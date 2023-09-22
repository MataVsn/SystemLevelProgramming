#include <iostream>
#include <fstream>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;

int main() {
    const char* inputFilePath = "input.txt";
    ifstream inputFile(inputFilePath);
    if (!inputFile) {
        cerr << "Не удалось открыть входной файл." << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    cpp_dec_float_100 pi = boost::math::constants::pi<cpp_dec_float_100>();
    cout.precision(N + 1);
    cout << fixed << pi << endl;

    const char* outputFilePath = "output.txt";

    ofstream outputFile(outputFilePath);
    if (!outputFile) {
        cerr << "Не удалось открыть выходной файл." << endl;
        return 1;
    }

    outputFile.precision(N + 1);
    outputFile << fixed << pi << endl;

    inputFile.close();
    outputFile.close();

    cout << "Число π с " << N << " десятичными разрядами сохранено в " << outputFilePath << endl;
    return 0;
}
