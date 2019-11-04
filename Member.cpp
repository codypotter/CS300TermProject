//
// Created by Cody Potter on 10/24/2019.
//

#include "Member.h"

Member::Member(Json::Value& memberRef, std::string key) {
    name =      memberRef["name"].asString();
    id =        key;
    isValid =   memberRef["isValid"].asBool();
    street =    memberRef["street"].asString();
    city =      memberRef["city"].asString();
    state =     memberRef["state"].asString();
    zip =       memberRef["zip"].asString();

    for (int i = 0; i < memberRef["services"].size(); i++) {
        services.push_back(memberRef["services"][i].asString());
    }
    std::cout << "Member constructor being called. ID: " << id << std::endl;
}

Member::Member(std::string newID, std::string newName) {
    name = newName;
    id = newID;
}

// Getters
Json::Value Member::getJsonValue() {
    Json::Value jsonValue;

    jsonValue["name"] = name;
    jsonValue["id"] = id;

    return jsonValue;
}

std::string Member::getID() {
    return id;
}