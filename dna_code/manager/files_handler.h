#ifndef DNAANALYZERPROJECT_FILES_HANDLER_H
#define DNAANALYZERPROJECT_FILES_HANDLER_H

#include <string>

std::string read_seq_from_file(std::string file_name);
void write_into_file(std::string file_name, std::string data);

#endif //DNAANALYZERPROJECT_FILES_HANDLER_H
