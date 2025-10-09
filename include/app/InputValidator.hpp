#pragma once

#include "utils/Types.hpp"

namespace CurrencyApp {

class InputValidator {
public:
    InputValidator() = default;
    ~InputValidator() = default;

    bool validateAmount(const string& amount) const;
    bool validateCurrency(const string& code) const;
    string sanitizeInput(const string& input) const;
    double parseAmount(const string& amount) const;
};

} // namespace CurrencyApp