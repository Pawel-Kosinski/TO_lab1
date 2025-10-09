#pragma once

#include "IApplicationState.hpp"

namespace CurrencyApp {

class ErrorState : public IApplicationState {
private:
    string errorMessage;

public:
    explicit ErrorState(const string& msg);

    void handle(AppContext* context) override;
    string getStateName() const override;
    const string& getErrorMessage() const;
};

} // namespace CurrencyApp