//
// Created by chappie on 03.05.2022.
//

#include "FileService.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <regex>

FileService::FileService(Repo &_repo) : repo(_repo) {}

bool FileService::load(const std::string &path) {
    std::regex r("^.*\.(csv|CSV)$");
    if (!std::regex_match(path, r)) //path must end in .csv
        return false;

    std::ifstream fileLocation(path);
    if (!fileLocation.is_open())
        return false;

    std::string line, word;
    vector<string> row;
    vector<vector<string>> temp_content;
    while (getline(fileLocation, line)) {
        row.clear();
        std::stringstream str(line);
        while (getline(str, word, ','))
            row.push_back(word);
        temp_content.push_back(row); //TODO something here
    }
    for (auto &i: temp_content) {
        for (auto &j: i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return true;
}

bool FileService::save(const std::string &path) {
    return false;
}

bool FileService::save() {
    return false;
}


