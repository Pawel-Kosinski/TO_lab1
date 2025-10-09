#include "app/CurrencyExchangeApp.hpp"
#include "services/NBPService.hpp"
#include "patterns/iterator/CurrencyIterator.hpp"
#include "utils/Exceptions.hpp"
#include <iostream>
#include <limits>

namespace CurrencyApp {

CurrencyExchangeApp::CurrencyExchangeApp() {
    context = std::make_unique<AppContext>();
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

void CurrencyExchangeApp::displayAvailableCurrencies() {
    NBPService& nbp = NBPService::getInstance();

    std::cout << "\n======================================" << std::endl;
    std::cout << "   DOSTEPNE WALUTY" << std::endl;
    std::cout << "======================================" << std::endl;

    CurrencyIterator* iterator = nbp.getCurrencyIterator();

    int index = 1;
    while (iterator->hasNext()) {
        shared_ptr<Currency> curr = iterator->next();
        std::cout << index++ << ". " << curr->getCode() << " - "
            << curr->getName() << " (Kurs: "
            << doubleToString(curr->getRate(), 4) << " PLN)" << std::endl;
    }

    delete iterator;

    std::cout << "======================================" << std::endl;
}

void CurrencyExchangeApp::handleConversion() {
    InputValidator* validator = context->getValidator();

    std::cout << "\n--- KONWERSJA WALUTY ---" << std::endl;

    string amountStr;
    std::cout << "Podaj kwote: ";
    std::cin >> amountStr;

    if (!validator->validateAmount(amountStr)) {
        std::cerr << "Blad: Niepoprawna kwota!" << std::endl;
        return;
    }

    string fromCode;
    std::cout << "Waluta zrodlowa (np. USD): ";
    std::cin >> fromCode;
    fromCode = toUpperCase(trim(fromCode));

    if (!validator->validateCurrency(fromCode)) {
        std::cerr << "Blad: Niepoprawny kod waluty zrodlowej!" << std::endl;
        return;
    }

    string toCode;
    std::cout << "Waluta docelowa (np. EUR): ";
    std::cin >> toCode;
    toCode = toUpperCase(trim(toCode));

    if (!validator->validateCurrency(toCode)) {
        std::cerr << "Blad: Niepoprawny kod waluty docelowej!" << std::endl;
        return;
    }

    try {
        double amount = validator->parseAmount(amountStr);

        Money result = context->convertCurrency(amount, fromCode, toCode);

        std::cout << "\nKonwersja: " << doubleToString(amount, 2) << " " << fromCode
            << " = " << result.toString() << std::endl;

    }
    catch (const CurrencyException& e) {
        std::cerr << "Blad konwersji: " << e.what() << std::endl;
    }
}

void CurrencyExchangeApp::handleExit() {
    std::cout << "\nDziekujemy za skorzystanie z kalkulatora walut!" << std::endl;
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

            switch (choice) {
            case 1:
                handleConversion();
                break;
            case 2:
                displayAvailableCurrencies();
                break;
            case 3:
                handleExit();
                running = false;
                break;
            default:
                std::cerr << "Blad: Niepoprawny wybor!" << std::endl;
                break;
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