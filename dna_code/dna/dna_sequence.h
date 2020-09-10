#ifndef DNA_SEQUENCE_DNA_SEQUENCE_H
#define DNA_SEQUENCE_DNA_SEQUENCE_H

#include <string>
#include <ostream>
#include <iostream>
#include "cstring"
#include <map>
#include <vector>

#include "../dna_exceptions/dna_exceptions.h"



class DnaSequence
{
    private:
        class Nucleotide
        {
            public:
                Nucleotide(){}
                Nucleotide(char nucleotide);
                Nucleotide& operator= (const Nucleotide& nucleotide);
                Nucleotide& operator= (const char nucleotide);
                operator char() const;

                char get_nucleotide() const;

            private:
                char m_nucleotide;
        };

        Nucleotide *m_dna_seq;


    public:
        DnaSequence(const char *sequence);
        DnaSequence(const std::string sequence);
        DnaSequence(const DnaSequence& dnaSeq);
        ~DnaSequence();

        void init_dna_sequence(const char *sequence, const size_t sequenceLength);

        DnaSequence& operator= (const DnaSequence& dnaSeq);
        DnaSequence& operator= (const char *sequence);
        DnaSequence& operator= (const std::string sequence);
        friend std::ostream& operator<< (std::ostream& os, const DnaSequence& dnaSeq);
        bool operator== (const DnaSequence& dnaSeq) const;
        bool operator!= (const DnaSequence& dnaSeq);
        const DnaSequence::Nucleotide& operator[] (size_t index) const;
        DnaSequence::Nucleotide& operator[] (size_t index);

        size_t seqLen() const;
        std::string getDNASequence() const;
        DnaSequence slicing(size_t from, size_t to) const;
        DnaSequence pairing() const;
        size_t find(const DnaSequence& dnaSubSeq, size_t fromIndex) const;
        std::vector<size_t> findAll(const DnaSequence& dnaSubSeq) const;
        size_t count(const DnaSequence& dnaSubSeq) const;
//        std::vector<DnaSequence> findConsensusSeq() const;
};

//-------------------------------------------------------------------------------------------

inline char DnaSequence::Nucleotide::get_nucleotide() const
{
    return this->m_nucleotide;
}


inline DnaSequence::Nucleotide::operator char() const
{
    return m_nucleotide;
}

//-------------------------------------------------------------------------------------------

inline DnaSequence::DnaSequence(const char *sequence)
{
    init_dna_sequence(sequence, strlen(sequence));
}


inline DnaSequence::DnaSequence(const std::string sequence)
{
    init_dna_sequence(sequence.c_str(), sequence.size());
}


inline DnaSequence::DnaSequence(const DnaSequence &dnaSeq)
{
    init_dna_sequence(dnaSeq.getDNASequence().c_str(), dnaSeq.seqLen());
}


inline DnaSequence::~DnaSequence()
{
    delete [] m_dna_seq;
}


inline DnaSequence::Nucleotide& DnaSequence::Nucleotide::operator=(const Nucleotide &nucleotide)
{
    if(this != &nucleotide)
    {
        m_nucleotide = nucleotide.m_nucleotide;
    }

    return *this;
}


inline DnaSequence::Nucleotide& DnaSequence::Nucleotide::operator=(const char nucleotide)
{
    m_nucleotide = nucleotide;

    return *this;
}


inline std::ostream& operator<< (std::ostream& output, const DnaSequence& dnaSeq)
{
    output << "DNA Sequence: " << dnaSeq.getDNASequence().c_str() << std::endl;

    return output;
}


inline bool DnaSequence::operator==(const DnaSequence &dnaSeq) const
{
    std::string getDNASequence = dnaSeq.getDNASequence();
    std::string currDNASequence = this->getDNASequence();

    return currDNASequence == getDNASequence;
}


inline bool DnaSequence::operator!= (const DnaSequence &dnaSeq)
{
    std::string getDNASequence = dnaSeq.getDNASequence();
    std::string currDNASequence = this->getDNASequence();

    return currDNASequence != getDNASequence;
}


inline const DnaSequence::Nucleotide& DnaSequence::operator[](size_t index) const
{
    if(index > this->seqLen() - 1)
    {
        throw InvalidDNASeq("Index is out of range");
    }

    return const_cast<Nucleotide &>(m_dna_seq[index]);
}


inline DnaSequence::Nucleotide& DnaSequence::operator[](size_t index)
{
    if(index > this->seqLen() - 1)
    {
        throw InvalidDNASeq("Index is out of range");
    }

    return const_cast<Nucleotide &>(m_dna_seq[index]);
}


inline size_t DnaSequence::seqLen() const
{
    std::string currDNASequence = this->getDNASequence();
    return currDNASequence.size() - 1;
}


inline size_t DnaSequence::count(const DnaSequence &dnaSubSeq) const
{
    return findAll(dnaSubSeq).size();
}


//TODO: from cpp file
inline void DnaSequence::init_dna_sequence(const char *sequence, const size_t sequenceLength)
{
    size_t i;

    m_dna_seq  = new Nucleotide[sequenceLength + 1];

    for (i =0 ; i < sequenceLength; i++)
    {
        m_dna_seq[i] = DnaSequence::Nucleotide(sequence[i]);
    }

    m_dna_seq[sequenceLength] = Nucleotide('\0');
}

//TODO: from cpp file
inline std::string DnaSequence::getDNASequence() const
{
    size_t i = 0;
    std::string currDNASequence = "";

    while (m_dna_seq[i].get_nucleotide() != '\0')
    {
        currDNASequence += m_dna_seq[i].get_nucleotide();
        i++;
    }

    currDNASequence += '\0';

    return currDNASequence;
}

#endif //DNA_SEQUENCE_DNA_SEQUENCE_H
