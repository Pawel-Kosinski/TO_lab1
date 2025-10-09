#include "utils/Exceptions.hpp"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "services/HTTPClient.hpp"

namespace CurrencyApp {

    HTTPClient::HTTPClient() : timeout(30) {}

    HTTPClient::~HTTPClient() {}

    HTTPClient& HTTPClient::getInstance() {
        static HTTPClient instance;
        return instance;
    }

    string HTTPClient::executeCurl(const string& url) {
        string tempFile = "temp_curl_output.txt";
        string command = "curl -s -L --max-time " + std::to_string(timeout) +
            " \"" + url + "\" > " + tempFile + " 2>&1";

        int result = system(command.c_str());

        if (result != 0) {
            throw NetworkException("Failed to execute curl command");
        }

        std::ifstream file(tempFile);
        if (!file.is_open()) {
            throw NetworkException("Failed to read curl output");
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        string response = buffer.str();

        file.close();

        std::remove(tempFile.c_str());

        if (response.empty()) {
            throw NetworkException("Empty response from server");
        }

        if (response.find("curl:") != string::npos) {
            throw NetworkException("CURL error: " + response);
        }

        return response;
    }

    string HTTPClient::get(const string& url) {
        if (url.empty()) {
            throw ValidationException("URL cannot be empty");
        }

        try {
            return executeCurl(url);
        }
        catch (const CurrencyException& e) {
            throw;
        }
        catch (const std::exception& e) {
            throw NetworkException(string("HTTP GET failed: ") + e.what());
        }
    }

    void HTTPClient::setTimeout(int seconds) {
        if (seconds <= 0) {
            throw ValidationException("Timeout must be positive", std::to_string(seconds));
        }
        this->timeout = seconds;
    }

    int HTTPClient::getTimeout() const {
        return timeout;
    }

} // namespace CurrencyApp