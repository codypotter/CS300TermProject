//
// Created by Cody Potter on 11/26/2019.
//

#ifndef CS300TERMPROJECT_SERVICEENTRY_H
#define CS300TERMPROJECT_SERVICEENTRY_H

#include <string>
#include <json/json.h>

class ServiceEntry {
public:
    /////////////////// Members ////////////////////
    std::string name;
    std::string id;
    int fee;

    /////////////////// Constructors ////////////////////
    ServiceEntry(Json::Value& serviceEntryRef, std::string key);

    /////////////////// Getters ////////////////////
    Json::Value getJsonValue();
};


#endif //CS300TERMPROJECT_SERVICEENTRY_H
