#pragma once

#include "IMenuAction.hpp"

namespace CurrencyApp {

class AppContext;

class ConversionAction : public IMenuAction {
private:
    AppContext* context;

public:
    explicit ConversionAction(AppContext* ctx);
    void execute() override;
};

} // namespace CurrencyApp