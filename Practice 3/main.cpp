#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const char* inputFilePath = "input.txt";
    const char* outputFilePath = "output.txt";

    ifstream inputFile(inputFilePath, ios::binary);
    if (!inputFile) {
        cerr << "Не удалось открыть входной файл." << endl;
        return 1;
    }

    ofstream outputFile(outputFilePath, ios::binary);
    if (!outputFile) {
        cerr << "Не удалось открыть выходной файл." << endl;
        return 1;
    }

    outputFile << inputFile.rdbuf();

    inputFile.close();
    outputFile.close();

    cout << "Копирование завершено." << endl;
    return 0;
}
