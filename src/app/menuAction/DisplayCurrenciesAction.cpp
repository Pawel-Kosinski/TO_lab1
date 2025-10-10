#include "app/menuAction/DisplayCurrenciesAction.hpp"
#include "services/NBPService.hpp"
#include "patterns/iterator/CurrencyIterator.hpp"

namespace CurrencyApp {

DisplayCurrenciesAction::DisplayCurrenciesAction() = default;

void DisplayCurrenciesAction::execute() {
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

} // namespace CurrencyApp