#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    std::deque<int> D;
    int numElements;
    std::cout << "Enter the number of elements (should be even): ";
    std::cin >> numElements;

    std::cout << "Enter the elements of the deque: ";
    for (int i = 0; i < numElements; ++i) {
        int num;
        std::cin >> num;
        D.push_back(num);
    }

    std::deque<int> D0(D.begin(), D.begin() + D.size() / 2);

    std::replace_if(D0.begin(), D0.end(), [](int num) { return num < 0; }, 0);

    std::copy(D0.rbegin(), D0.rend(), std::back_inserter(D));

    std::cout << "Modified deque: ";
    for (const auto& num : D) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}