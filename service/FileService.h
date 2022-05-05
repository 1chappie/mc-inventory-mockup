//
// Created by chappie on 03.05.2022.
//

#ifndef MC_INVENTORY_MOCKUP_FILESERVICE_H
#define MC_INVENTORY_MOCKUP_FILESERVICE_H

#include "../persistence/Repo.h"


class FileService {
private:
    Repo &repo;
    std::string path;

public:
    FileService(Repo &);

    FileService() = delete;

    bool load(const std::string &path);

    bool save(const std::string &path);

    bool save();
};


#endif //MC_INVENTORY_MOCKUP_FILESERVICE_H
