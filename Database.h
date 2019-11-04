//
// Created by Cody Potter on 10/24/2019.
//

#ifndef CS300TERMPROJECT_DATABASE_H
#define CS300TERMPROJECT_DATABASE_H

#include <vector>
#include <string>
#include "Member.h"
#include "Provider.h"
#include "Service.h"
#include "include/json/json.h"

class Database {
public:
    Database(char* rootPath);

    bool update();
    bool addMember(Member newMember);

private:
    Json::Value rootRef;
    std::vector<Member> members;
    std::vector<Provider> providers;
    std::vector<Service> services;
};


#endif //CS300TERMPROJECT_DATABASE_H
