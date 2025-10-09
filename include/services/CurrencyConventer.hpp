#pragma once

#include "patterns/observer/Subject.hpp"
#include "patterns/strategies/IConversionStrategy.hpp"
#include "model/Money.hpp"
#include "utils/Types.hpp"

namespace CurrencyApp {

class CurrencyConverter : public Subject {
private:
    unique_ptr<IConversionStrategy> strategy;

public:
    CurrencyConverter();
    ~CurrencyConverter() = default;

    Money convert(const Money& from, SharedPtr<Currency> to);
    void setStrategy(unique_ptr<IConversionStrategy> newStrategy);
};

} // namespace CurrencyApp