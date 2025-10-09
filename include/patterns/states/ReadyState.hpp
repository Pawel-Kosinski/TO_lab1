#pragma once

#include "IApplicationState.hpp"

namespace CurrencyApp {

class ReadyState : public IApplicationState {
public:
    void handle(AppContext* context) override;
    string getStateName() const override;
};

} // namespace CurrencyApp