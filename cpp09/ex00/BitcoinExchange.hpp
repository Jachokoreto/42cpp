#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <stdexcept>

class BitcoinExchange
{
private:
    std::string _filename;
    std::map<std::string, float> _exchangeRates;
    std::vector<std::string> _dataToEvaluate;

    std::string getDate(std::string date);
    float getValue(std::string value);
    int isNumeric(std::string str);
    std::vector<std::string> split(std::string str, char delimiter);

public:
    BitcoinExchange(std::string filename);
    ~BitcoinExchange();
    void readFileToEvaluate(std::string filename);
    void evaluate();
};
