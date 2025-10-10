#pragma once
#include "utils/Types.hpp"
#include "app/menuAction/IMenuAction.hpp" 

namespace CurrencyApp {

    class AppContext;
class CurrencyExchangeApp {
private:
    unique_ptr<AppContext> context;

    void displayMenu();

public:
    CurrencyExchangeApp();
    ~CurrencyExchangeApp();

    void run();
};

} // namespace CurrencyApp