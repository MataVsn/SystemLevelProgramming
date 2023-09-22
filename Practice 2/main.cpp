#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string inputFileName = "input.txt"
    string outputFileName = "output.txt"; 

    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Не удалось открыть входной файл." << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    sort(lines.begin(), lines.end());

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cerr << "Не удалось открыть выходной файл." << endl;
        return 1;
    }

    for (const string& sortedLine : lines) {
        outputFile << sortedLine << endl;
    }
    inputFile.close();
    outputFile.close();

    cout << "Сортировка завершена. Результат записан в " << outputFileName << endl;
    return 0;
}
