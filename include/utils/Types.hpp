#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>

namespace CurrencyApp {
    using std::string;
    using std::shared_ptr;
    using std::unique_ptr;
    using std::vector;
    using std::cout;
    using std::endl;
    using std::map;

inline string doubleToString(double value, int precision = 2) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision) << value;
    return out.str();
}

inline string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

inline string toUpperCase(string str) {
    std::transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) { return std::toupper(c); });
    return str;
}

inline string toLowerCase(string str) {
    std::transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return str;
}
} // namespace CurrencyApp