#include "app/menuAction/HandleConversion.hpp"
#include "utils/Types.hpp"

namespace CurrencyApp {
    HandleConversion::HandleConversion() {
        context = std::make_unique<AppContext>();
    }

	void HandleConversion::handleAction() {
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

            std::cout << "\n==================================" << std::endl;
            std::cout << "      WYNIK KONWERSJI" << std::endl;
            std::cout << "==================================" << std::endl;
            std::cout << "  " << doubleToString(amount, 2) << " " << fromCode
                << " = " << result.toString() << std::endl;
            std::cout << "==================================" << std::endl;

        }
        catch (const CurrencyException& e) {
            std::cerr << "\nBlad konwersji: " << e.what() << std::endl;
        }
	}
}