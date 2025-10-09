#include "patterns/states/LoadingState.hpp"
#include "patterns/states/ReadyState.hpp"
#include "patterns/states/ErrorState.hpp"
#include "services/NBPService.hpp"
#include "app/AppContext.hpp"
#include <utils/Exceptions.hpp>

namespace CurrencyApp {

void LoadingState::handle(AppContext* context) 
{
    std::cout << "Pobieranie kursow walut z NBP..." << std::endl;

    try {
        NBPService& nbp = NBPService::getInstance();
        nbp.fetchExchangeRates();

        std::cout << "Kursy pobrane pomyslnie!" << std::endl;
        context->setState(new ReadyState());

    }
    catch (const CurrencyException& e) {
        std::cerr << "Blad: " << e.what() << std::endl;
        context->setState(new ErrorState(e.getMessage()));
    }
}

string LoadingState::getStateName() const 
{
    return "LoadingState";
}

} // namespace CurrencyApp