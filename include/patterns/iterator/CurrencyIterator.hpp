#pragma once

#include "IIterator.h"
#include "model/Currency.h"
#include "utils/Types.h"

namespace CurrencyApp {

    class CurrencyIterator : public IIterator<SharedPtr<Currency>> {
    private:
        List<SharedPtr<Currency>> currencies;
        size_t position;

    public:
        explicit CurrencyIterator(const List<SharedPtr<Currency>>& currs);

        bool hasNext() const override;
        SharedPtr<Currency> next() override;
        void reset() override;
    };

} // namespace CurrencyApp