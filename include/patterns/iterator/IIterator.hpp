#pragma once

namespace CurrencyApp {

template<typename T>
class IIterator {
public:
    virtual ~IIterator() = default;

    virtual bool hasNext() const = 0;
    virtual T next() = 0;
    virtual void reset() = 0;
};

} // namespace CurrencyApp