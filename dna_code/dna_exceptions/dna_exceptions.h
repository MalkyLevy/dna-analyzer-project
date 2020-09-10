#ifndef DNA_SEQUENCE_INVALIDDNASEQ_H
#define DNA_SEQUENCE_INVALIDDNASEQ_H

#include <stdexcept>
#include <ios>

class InvalidDNASeq: public std::invalid_argument
{
    public:
        InvalidDNASeq(std::string error);
};

inline InvalidDNASeq::InvalidDNASeq(std::string error): std::invalid_argument(error){}

//-------------------------------------------------------------------------------------------------

class InvalidCmdName: public std::invalid_argument
{
    public:
        InvalidCmdName(std::string error);
};

inline InvalidCmdName::InvalidCmdName(std::string error): std::invalid_argument(error){}

//-------------------------------------------------------------------------------------------------

class UnableOpenFile: public std::ios_base::failure
{
    public:
        UnableOpenFile(std::string error);
};

inline UnableOpenFile::UnableOpenFile(std::string error): std::ios_base::failure(error){}

//-------------------------------------------------------------------------------------------------

class InvalidAmountOfArguments: public std::invalid_argument
{
    public:
        InvalidAmountOfArguments(std::string error);
};

inline InvalidAmountOfArguments::InvalidAmountOfArguments(std::string error): std::invalid_argument(error){}

//-------------------------------------------------------------------------------------------------

class InvalidArgument: public std::invalid_argument
{
    public:
        InvalidArgument(std::string error);
};

inline InvalidArgument::InvalidArgument(std::string error): std::invalid_argument(error){}

#endif //DNA_SEQUENCE_INVALIDDNASEQ_H
