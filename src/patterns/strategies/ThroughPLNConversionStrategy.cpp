#include "patterns/strategies/ThroughPLNConversionStrategy.hpp"
#include "utils/Exceptions.hpp"

namespace CurrencyApp {

ThroughPLNConversionStrategy::ThroughPLNConversionStrategy(NBPService& nbp)
    : nbpService(nbp) {}

Money ThroughPLNConversionStrategy::convertToPLN(const Money& money) {
    shared_ptr<Currency> fromCurrency = money.getCurrency();

    if (fromCurrency->getCode() == "PLN") {
        return money;
    }

    double rate = fromCurrency->getRate();
    int multiplier = fromCurrency->getMultiplier();

    double amountInPLN = (money.getAmount() * rate) / multiplier;

    shared_ptr<Currency> pln = nbpService.getRate("PLN");
    if (pln == nullptr) {
        throw ConversionException("PLN currency not found in NBPService");
    }

    return Money(amountInPLN, pln);
}

Money ThroughPLNConversionStrategy::convertFromPLN(const Money& moneyInPLN, shared_ptr<Currency> to) {
    if (to->getCode() == "PLN") {
        return moneyInPLN;
    }

    double toRate = to->getRate();
    int toMultiplier = to->getMultiplier();

    double resultAmount = (moneyInPLN.getAmount() * toMultiplier) / toRate;

    return Money(resultAmount, to);
}

Money ThroughPLNConversionStrategy::convert(const Money& from, shared_ptr<Currency> to) {
    if (from.getCurrency() == nullptr) {
        throw ConversionException("Source currency is null");
    }

    if (to == nullptr) {
        throw ConversionException("Target currency is null");
    }

    if (from.getCurrency()->getCode() == to->getCode()) {
        return Money(from.getAmount(), to);
    }

    Money moneyInPLN = convertToPLN(from);
    Money result = convertFromPLN(moneyInPLN, to);

    return result;
}

} // namespace CurrencyApp