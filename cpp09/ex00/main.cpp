#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc <filename> <filename>" << std::endl;
        return 1;
    }
    BitcoinExchange exchange("data.csv");
    exchange.readFileToEvaluate(argv[1]);
    exchange.evaluate();
    return 0;
}