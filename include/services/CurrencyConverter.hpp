#pragma once

#include "patterns/strategies/IConversionStrategy.hpp"
#include "model/Money.hpp"
#include "utils/Types.hpp"

namespace CurrencyApp {

class CurrencyConverter {
private:
    unique_ptr<IConversionStrategy> strategy;

public:
    CurrencyConverter();
    ~CurrencyConverter() = default;

    Money convert(const Money& from, shared_ptr<Currency> to);
    void setStrategy(unique_ptr<IConversionStrategy> newStrategy);
};

} // namespace CurrencyApp