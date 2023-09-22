#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
vector<int> findPrimes(int N) {
    vector<bool> isPrime(N + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= N; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= N; i += p) {
                isPrime[i] = false;
            }
        }
    }
    for (int p = 2; p <= N; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

int main() {
    const char* inputFilePath = "input.txt";
    ifstream inputFile(inputFilePath);
    if (!inputFile) {
        cerr << "Не удалось открыть входной файл." << endl;
        return 1;
    }

    int N;
    inputFile >> N;
    vector<int> primes = findPrimes(N);
    const char* outputFilePath = "output.txt";
    ofstream outputFile(outputFilePath);
    if (!outputFile) {
        cerr << "Не удалось открыть выходной файл." << endl;
        return 1;
    }

    for (size_t i = 0; i < primes.size(); ++i) {
        outputFile << primes[i];
        if (i < primes.size() - 1) {
            outputFile << ", ";
        }
    }
    inputFile.close();
    outputFile.close();

    cout << "Простые числа до " << N << " сохранены в " << outputFilePath << endl;
    return 0;
}
