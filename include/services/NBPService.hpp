#pragma once
#include "XMLParser.hpp"
#include "Currency.hpp"
#include "CurrencyIterator.hpp"
#include "HTTPCllient.hpp"

namespace CurrencyApp {
class NBPService {
private:
    NBPService();
    NBPService(const NBPService&) = delete;
    NBPService& operator=(const NBPService&) = delete;

    HTTPClient& httpClient;
    unique_ptr<XMLParser> xmlParser;
    Map<string, shared_ptr<Currency>> exchangeRates;
    string lastUpdate;

public:
    ~NBPService() = default;

    static NBPService& getInstance();

    void fetchExchangeRates();
    shared_ptr<Currency> getRate(const string& code);
    CurrencyIterator* getCurrencyIterator();
    size_t getCurrencyCount() const;
};
} // namespace CurrencyApp