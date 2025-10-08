#pragma once

#include "IConversionStrategy.hpp"
#include "NBPService.hpp"

namespace CurrencyApp {

    class DirectConversionStrategy : public IConversionStrategy {
    private:
        NBPService& nbpService;

    public:
        explicit DirectConversionStrategy(NBPService& nbp);

        Money convert(const Money& from, shared_ptr<Currency> to) override;

    private:
        double calculateRate(shared_ptr<Currency> fromCurr, shared_ptr<Currency> toCurr);
    };

} // namespace CurrencyApp