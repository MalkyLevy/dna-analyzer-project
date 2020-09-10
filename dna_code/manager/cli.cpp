#include "./cli.h"


std::string CLI::input() const
{
    std::string input;

    std::cout << ">> my_cmd >> ";
    std::getline(std::cin, input);

    return input;
}

std::vector<std::string> CLI::split(const std::string& strCmd) const
{
    std::vector<std::string> params;
    std::istringstream iss(strCmd);
    std::string word;

    while(std::getline(iss, word, ' '))
    {
        params.push_back(word);
    }

    return params;
}

void CLI::output(std::string output) const
{
    std::cout << output << std::endl;
}

