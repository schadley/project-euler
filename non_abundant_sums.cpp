#include <iostream>
#include <vector>
#include <unordered_set>

// The sum of all the positive integers which
// cannot be written as the sum of two abundant numbers
int main() {
    // Find the sum of divisors for each number
    // Check up to 20000 since a number < 10000 could be amicable with a number > 10000
    std::vector<int> sums(28124);
    for (int i = 1; i < 28124; i++) {
        // Find all proper multiples of each number
        for (int j = 2 * i; j < 28124; j += i) {
            sums[j] += i;
        }
    }

    // Set of abundant numbers <= 28123
    std::unordered_set<int> abundant;
    for (int i = 1; i < 28124; i++) {
        if (sums[i] > i) abundant.insert(i);
    }

    int sum = 0;
    for (int i = 1; i < 28124; i++) {
        bool sum_of_abundant = false;
        // If j is abundant and i - j is abundant,
        // then i is the sum of two abundant numbers
        for (int j : abundant) {
            if (abundant.find(i - j) != abundant.end()) {
                sum_of_abundant = true;
                break;
            }
        }
        if (!sum_of_abundant) sum += i;
    }

    std::cout << "Total sum = " << sum << std::endl;
}