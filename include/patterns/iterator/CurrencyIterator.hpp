#include "IIterator.hpp"

class CurrencyIterator : public IIterator<SharedPtr<Currency>> {
private:
    vector<SharedPtr<Currency>> currencies;
    size_t position;

public:
    explicit CurrencyIterator(const vector<SharedPtr<Currency>>& currs);

    bool hasNext() const override;
    SharedPtr<Currency> next() override;
    void reset() override;
};