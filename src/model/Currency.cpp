#include "Currency.hpp"
#include "Exceptions.hpp"

namespace CurrencyApp {

    Currency::Currency(const string& code, const string& name, double rate, int multiplier)
        : code(code), name(name), rate(rate), multiplier(multiplier) {

        if (code.empty()) {
            throw ValidationException("Currency code cannot be empty");
        }

        if (rate < 0) {
            throw ValidationException("Currency rate cannot be negative", doubleToString(rate));
        }

        if (multiplier <= 0) {
            throw ValidationException("Currency multiplier must be positive", std::to_string(multiplier));
        }
    }

    const string& Currency::getCode() const {
        return code;
    }

    const string& Currency::getName() const {
        return name;
    }

    double Currency::getRate() const {
        return rate;
    }

    int Currency::getMultiplier() const {
        return multiplier;
    }

    void Currency::setRate(double rate) {
        if (rate < 0) {
            throw ValidationException("Currency rate cannot be negative", doubleToString(rate));
        }
        this->rate = rate;
    }

    void Currency::setMultiplier(int multiplier) {
        if (multiplier <= 0) {
            throw ValidationException("Currency multiplier must be positive", std::to_string(multiplier));
        }
        this->multiplier = multiplier;
    }

    string Currency::toString() const {
        return code + " - " + name + " (Rate: " + doubleToString(rate, 4) +
            " PLN, Multiplier: " + std::to_string(multiplier) + ")";
    }

} // namespace CurrencyApp