#pragma once

#include "IConversionStrategy.hpp"
#include "NBPService.hpp"

namespace CurrencyApp {

    class ThroughPLNConversionStrategy : public IConversionStrategy {
    private:
        NBPService& nbpService;

    public:
        explicit ThroughPLNConversionStrategy(NBPService& nbp);

        Money convert(const Money& from, shared_ptr<Currency> to) override;

    private:
        Money convertToPLN(const Money& money);
        Money convertFromPLN(const Money& moneyInPLN, shared_ptr<Currency> to);
    };

} // namespace CurrencyApp