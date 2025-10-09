#pragma once

#include "utils/Types.hpp"

namespace CurrencyApp {

    class AppContext;

    class IApplicationState {
    public:
        virtual ~IApplicationState() = default;

        virtual void handle(AppContext* context) = 0;
        virtual string getStateName() const = 0;
    };

} // namespace CurrencyApp