#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

namespace CurrencyApp {

//using String = std::string;
//template<typename T>
//using List = std::vector<T>;
template<typename K, typename V>
using Map = std::map<K, V>;
//template<typename T>
//using SharedPtr = std::shared_ptr<T>;
//template<typename T>
//using UniquePtr = std::unique_ptr<T>;

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