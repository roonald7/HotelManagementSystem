#pragma once

#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

std::string get_file_content(std::string file_path) {
    std::ifstream file;
    
    file.open(file_path);
    
    std::string file_content;
    std::string line;
    
    while(file.good()) {
        file >> line;
        if (file.good()) {
            file_content.append(line + "\n");
        } 
    }
    
    file.close();
    return file_content;
}

void write_json(const nlohmann::json &json, const std::string &file_path)
{
    std::ofstream file(file_path);
           
    file << std::setw(4) << json << std::endl;
}