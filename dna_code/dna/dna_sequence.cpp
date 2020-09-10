#include "dna_sequence.h"



DnaSequence::Nucleotide::Nucleotide(char nucleotide)
{
    if(nucleotide == 'A' || nucleotide == 'G' || nucleotide == 'T' || nucleotide == 'C' || nucleotide == '\0')
    {
        m_nucleotide = nucleotide;
    }

    else
    {
        throw InvalidDNASeq("Invalid Char");
    }
}

// Nucleotide -----------------------------------------------------------------------

//void DnaSequence::init_dna_sequence(const char *sequence, const size_t sequenceLength)
//{
//    size_t i;
//
//    m_dna_seq  = new Nucleotide[sequenceLength + 1];
//
//    for (i =0 ; i < sequenceLength; i++)
//    {
//        m_dna_seq[i] = Nucleotide(sequence[i]);
//    }
//
//    m_dna_seq[sequenceLength] = Nucleotide('\0');
//}


//std::string DnaSequence::getDNASequence() const
//{
//    size_t i = 0;
//    std::string currDNASequence = "";
//
//    while (m_dna_seq[i].get_nucleotide() != '\0')
//    {
//        currDNASequence += m_dna_seq[i].get_nucleotide();
//        i++;
//    }
//
//    currDNASequence += '\0';
//
//    return currDNASequence;
//}


DnaSequence& DnaSequence::operator=(const DnaSequence& dnaSeq)
{
    if(this != &dnaSeq)
    {
        const std::string getDNASequence = dnaSeq.getDNASequence();
        const std::string currDNASequence = this->getDNASequence();

        delete [] m_dna_seq;
        try
        {
            init_dna_sequence(getDNASequence.c_str(), getDNASequence.size());
        }

        catch (std::exception &exp)
        {
            init_dna_sequence(currDNASequence.c_str(), currDNASequence.size());
        }
    }

    return *this;
}


DnaSequence& DnaSequence::operator=(const char *sequence)
{
    std::string currDNASequence = this->getDNASequence();

    delete [] m_dna_seq;

    try
    {
        init_dna_sequence(sequence, strlen(sequence));
    }

    catch (std::exception &exp)
    {
        init_dna_sequence(currDNASequence.c_str(), currDNASequence.size());
    }

    return *this;
}


DnaSequence& DnaSequence::operator=(const std::string sequence)
{
    std::string currDNASequence = this->getDNASequence();

    delete [] m_dna_seq;

    try
    {
        init_dna_sequence(sequence.c_str(), sequence.size());
    }

    catch (std::exception &exp)
    {
        init_dna_sequence(currDNASequence.c_str(), currDNASequence.size());
    }

    return *this;
}


DnaSequence DnaSequence::slicing(size_t from, size_t to) const
{
    size_t i;
    std::string strSubSeq;

    if(to < from || to > seqLen() - 1)
    {
        to = 1;
        from = 0;
    }

    for(i = from + 1; i < to; i++)
    {
        strSubSeq += m_dna_seq[i].get_nucleotide();
    }

    DnaSequence subSeq(strSubSeq);

    return subSeq;
}


DnaSequence DnaSequence::pairing() const
{
    size_t i = 0;
    size_t j = seqLen() - 1;
    char currNucleotide;
    std::string strPairedSeq;
    std::map<char, char> pairingMap;
    pairingMap['A'] = 'T';
    pairingMap['C'] = 'G';
    pairingMap['G'] = 'C';
    pairingMap['T'] = 'A';


    for (; i < seqLen() - 1; i++, j--)
    {
        currNucleotide = m_dna_seq[j].get_nucleotide();
        strPairedSeq += pairingMap[currNucleotide];
    }

    DnaSequence pairedSeq(strPairedSeq);

    return pairedSeq;
}


size_t DnaSequence::find(const DnaSequence &dnaSubSeq, size_t fromIndex) const
{

    std::string currStr = getDNASequence();
    std::string subStr = dnaSubSeq.getDNASequence();
    size_t currStrLen = seqLen();
    size_t subStrLen = dnaSubSeq.seqLen();
    size_t i = 0;
    size_t j = 0;

    for(i = fromIndex; i < currStrLen; i++)
    {
        if(currStr[i] == subStr[0])
        {
            for(j = 0; j < subStrLen; j++)
            {
                if(currStr[i + j] != subStr[j])
                {
                    break;
                }
            }

            if(j == subStrLen)
            {
                return i;
            }
        }
    }

    return (size_t)-1;
}


std::vector<size_t> DnaSequence::findAll(const DnaSequence &dnaSubSeq) const
{
    std::vector<size_t> indexesVec;
    size_t i = 0;
    size_t subSeqIndex = -1;

    while(i <= seqLen() - dnaSubSeq.seqLen())
    {
        subSeqIndex = find(dnaSubSeq, i);

        if(subSeqIndex < seqLen() && subSeqIndex != (size_t)-1)
        {
            indexesVec.push_back(subSeqIndex);
        }

        i++;
    }

    return indexesVec;
}


//std::vector<DnaSequence> DnaSequence::findConsensusSeq() const
//{
//    std::vector<DnaSequence> consensusSeq;
//
//    DnaSequence startCodon("ATG");
//    DnaSequence endCodon1("TAG");
//    DnaSequence endCodon2("TAA");
//    DnaSequence endCodon3("TGA");
//
//    std::vector<size_t> start_indexes = findAll(startCodon);
//
//}





