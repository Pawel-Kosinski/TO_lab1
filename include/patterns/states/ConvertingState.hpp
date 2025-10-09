#pragma once

#include "IApplicationState.hpp"

namespace CurrencyApp {

class ConvertingState : public IApplicationState {
public:
    void handle(AppContext* context) override;
    string getStateName() const override;
};

} // namespace CurrencyApp