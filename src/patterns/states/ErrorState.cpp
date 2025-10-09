#include "patterns/states/ErrorState.hpp"

namespace CurrencyApp {

ErrorState::ErrorState(const string& msg) : errorMessage(msg) {}

void ErrorState::handle(AppContext* context) {
    std::cerr << "Stan bledu: " << errorMessage << std::endl;
}

string ErrorState::getStateName() const {
    return "ErrorState";
}

const string& ErrorState::getErrorMessage() const {
    return errorMessage;
}

} // namespace CurrencyApp