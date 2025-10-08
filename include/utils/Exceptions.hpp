#pragma once

#include "Types.hpp"
#include <exception>

namespace CurrencyApp {

    class CurrencyException : public std::exception {
    private:
        string message;

    public:
        explicit CurrencyException(const string& msg) : message(msg) {}

        const char* what() const noexcept override {
            return message.c_str();
        }

        const string& getMessage() const {
            return message;
        }

        virtual ~CurrencyException() = default;
    };

    class NetworkException : public CurrencyException {
    private:
        int httpCode;

    public:
        explicit NetworkException(const string& msg)
            : CurrencyException("Network Error: " + msg), httpCode(0) {}

        NetworkException(const string& msg, int code)
            : CurrencyException("Network Error (HTTP " + std::to_string(code) + "): " + msg),
            httpCode(code) {}

        int getHttpCode() const { return httpCode; }
    };

    class ParseException : public CurrencyException {
    private:
        string fieldName;

    public:
        explicit ParseException(const string& msg)
            : CurrencyException("Parse Error: " + msg), fieldName("") {}

        ParseException(const string& msg, const string& field)
            : CurrencyException("Parse Error in field '" + field + "': " + msg),
            fieldName(field) {}

        const string& getFieldName() const { return fieldName; }
    };

    class ValidationException : public CurrencyException {
    private:
        string inputValue;

    public:
        explicit ValidationException(const string& msg)
            : CurrencyException("Validation Error: " + msg), inputValue("") {}

        ValidationException(const string& msg, const string& value)
            : CurrencyException("Validation Error: " + msg + " (got: '" + value + "')"),
            inputValue(value) {}

        const string& getInputValue() const { return inputValue; }
    };

    class ConversionException : public CurrencyException {
    private:
        string fromCurrency;
        string toCurrency;

    public:
        explicit ConversionException(const string& msg)
            : CurrencyException("Conversion Error: " + msg),
            fromCurrency(""), toCurrency("") {}

        ConversionException(const string& msg, const string& from, const string& to)
            : CurrencyException("Conversion Error (" + from + " -> " + to + "): " + msg),
            fromCurrency(from), toCurrency(to) {}

        const string& getFromCurrency() const { return fromCurrency; }
        const string& getToCurrency() const { return toCurrency; }
    };

    class StateException : public CurrencyException {
    private:
        string currentState;

    public:
        explicit StateException(const string& msg)
            : CurrencyException("State Error: " + msg), currentState("") {}

        StateException(const string& msg, const string& state)
            : CurrencyException("State Error in '" + state + "': " + msg),
            currentState(state) {}

        const string& getCurrentState() const { return currentState; }
    };

} // namespace CurrencyApp