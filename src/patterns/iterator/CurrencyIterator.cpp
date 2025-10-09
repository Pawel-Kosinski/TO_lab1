#include "patterns/iterator/CurrencyIterator.hpp"
#include "utils/Exceptions.hpp"

namespace CurrencyApp {

CurrencyIterator::CurrencyIterator(const vector<shared_ptr<Currency>>& currs)
    : currencies(currs), position(0) {}

bool CurrencyIterator::hasNext() const {
    return position < currencies.size();
}

shared_ptr<Currency> CurrencyIterator::next() {
    if (!hasNext()) {
        throw StateException("No more elements in iterator");
    }
    return currencies[position++];
}

void CurrencyIterator::reset() {
    position = 0;
    }

} // namespace CurrencyApp