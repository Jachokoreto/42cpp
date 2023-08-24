#include "BitcoinExchange.hpp"
// create a program which outputs the value of a certain amount of bitcoin
// on a certain date.
// This program must use a database in csv format which will represent bitcoin price
// over time. This database is provided with this subject.
// The program will take as input a second database, storing the different prices/dates
// to evaluate.
// Your program must respect these rules:
// • The program name is btc.
// • Your program must take a file as argument.
// • Each line in this file must use the following format: "date | value".
// • A valid date will always be in the following format: Year-Month-Day.
// • A valid value must be either a float or a positive integer between 0 and 1000.

BitcoinExchange::BitcoinExchange(std::string filename) : _filename(filename)
{
    // read csv
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        exit(1);
    }

    // read each line of csv
    std::string line;
    while (std::getline(file, line))
    {
        // skip the first line
        if (line.find("date") != std::string::npos)
            continue;
        // split line by comma
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, ','))
        {
            tokens.push_back(token);
        }
        // store data in exchangeRates
        // std::cout << tokens[1] << std::endl;
        _exchangeRates[tokens[0]] = std::stof(tokens[1]);
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

namespace util
{
    int stoi(std::string str)
    {
        std::stringstream ss(str);
        int val;
        ss >> val;
        return val;
    }
} // namespace util

void BitcoinExchange::readFileToEvaluate(std::string filename)
{
    // read filename file
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        exit(1);
    }

    // read each line of filename file
    std::string line;
    while (std::getline(file, line))
    {
        _dataToEvaluate.push_back(line);
    }
    file.close();
}

void BitcoinExchange::evaluate()
{
    // for each line in _dataToEvaluate
    for (size_t i = 0; i < _dataToEvaluate.size(); i++)
    {
        // split line by |

        std::vector<std::string> tokens = split(_dataToEvaluate[i], '|');
        try
        {
            if (tokens.size() != 2)
                throw std::runtime_error("invalid data format.");
            std::string date = getDate(tokens[0]);
            float val = getValue(tokens[1]);

            // check if date is in _exchangeRates
            if (_exchangeRates.find(date) == _exchangeRates.end())
                throw std::runtime_error("date not found.");

            // calculate value
            float calValue = val * _exchangeRates[date];
            // print result
            std::cout << date << " => " << val
                      << std::fixed << std::setprecision(2) << " = " << calValue << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what()
                      << " => " << _dataToEvaluate[i] << std::endl;
        }
    }
}

std::string BitcoinExchange::getDate(std::string date)
{
    // format : Yera-Month-Day

    // check if date is valid
    //  if not valid, print error message and exit

    // split data witn -
    std::vector<std::string> tokens;
    int toCheck;

    date = date.substr(0, 10);
    tokens = split(date, '-');
    if (tokens.size() != 3)
        throw std::runtime_error("invalid date.");
    // check year
    if (isNumeric(tokens[0]) == 1 || tokens[0].length() != 4)
        throw std::runtime_error("invalid year.");
    // check month
    toCheck = util::stoi(tokens[1]);
    if (isNumeric(tokens[1]) == 1 || tokens[1].length() != 2 || toCheck < 1 || toCheck > 12)
    {
        throw std::runtime_error("invalid month");
    }
    // check day
    toCheck = util::stoi(tokens[2]);
    if (isNumeric(tokens[2]) == 1 || tokens[2].length() != 2 || toCheck < 1 || toCheck > 31)
        throw std::runtime_error("invalid day.");
    return date;
}

float BitcoinExchange::getValue(std::string value)
{
    // check if value is valid
    //  if not valid, print error message and exit
    float val;

    // if (isNumeric(value) == 1)
    //     throw std::runtime_error("invalid value.");
    try
    {
        val = std::stof(value);
    }
    catch (std::exception &e)
    {
        throw std::runtime_error("invalid value.");
    }
    if (val < 0)
        throw std::runtime_error("not a positive number.");
    if (val > 1000)
        throw std::runtime_error("too large a number.");
    return val;
}

int BitcoinExchange::isNumeric(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        // check that if character is not a space and not a digit
        if (str[i] != ' ' && !isdigit(str[i]))
            return 1;
    }
    return 0;
}

std::vector<std::string> BitcoinExchange::split(std::string str, char delimiter)
{
    std::stringstream ss(str);
    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
