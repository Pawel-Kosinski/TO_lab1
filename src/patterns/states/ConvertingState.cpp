#include "patterns/states/ConvertingState.hpp"
#include "patterns/states/ReadyState.hpp"
#include "app/AppContext.hpp"

namespace CurrencyApp {

void ConvertingState::handle(AppContext* context) {
    std::cout << "Wykonywanie konwersji..." << std::endl;

    context->setState(new ReadyState());
}

string ConvertingState::getStateName() const {
    return "ConvertingState";
}

} // namespace CurrencyApp