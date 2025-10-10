#include "app/CurrencyExchangeApp.hpp"

#include "menuAction/DisplayCurrenciesAction.cpp"
#include "menuAction/ExitAction.cpp"
#include "menuAction/ConversionAction.cpp"
#include "utils/Types.hpp"
#include "app/AppContext.hpp"


namespace CurrencyApp {

using std::make_unique;

CurrencyExchangeApp::CurrencyExchangeApp() {
    context = make_unique<AppContext>();
}

void CurrencyExchangeApp::displayMenu() {
    std::cout << "\n" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "   KALKULATOR WALUT - MENU GLOWNE" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "1. Przelicz walute" << std::endl;
    std::cout << "2. Pokaz dostepne waluty" << std::endl;
    std::cout << "3. Wyjscie" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Wybierz opcje: ";
}

void CurrencyExchangeApp::run() {
    try {
        context->initialize();

        bool running = true;

        while (running) {
            displayMenu();

            int choice;
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Blad: Niepoprawny wybor!" << std::endl;
                continue;
            }

            unique_ptr<IMenuAction> action;

            switch (choice) {
            case 1:
                action = make_unique<ConversionAction>(context.get());
                break;
            case 2:
                action = make_unique<DisplayCurrenciesAction>();
                break;
            case 3:
                action = make_unique<ExitAction>();
                break;
            default:
                std::cerr << "Blad: Niepoprawny wybor!" << std::endl;
                continue;
            }

            if (action) {
                action->execute();
                if (action->shouldExit()) {
                    running = false;
                }
            }
        }

    }
    catch (const CurrencyException& e) {
        std::cerr << "Blad krytyczny: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Nieoczekiwany blad: " << e.what() << std::endl;
    }
}

} // namespace CurrencyApp