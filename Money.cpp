#include "Money.hpp"
#include "Exceptions.hpp"

namespace CurrencyApp {

Money::Money(double amount, shared_ptr<Currency> currency)
    : amount(amount), currency(currency) {

    if (currency == nullptr) {
        throw ValidationException("Currency cannot be null");
    }

    if (amount < 0) {
        throw ValidationException("Amount cannot be negative", doubleToString(amount));
    }
}

double Money::getAmount() const {
    return amount;
}

shared_ptr<Currency> Money::getCurrency() const {
    return currency;
}

const Currency& Money::getCurrencyRef() const {
    return *currency;
}

string Money::toString() const {
    return doubleToString(amount, 2) + " " + currency->getCode();
}

} // namespace CurrencyApp