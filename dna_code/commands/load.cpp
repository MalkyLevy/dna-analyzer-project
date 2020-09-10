#include "load.h"
//#include "../manager/files_handler.h"
#include "../dna_data/dna_data.h"


void Load::is_valid_params(const std::vector<std::string>& params) const
{
    if (params.size() < 2 || params.size() > 3)
    {
        throw InvalidAmountOfArguments("error");
    }

    if(params.size() == 3)
    {
        if (params.at(2)[0] != '@' || params.at(2).length() < 2)
        {
            throw InvalidArgument("error");
        }
    }
}

void Load::print_sequence(const DnaSeqMetaData& metaData) const
{
    std::string sequence = metaData.get_dna_seq();
    std::string output_seq;

    if (sequence.length() > 40)
    {
        output_seq = sequence.substr(0, 32);
        output_seq.append("...");
        std:: string last_3_nuc = sequence.substr(sequence.size() - 3, sequence.size());
        output_seq.append(last_3_nuc);
    }

    else
    {
        output_seq = sequence;
    }

    std::cout << "[" << metaData.get_id() << "] " << metaData.get_seq_name() << ": "<< output_seq;
}

std::string Load::create_seq_name(const std::vector<std::string>& params) const
{
    std::string seq_name;

    if (params.size() == 2)
    {
        seq_name = params[1].substr(0, params[1].size() - 4); //remove ".txt" suffix;
    }

    else
    {
        seq_name = params[2];
    }

    return seq_name;
}

void Load::update_dnas_data(DnaSeqMetaData& metaData) const
{
    DnasData::m_ids.resize(DnasData::m_ids.size() + 1);

    DnasData::m_ids[metaData.get_id()] = &metaData;
    DnasData::m_names[metaData.get_seq_name()] = &metaData;
}

std::string Load::do_action(const std::vector<std::string>& params)
{
    is_valid_params(params);

    std::string sequence = read_seq_from_file(params[1]);
    std::string seq_name = create_seq_name(params);

    DnaSeqMetaData metaData(seq_name, sequence);

    update_dnas_data(metaData);
    print_sequence(metaData);

    return "";
}