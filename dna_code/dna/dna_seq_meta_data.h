#ifndef DNAANALYZERPROJECT_DNA_SEQ_META_DATA_H
#define DNAANALYZERPROJECT_DNA_SEQ_META_DATA_H

#include "dna_sequence.h"

class DnaSeqMetaData // TODO: should contains DnaSequence?
{
    public:
        DnaSeqMetaData(std::string name, const char *sequence);
        DnaSeqMetaData(std::string name, const std::string sequence);

        std::string get_dna_seq() const;
        size_t get_id() const;
        std::string get_seq_name() const;

    private:
        std::string m_name;
        size_t m_id;
        DnaSequence* m_seq;
};

static size_t id = 0;

inline DnaSeqMetaData::DnaSeqMetaData(std::string name, const char *sequence)
: m_name(name), m_id(++id), m_seq(NULL)
{
    m_seq = new DnaSequence(sequence);
}

inline DnaSeqMetaData::DnaSeqMetaData(std::string name, const std::string sequence)
: m_name(name), m_id(++id), m_seq(NULL)
{
    m_seq = new DnaSequence(sequence);
}

inline std::string DnaSeqMetaData::get_dna_seq() const
{
    return m_seq->getDNASequence();
}

inline size_t DnaSeqMetaData::get_id() const
{
    return m_id;
}

inline std::string DnaSeqMetaData::get_seq_name() const
{
    return m_name;
}

#endif //DNAANALYZERPROJECT_DNA_SEQ_META_DATA_H
