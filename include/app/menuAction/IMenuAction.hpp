#pragma once

namespace CurrencyApp {

class IMenuAction {
public:
    virtual ~IMenuAction() = default;
    virtual void execute() = 0;
    virtual bool shouldExit() const { return false; }
};

} // namespace CurrencyApp