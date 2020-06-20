#include <iostream>
#include <vector>
#include <algorithm>

/*
 * Problem 18
 * Calculate the maximum sum of a path from the top to the bottom of the triangle
 */
int main() {
    std::vector<std::vector<int>> triangle = {
        {75},
        {95, 64},
        {17, 47, 82},
        {18, 35, 87, 10},
        {20,  4, 82, 47, 65},
        {19,  1, 23, 75,  3, 34},
        {88,  2, 77, 73,  7, 63, 67},
        {99, 65,  4, 28,  6, 16, 70, 92},
        {41, 41, 26, 56, 83, 40, 80, 70, 33},
        {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
        {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
        {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
        {63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
        { 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23},
    };

    // Calculate the max path to arrive at each number
    // The max path to the top element is itself, so no need to change that
    for (int i = 1; i < triangle.size(); i++) {
        // The leftmost element in each row has only one possible path
        triangle[i][0] += triangle[i - 1][0];
        // Interior elements can choose the left or right element above them
        for (int j = 1; j < i; j++) {
            triangle[i][j] += std::max(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
        // The rightmost element in each row has only one possible path
        triangle[i][i] += triangle[i - 1][i - 1];
    }

    for (const auto &i : triangle) {
        for (auto j : i) {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }

    int max = 0;
    // The bottom row contains the paths from top to bottom
    for (auto i : triangle.back()) {
        max = std::max(max, i);
    }
    std::cout << "Total max path = " << max << std::endl;
}
