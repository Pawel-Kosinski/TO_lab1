#pragma once

#include "app/menuAction/IMenuAction.hpp"

namespace CurrencyApp {

class ExitAction : public IMenuAction {
public:
    ExitAction() = default;
    void execute() override;
    bool shouldExit() const override { return true; }
};

} // namespace CurrencyApp