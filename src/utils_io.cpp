#include "utils_io.h"

std::string get_file_content(std::string file_path) {
    std::ifstream file;
    
    file.open(file_path);
    
    std::string file_content;
    std::string line;
    
    while(file.good()) {
        file >> line;
        if (file.good()) {
            file_content.append(line);
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
