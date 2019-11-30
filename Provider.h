//
// Created by Cody Potter on 11/1/2019.
//

#ifndef CS300TERMPROJECT_PROVIDER_H
#define CS300TERMPROJECT_PROVIDER_H

#include <vector>
#include <string>
#include <json/json.h>

class Provider {
public:
    /////////////////// Members ////////////////////
    std::string name;
    std::string id;
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
    std::vector<std::string> services;

    /////////////////// Constructors ////////////////////
    Provider(Json::Value& providerRef, std::string key);
    Provider(std::string newID, std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZip);

    /////////////////// Getters ////////////////////
    Json::Value getJsonValue();

};


#endif //CS300TERMPROJECT_PROVIDER_H
