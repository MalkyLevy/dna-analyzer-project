#ifndef DNAANALYZERPROJECT_CLI_H
#define DNAANALYZERPROJECT_CLI_H

#include <sstream>

#include "../commands/icommand.h"
#include "../build/cmd_factory.h"


class CLI
{
    public:
//        CLI();
//        ICommand* get_icommand() const;
//        std::vector<std::string>& get_params_vec();

    std::string input() const;
    std::vector<std::string> split(const std::string& strCmd) const;
    void output(std::string output) const;


//private:
//        std::string m_strCmd;
//        ICommand* m_icommand;
//        std::vector<std::string> m_params; // TODO: global?


};


//inline CLI::CLI() : m_strCmd(input()), m_icommand(NULL), m_params(split(m_strCmd))
//{
//    m_icommand = CmdFactory().create_cmd(m_params[0]);
//}
//
//inline ICommand * CLI::get_icommand() const
//{
//    return m_icommand;
//}

//inline std::vector<std::string> & CLI::get_params_vec()
//{
//    return m_params;
//}


#endif //DNAANALYZERPROJECT_CLI_H
