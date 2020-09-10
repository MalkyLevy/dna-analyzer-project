#include "controller.h"
#include "../commands/icommand.h"


void Controller::run()
{
    std::vector<std::string> params = m_cli->split(m_cli->input());

    ICommand* command = m_factory->create_cmd(params[0]);

    m_cli->output(command->do_action(params));

    delete command;
    command = NULL;
}