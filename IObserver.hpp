#pragma once

#include "Money.hpp"

namespace CurrencyApp {

    class IObserver {
    public:
        virtual ~IObserver() = default;

        virtual void update(const Money& data) = 0;
    };

} // namespace CurrencyApp