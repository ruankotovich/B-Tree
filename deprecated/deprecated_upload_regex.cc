#include <fstream>
#include <iostream>
#include <regex>

int ocurrences(const std::string& str, char c)
{
    int count = 0;
    int i = 0;

    size_t contain;
    while ((contain = str.find(c, i)) != std::string::npos) {
        count++;
        i = contain + 1;
    }

    return count;
}

int main()
{
    std::ifstream fileStream("./misc/testinho.txt");
    std::string lineBuffer;
    std::string completeBuffer;
    std::vector<std::string> completition;
    int occurrenceTilNow = 0;

    while (std::getline(fileStream, lineBuffer, '\n')) {
        occurrenceTilNow += ocurrences(lineBuffer, ';');
        completeBuffer += lineBuffer;

        if (occurrenceTilNow >= 6) {
            occurrenceTilNow = 0;
            completition.push_back(completeBuffer);
            completeBuffer.clear();
        }
    }

    std::regex record("\"(.*)\";\"?(.*)\"?;\"?(.*)\"?;\"?(.*)\"?;\"?(.*)\"?;\"?(.*)\"?;\"?(.*)\"?");

    for (auto a : completition) {
        if (std::regex_match(a, record)) {
            std::cout << "Record Matched\n";
        } else {
            std::cout << "Record Not Matched\n";
        }
    }
}