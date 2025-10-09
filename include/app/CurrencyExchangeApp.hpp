#pragma once

#include "AppContext.hpp"
#include "utils/Types.hpp"

namespace CurrencyApp {

class CurrencyExchangeApp {
private:
    unique_ptr<AppContext> context;

    void displayMenu();
    void displayAvailableCurrencies();
    void handleConversion();
    void handleExit();

public:
    CurrencyExchangeApp();
    ~CurrencyExchangeApp() = default;

    void run();
};

} // namespace CurrencyApp