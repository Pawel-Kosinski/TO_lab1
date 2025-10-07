#pragma once

#include "IObserver.hpp"

namespace CurrencyApp {

    class UIObserver : public IObserver {
    public:
        UIObserver() = default;
        ~UIObserver() override = default;

        void update(const Money& data) override;
    };

} // namespace CurrencyApp