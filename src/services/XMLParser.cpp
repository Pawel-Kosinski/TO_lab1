#include "services/XMLParser.hpp"
#include "utils/Exceptions.hpp"
#include <sstream>

namespace CurrencyApp {

    string XMLParser::extractTextBetweenTags(const string& xml, const string& tagName, size_t startPos) {
        string openTag = "<" + tagName + ">";
        string closeTag = "</" + tagName + ">";

        size_t start = xml.find(openTag, startPos);
        if (start == string::npos) {
            return "";
        }

        start += openTag.length();
        size_t end = xml.find(closeTag, start);

        if (end == string::npos) {
            throw ParseException("Closing tag not found", tagName);
        }

        return trim(xml.substr(start, end - start));
    }

    size_t XMLParser::findNextTag(const string& xml, const string& tagName, size_t startPos) {
        string tag = "<" + tagName + ">";
        return xml.find(tag, startPos);
    }

    vector<shared_ptr<Currency>> XMLParser::parse(const string& xml) {
        vector<shared_ptr<Currency>> currencies;

        if (xml.empty()) {
            throw ParseException("XML content is empty");
        }

        size_t pos = 0;

        while (true) {
            pos = findNextTag(xml, "pozycja", pos);

            if (pos == string::npos) {
                break;
            }

            try {
                string code = extractTextBetweenTags(xml, "kod_waluty", pos);
                string name = extractTextBetweenTags(xml, "nazwa_waluty", pos);
                string rateStr = extractTextBetweenTags(xml, "kurs_sredni", pos);
                string multStr = extractTextBetweenTags(xml, "przelicznik", pos);

                if (code.empty() || name.empty() || rateStr.empty() || multStr.empty()) {
                    pos++;
                    continue;
                }

                for (char& c : rateStr) {
                    if (c == ',') {
                        c = '.';
                    }
                }

                double rate = std::stod(rateStr);
                int multiplier = std::stoi(multStr);

                shared_ptr<Currency> currency = std::make_shared<Currency>(code, name, rate, multiplier);
                currencies.push_back(currency);

            }
            catch (const std::invalid_argument& e) {
                throw ParseException("Invalid number format in currency data");
            }
            catch (const std::out_of_range& e) {
                throw ParseException("Number out of range in currency data");
            }

            pos++;
        }

        if (currencies.empty()) {
            throw ParseException("No valid currency entries found in XML");
        }

        return currencies;
    }

} // namespace CurrencyApp