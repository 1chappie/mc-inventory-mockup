//
// Created by chappie on 19.04.2022.
//

#ifndef MC_INVENTORY_MOCKUP_REPO_H
#define MC_INVENTORY_MOCKUP_REPO_H

#include <vector>
#include <algorithm>

using std::vector;

template<typename TElem>
class Repo {
protected:
    vector<TElem> elems;
public:
    Repo();

    ~Repo();

    virtual void add(const TElem &);

    virtual void update(const TElem &);

    virtual void remove(const TElem &);

    virtual const TElem &search(const TElem &);

    virtual const vector<TElem> &get_all();

    virtual int size();
};

};


#endif //MC_INVENTORY_MOCKUP_REPO_H
