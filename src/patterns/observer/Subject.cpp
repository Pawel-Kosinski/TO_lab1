#include "patterns/observer/Subject.hpp"
#include <algorithm>

namespace CurrencyApp {

    void Subject::attach(IObserver* observer) {
        if (observer == nullptr) {
            return;
        }

        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it == observers.end()) {
            observers.push_back(observer);
        }
    }

    void Subject::detach(IObserver* observer) {
        if (observer == nullptr) {
            return;
        }

        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    void Subject::notify(const Money& data) {
        for (IObserver* observer : observers) {
            if (observer != nullptr) {
                observer->update(data);
            }
        }
    }

} // namespace CurrencyApp