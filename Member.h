//
// Created by Cody Potter on 10/24/2019.
//

#ifndef CS300TERMPROJECT_MEMBER_H
#define CS300TERMPROJECT_MEMBER_H

#include <vector>
#include <string>
#include "include/json/json.h"

/**
 * Represents a member record from the ChocAn Database
 * READ-ONLY
 */
class Member {
public:
    //////////////////// Variables ////////////////////
    std::string name;
    std::string id;
    bool isValid;
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
    std::vector<std::string> services;

    //////////////////// Constructors ////////////////////
    Member(Json::Value& memberRef, std::string key);
    Member(std::string newID, std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZip);

    //////////////////// Getters ////////////////////
    Json::Value getJsonValue();

    //////////////////// Setters ////////////////////
    void addService(std::string serviceID);
    void removeService(std::string serviceID);
};


#endif //CS300TERMPROJECT_MEMBER_H
