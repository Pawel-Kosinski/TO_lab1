#include "app/AppContext.hpp"
#include "patterns/states/InitialState.hpp"
#include "patterns/observer/UIObserver.hpp"
#include "services/NBPService.hpp"
#include "utils/Exceptions.hpp"

namespace CurrencyApp {

AppContext::AppContext() : currentState(nullptr) {
    converter = std::make_unique<CurrencyConverter>();
    validator = std::make_unique<InputValidator>();

    UIObserver* uiObserver = new UIObserver();
    converter->attach(uiObserver);
}

AppContext::~AppContext() {
    if (currentState != nullptr) {
        delete currentState;
    }
}

void AppContext::initialize() {
    currentState = new InitialState();
    currentState->handle(this);

    if (currentState != nullptr) {
        currentState->handle(this);
    }
}

Money AppContext::convertCurrency(double amount, const string& fromCode, const string& toCode) {
    NBPService& nbp = NBPService::getInstance();

    shared_ptr<Currency> fromCurrency = nbp.getRate(toUpperCase(fromCode));
    if (fromCurrency == nullptr) {
        throw ValidationException("Currency not found", fromCode);
    }

    shared_ptr<Currency> toCurrency = nbp.getRate(toUpperCase(toCode));
    if (toCurrency == nullptr) {
        throw ValidationException("Currency not found", toCode);
    }

    Money fromMoney(amount, fromCurrency);

    return converter->convert(fromMoney, toCurrency);
}

void AppContext::setState(IApplicationState* state) {
    if (currentState != nullptr) {
        delete currentState;
    }
    currentState = state;
}

IApplicationState* AppContext::getState() const {
    return currentState;
}

CurrencyConverter* AppContext::getConverter() {
    return converter.get();
}

InputValidator* AppContext::getValidator() {
    return validator.get();
}

} // namespace CurrencyApp