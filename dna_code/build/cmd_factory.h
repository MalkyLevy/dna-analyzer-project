#ifndef DNAANALYZERPROJECT_CMD_FACTORY_H
#define DNAANALYZERPROJECT_CMD_FACTORY_H

#include "../commands/icommand.h"
#include "../commands/load.h"

class CmdFactory
{
    public:
        ICommand* create_cmd(const std::string& cmdName);

};


#endif //DNAANALYZERPROJECT_CMD_FACTORY_H
