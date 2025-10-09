#pragma once

#include "InputValidator.hpp"
#include <services/CurrencyConventer.hpp>
#include "patterns/states/IApplicationState.hpp"
#include "utils/Types.hpp"

namespace CurrencyApp {

    class AppContext {
    private:
        unique_ptr<CurrencyConverter> converter;
        unique_ptr<InputValidator> validator;
        IApplicationState* currentState;

    public:
        AppContext();
        ~AppContext();

        void initialize();
        Money convertCurrency(double amount, const string& fromCode, const string& toCode);

        void setState(IApplicationState* state);
        IApplicationState* getState() const;

        CurrencyConverter* getConverter();
        InputValidator* getValidator();
    };

} // namespace CurrencyApp