#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Не удалось открыть входной файл." << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    int number
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    std::sort(numbers.begin(), numbers.end());

    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Не удалось открыть выходной файл." << std::endl;
        return 1;
    }
    for (const int& num : numbers) {
        outputFile << num << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Числа были успешно отсортированы и записаны в output.txt" << std::endl;
    return 0;
}
