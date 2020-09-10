#ifndef DNAANALYZERPROJECT_COMMANDS_H
#define DNAANALYZERPROJECT_COMMANDS_H


#include "../dna/dna_seq_meta_data.h"


class ICommand
{
    public:
        virtual ~ICommand(){};

        virtual std::string do_action(const std::vector<std::string>& params) = 0;

    private:

};


#endif //DNAANALYZERPROJECT_COMMANDS_H
