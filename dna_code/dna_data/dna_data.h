#ifndef DNAANALYZERPROJECT_DNA_DATA_H
#define DNAANALYZERPROJECT_DNA_DATA_H

#include <vector>
#include "../dna/dna_seq_meta_data.h"

class DnasData
{
    public:
        static std::vector<DnaSeqMetaData*> m_ids;
        static std::map<std::string, DnaSeqMetaData*> m_names;

    private:

};

#endif //DNAANALYZERPROJECT_DNA_DATA_H
