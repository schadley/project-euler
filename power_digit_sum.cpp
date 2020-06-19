#include <iostream>
#include <vector>

/*
 * Problem 16
 * Calculate the sum of the digits of 2^N
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: power_digit_sum <power>";
        return 1;
    }
    int power = atoi(argv[1]);

    std::vector<int> num = {1};
    for (int i = 0; i < power; i++) {
        bool carry = false;
        for (int &j : num) {
            j *= 2;
            if (carry) j++;
            carry = j >= 10;
            if (carry) j -= 10;
        }
        if (carry) num.push_back(1);
    }

    int sum = 0;
    for (auto it = num.rbegin(); it != num.rend(); it++) {
        sum += *it;
        std::cout << *it;
    }
    std::cout << std::endl << "Sum = " << sum << std::endl;
}
