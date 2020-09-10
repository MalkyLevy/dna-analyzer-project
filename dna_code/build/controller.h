#ifndef DNAANALYZERPROJECT_CONTROLLER_H
#define DNAANALYZERPROJECT_CONTROLLER_H

#include "../manager/cli.h"
#include "./cmd_factory.h"


class Controller
{
public:
    void run();

private:
    CLI* m_cli;
    CmdFactory* m_factory;
};


#endif //DNAANALYZERPROJECT_CONTROLLER_H
