#pragma once
#include "Types.hpp"

namespace CurrencyApp {

class HTTPClient {
private:
    HTTPClient();

    HTTPClient(const HTTPClient&) = delete;
    HTTPClient& operator=(const HTTPClient&) = delete;

    int timeout;
    string executeCurl(const string& url);

public:
    ~HTTPClient();

    static HTTPClient& getInstance();

    string get(const string& url);

    void setTimeout(int seconds);
    int getTimeout() const;
};
} // namespace CurrencyApp