#include "services/NBPService.hpp"
#include "utils/Exceptions.hpp"

namespace CurrencyApp {

    const string NBPService::NBP_URL = "https://static.nbp.pl/dane/kursy/xml/LastA.xml";

    NBPService::NBPService()
        : httpClient(HTTPClient::getInstance()),
        xmlParser(std::make_unique<XMLParser>()),
        lastUpdate("") {}

    NBPService& NBPService::getInstance() {
        static NBPService instance;
        return instance;
    }

    void NBPService::fetchExchangeRates() {
        try {
            std::cout << "Pobieranie kursow walut z NBP..." << std::endl;

            string xml = httpClient.get(NBP_URL);

            if (xml.empty()) {
                throw NetworkException("Otrzymano pusty XML z NBP");
            }

            vector<shared_ptr<Currency>> currencies = xmlParser->parse(xml);

            exchangeRates.clear();

            for (const auto& currency : currencies) {
                exchangeRates[currency->getCode()] = currency;
            }

            shared_ptr<Currency> pln = std::make_shared<Currency>("PLN", "Polski zloty", 1.0, 1);
            exchangeRates["PLN"] = pln;

            lastUpdate = "success";

            std::cout << "Pobrano " << currencies.size() << " kursow walut" << std::endl;

        }
        catch (const NetworkException& e) {
            throw;
        }
        catch (const ParseException& e) {
            throw;
        }
        catch (const std::exception& e) {
            throw NetworkException(string("Blad podczas pobierania kursow: ") + e.what());
        }
    }

    shared_ptr<Currency> NBPService::getRate(const string& code) {
        string upperCode = toUpperCase(code);

        auto it = exchangeRates.find(upperCode);
        if (it != exchangeRates.end()) {
            return it->second;
        }

        return nullptr;
    }

    CurrencyIterator* NBPService::getCurrencyIterator() {
        vector<shared_ptr<Currency>> currList;

        for (const auto& pair : exchangeRates) {
            currList.push_back(pair.second);
        }

        return new CurrencyIterator(currList);
    }

    size_t NBPService::getCurrencyCount() const {
        return exchangeRates.size();
    }

    const string& NBPService::getLastUpdate() const {
        return lastUpdate;
    }

} // namespace CurrencyApp