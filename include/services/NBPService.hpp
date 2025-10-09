#pragma once

#include "XMLParser.hpp"
#include "model/Currency.hpp"
#include "patterns/iterator/CurrencyIterator.hpp"
#include "utils/Types.hpp"
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

        static const string NBP_URL;

    public:
        ~NBPService() = default;

        static NBPService& getInstance();

        void fetchExchangeRates();
        shared_ptr<Currency> getRate(const string& code);
        CurrencyIterator* getCurrencyIterator();
        size_t getCurrencyCount() const;
        const string& getLastUpdate() const;
    };

} // namespace CurrencyApp