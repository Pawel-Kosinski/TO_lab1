#include "app/menuAction/ExitAction.hpp"
#include <iostream>

namespace CurrencyApp {

void ExitAction::execute() {
    std::cout << "\nDziekujemy za skorzystanie z kalkulatora walut!" << std::endl;
}

} // namespace CurrencyApp