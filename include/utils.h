#pragma once

#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

std::string get_file_content(std::string file_path);
void write_json(const nlohmann::json &json, const std::string &file_path);