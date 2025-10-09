#include "services/CurrencyConverter.hpp"
#include "patterns/strategies/ThroughPLNConversionStrategy.hpp"
#include "services/NBPService.hpp"
#include "utils/Exceptions.hpp"

namespace CurrencyApp {

CurrencyConverter::CurrencyConverter() {
    NBPService& nbp = NBPService::getInstance();
    strategy = std::make_unique<ThroughPLNConversionStrategy>(nbp);
}

Money CurrencyConverter::convert(const Money& from, SharedPtr<Currency> to) {
    if (strategy == nullptr) {
        throw StateException("Conversion strategy is not set");
    }

    Money result = strategy->convert(from, to);

    notify(result);

    return result;
}

void CurrencyConverter::setStrategy(UniquePtr<IConversionStrategy> newStrategy) {
    if (newStrategy == nullptr) {
        throw ValidationException("Strategy cannot be null");
    }

    strategy = std::move(newStrategy);
}

} // namespace CurrencyApp