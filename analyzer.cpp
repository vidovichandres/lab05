// Andres Vidovich 10/7/2024
// This is the fixed version!
#include <iostream>
#include <vector>
#include <string>
#include "StringData.h"

int linear_search(std::vector<std::string>& container, std::string element)
{
    for(int i = 0; i < container.size(); i++) {
        if (container[i] == element) {
            return i;
        }
    }
    return -1;
}


int binary_search(std::vector<std::string>& container, std::string element) {
    // Algorithm adapted from textbook
    long low {0};
    long high {static_cast<long>(container.size()) - 1};

    while(high >= low) {
        long mid {(high + low) / 2};
        if (container[mid].compare(element) < 0) {
            low = mid + 1;
        } else if (container[mid].compare(element) > 0) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main()
{
    std::vector<std::string> data = getStringData();
    const auto t1 = std::chrono::high_resolution_clock::now();
    linear_search(data, "not_here");
    const auto t2 = std::chrono::system_clock::now();
    binary_search(data, "not_here");

    const auto t3 = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> d1 = t2 - t1;
    const std::chrono::duration<double> d2 = t3 - t2;

    std::cout << "element: \"not_here\"\nLinear: " << d1.count() << "\nBinary: " << d2.count() << std::endl;

    linear_search(data, "mzzzz");
    const auto t4 = std::chrono::high_resolution_clock::now();
    binary_search(data, "mzzzz");

    const auto t5 = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> d3 = t4 - t3;
    const std::chrono::duration<double> d4 = t5 - t4;

    std::cout << "element: \"mzzzz\"\nLinear: " << d3.count() << "\nBinary: " << d4.count() << std::endl;

    linear_search(data, "aaaaa");
    const auto t6 = std::chrono::high_resolution_clock::now();
    binary_search(data, "aaaaa");

    const auto t7 = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> d5 = t6 - t5;
    const std::chrono::duration<double> d6 = t7 - t6;

    std::cout << "element: \"aaaaa\"\nLinear: " << d5.count() << "\nBinary: " << d6.count() << std::endl;

    return 0;
}
