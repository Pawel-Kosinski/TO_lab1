#pragma once
#include "utils/Types.hpp"

namespace CurrencyApp {

    class AppContext;
class CurrencyExchangeApp {
private:
    unique_ptr<AppContext> context;

    void displayMenu();

public:
    CurrencyExchangeApp();
    ~CurrencyExchangeApp() = default;

    void run();
};

} // namespace CurrencyApp