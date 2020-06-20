#include <iostream>
#include <vector>

// Find the sum of all amicable numbers under 10000
int main() {
    // Find the sum of divisors for each number
    // Check up to 20000 since a number < 10000 could be amicable with a number > 10000
    std::vector<int> sums(20000);
    for (int i = 1; i < 20000; i++) {
        // Find all proper multiples of each number
        for (int j = 2 * i; j < 20000; j += i) {
            sums[j] += i;
        }
    }
    
    int amicable_sum = 0;
    for (int i = 1; i < 10000; i++) {
        // Don't index past the end of the array
        // Check for d(a) = b and d(b) = a, where a != b
        if (sums[i] < 20000 && sums[i] != i && sums[sums[i]] == i) {
            amicable_sum += i;
            std::cout << i << " and " << sums[i] << " are amicable" << std::endl;
        }
    }
    
    std::cout << "Total sum = " << amicable_sum << std::endl;
}