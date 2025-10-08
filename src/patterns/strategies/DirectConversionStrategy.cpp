#include "DirectConversionStrategy.hpp"
#include "Exceptions.hpp"

namespace CurrencyApp {

    DirectConversionStrategy::DirectConversionStrategy(NBPService& nbp)
        : nbpService(nbp) {}

    double DirectConversionStrategy::calculateRate(shared_ptr<Currency> fromCurr, shared_ptr<Currency> toCurr) {
        double fromRate = fromCurr->getRate();
        double toRate = toCurr->getRate();

        return fromRate / toRate;
    }

    Money DirectConversionStrategy::convert(const Money& from, shared_ptr<Currency> to) {
        shared_ptr<Currency> fromCurrency = from.getCurrency();

        if (fromCurrency == nullptr) {
            throw ConversionException("Source currency is null");
        }

        if (to == nullptr) {
            throw ConversionException("Target currency is null");
        }

        if (fromCurrency->getCode() == to->getCode()) {
            return Money(from.getAmount(), to);
        }

        double rate = calculateRate(fromCurrency, to);
        double resultAmount = from.getAmount() * rate;

        return Money(resultAmount, to);
    }

} // namespace CurrencyApp