#pragma once

#include "IIterator.hpp"
#include "model/Currency.hpp"
#include "utils/Types.hpp"

namespace CurrencyApp {

class CurrencyIterator : public IIterator<shared_ptr<Currency>> {
private:
    vector<shared_ptr<Currency>> currencies;
    size_t position;

public:
    explicit CurrencyIterator(const vector<shared_ptr<Currency>>& currs);

    bool hasNext() const override;
    shared_ptr<Currency> next() override;
    void reset() override;
};

} // namespace CurrencyApp