#include "patterns/states/ReadyState.hpp"

namespace CurrencyApp {

void ReadyState::handle(AppContext* context) {
    std::cout << "Aplikacja gotowa do konwersji!" << std::endl;
}

string ReadyState::getStateName() const {
    return "ReadyState";
}

} // namespace CurrencyApp