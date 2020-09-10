#include <fstream>
#include <iostream>
#include <algorithm>

#include "files_handler.h"
#include "../dna_exceptions/dna_exceptions.h"


std::string read_seq_from_file(std::string file_name)
{
    std::string line, output;
    std::string path = "./data_files/";
    path += file_name;

    std::ifstream my_file(path.c_str());

    if (!my_file.is_open() || my_file.peek() == std::ifstream::traits_type::eof())
    {
        throw UnableOpenFile("Unable to read from file");
    }

    std::string content((std::istreambuf_iterator<char>(my_file)), (std::istreambuf_iterator<char>()));
    content.erase(std::remove(content.begin(), content.end(), '\n'), content.end());
    return content;

//    while(getline(my_file,line))
//    {
//        output.append(line);
//        std::cout << line << std::endl;
//    }
//
//    my_file.close();
//
//    return output;

//    if(my_file.is_open())
//    {
//        while(getline(my_file,line) )
//        {
//            output.append(line);
//            std::cout << "read" << std::endl;
//        }
//        my_file.close();
//    }
//
//    else
//    {
//        std::cout << "file is closed" << std::endl;
//        throw UnableOpenFile("Unable to read from file");
//    }
//
//    return output;
}


void write_into_file(std::string file_name, std::string data)
{
    std::string path = "../../data_files/";
    path += file_name;

    std::ofstream my_file(path.c_str(), std::ios_base::app);

    if(!my_file.is_open())
    {
        throw UnableOpenFile("Unable to write to file");
    }

    my_file << data;
}