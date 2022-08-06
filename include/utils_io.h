#pragma once

#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

auto get_file_content(std::string file_path) -> std::string;
void write_json(const nlohmann::json &json, const std::string &file_path);
