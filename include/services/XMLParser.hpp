#pragma once

#include "model/Currency.hpp"
#include "utils/Types.hpp"

namespace CurrencyApp {

class XMLParser {
public:
    XMLParser() = default;
    ~XMLParser() = default;

    vector<shared_ptr<Currency>> parse(const string& xml);

private:
    string extractTextBetweenTags(const string& xml, const string& tagName, size_t startPos);
    size_t findNextTag(const string& xml, const string& tagName, size_t startPos);
};

} // namespace CurrencyApp