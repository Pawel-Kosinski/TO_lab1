#include "UIObserver.hpp"
#include <iostream>

namespace CurrencyApp {

    void UIObserver::update(const Money& data) {
        std::cout << "\n==================================" << std::endl;
        std::cout << "  WYNIK KONWERSJI" << std::endl;
        std::cout << "==================================" << std::endl;
        std::cout << "  " << data.toString() << std::endl;
        std::cout << "==================================" << std::endl;
        std::cout << std::endl;
    }

} // namespace CurrencyApp