#include "cmd_factory.h"
#include "../commands/load.h"


ICommand* CmdFactory::create_cmd(const std::string& cmdName)
{
    ICommand* icmdPtr;

    if("load" == cmdName)
    {
        icmdPtr = new Load();
    }

    else
    {
        throw InvalidCmdName("Invalid command name");
    }

    return icmdPtr;
}
