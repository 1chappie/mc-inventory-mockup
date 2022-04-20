//
// Created by chappie on 19.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_REPOEXCEPTION_H
#define MC_INVENTORY_MOCKUP_REPOEXCEPTION_H

#include <exception>
#include <string>

class RepoException : public std::exception {
private:
    std::string message;
public:
    RepoException(const std::string &_message);

    const char *what() const noexcept override;
};


#endif //MC_INVENTORY_MOCKUP_REPOEXCEPTION_H

