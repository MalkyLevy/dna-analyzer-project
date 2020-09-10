#include <stdexcept>

#include "./dna_code/build/controller.h"


int main()
{
    Controller controller;

    while (true)
    {
        try
        {
            controller.run();
        }

        catch (const std::invalid_argument &ex)
        {
            std::cout << ex.what() << std::endl;
        }

        catch (const std::ios_base::failure &ex)
        {
            std::cout << ex.what() << std::endl;
        }
    }

//    try
//    {
//        CLI cli;
//        std::cout << cli.get_icommand()->do_action(cli.get_params_vec()) << std::endl;
//    }
//
//    //TODO:
//    catch (...)
//    {
//
//    }

    return 0;
}
