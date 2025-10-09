#include "app/InputValidator.hpp"
#include "services/NBPService.hpp"
#include "utils/Exceptions.hpp"
#include <cctype>

namespace CurrencyApp {

bool InputValidator::validateAmount(const string& amount) const {
    if (amount.empty()) {
        return false;
    }

    try {
        double value = std::stod(amount);
        return value > 0;
    }
    catch (...) {
        return false;
    }
}

bool InputValidator::validateCurrency(const string& code) const {
    if (code.empty()) {
        return false;
    }

    NBPService& nbp = NBPService::getInstance();
    shared_ptr<Currency> currency = nbp.getRate(toUpperCase(code));

    return currency != nullptr;
}

string InputValidator::sanitizeInput(const string& input) const {
    return trim(input);
}

double InputValidator::parseAmount(const string& amount) const {
    try {
        return std::stod(amount);
    }
    catch (const std::exception& e) {
        throw ValidationException("Invalid amount format", amount);
    }
}

} // namespace CurrencyApp