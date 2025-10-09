#include "patterns/states/InitialState.hpp"
#include "patterns/states/LoadingState.hpp"
#include <iostream>

namespace CurrencyApp {

void InitialState::handle(AppContext* context) {
    std::cout << "Inicjalizacja aplikacji..." << std::endl;

    context->setState(new LoadingState());
}

string InitialState::getStateName() const {
    return "InitialState";
}

} // namespace CurrencyApp