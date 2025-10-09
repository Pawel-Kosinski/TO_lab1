#pragma once

#include "IObserver.hpp"
#include "utils/Types.hpp"

namespace CurrencyApp {

    class Subject {
    private:
        vector<IObserver*> observers;

    public:
        virtual ~Subject() = default;

        void attach(IObserver* observer);
        void detach(IObserver* observer);
        void notify(const Money& data);
    };

} // namespace CurrencyApp