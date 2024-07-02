#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 
using namespace std;
int main() {
    ifstream inputFile("example.txt"); // Replace "example.txt" with your file name
    if (!inputFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string fileContent;
    string line;
    while (getline(inputFile, line)) {
        fileContent += line + "\n";
    }

    inputFile.close();

    // Count characters (including spaces)
    int charCount = fileContent.length();

    // Count words
    int wordCount = 0;
    bool inWord = false;
    for (char c : fileContent) {
        if (isspace(static_cast<unsigned char>(c))) {
            inWord = false;
        }
        else if (!inWord) {
            inWord = true;
            ++wordCount;
        }
    }

    // Count sentences
    int sentenceCount = 0;
    for (char c : fileContent) {
        if (c == '.' || c == '!' || c == '?') {
            ++sentenceCount;
        }
    }

    cout << "File content:\n" << fileContent << endl;
    cout << "Number of characters (including spaces): " << charCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of sentences: " << sentenceCount << endl;

    return 0;
}
