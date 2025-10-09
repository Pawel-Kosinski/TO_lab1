#pragma once

#include "model/Money.hpp"
#include "utils/Types.hpp"

namespace CurrencyApp {

    class IConversionStrategy {
    public:
        virtual ~IConversionStrategy() = default;

        virtual Money convert(const Money& from, shared_ptr<Currency> to) = 0;
    };

} // namespace CurrencyApp