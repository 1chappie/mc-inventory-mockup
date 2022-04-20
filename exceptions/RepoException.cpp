//
// Created by chappie on 19.04.2022.
//

#include "RepoException.h"

RepoException::RepoException(const std::string &_message) : message(_message) {}

const char *RepoException::what() const noexcept {
    return message.c_str();
}


