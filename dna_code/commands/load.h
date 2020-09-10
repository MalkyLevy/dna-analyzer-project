#ifndef DNAANALYZERPROJECT_LOAD_H
#define DNAANALYZERPROJECT_LOAD_H

#include "icommand.h"
#include "../manager/files_handler.h"

class Load : public ICommand
{
    public:
        /* virtual */ std::string do_action(const std::vector<std::string>& params);

    private:
        void is_valid_params(const std::vector<std::string>& params) const;
        void print_sequence(const DnaSeqMetaData& metaData) const;
        std::string create_seq_name(const std::vector<std::string>& params) const;
        void update_dnas_data(DnaSeqMetaData& metaData) const;
};


#endif //DNAANALYZERPROJECT_LOAD_H
