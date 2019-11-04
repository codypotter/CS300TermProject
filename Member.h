//
// Created by Cody Potter on 10/24/2019.
//

#ifndef CS300TERMPROJECT_MEMBER_H
#define CS300TERMPROJECT_MEMBER_H

#include <vector>
#include <string>
#include "include/json/json.h"

class Member {
private:
    std::string name;
    std::string id;
    bool isValid;
    std::string street;
    std::string city;
    std::string state;
    std::string zip;

    std::vector<std::string> services;

public:
    // Constructor
    Member(Json::Value& memberRef, std::string key);
    Member(std::string newID, std::string newName);

    // Getters
    std::string getName();
    std::string getID();
    bool getIsValid();
    std::string getStreet();
    std::string getCity();
    std::string getState();
    std::string getZip();
    std::vector<std::string> getServices();
    Json::Value getJsonValue();

    // Setters
    void setName(std::string newName);
    void setID(std::string newID);
    void setIsValid(bool newIsValid);
    void setStreet(std::string newStreet);
    void setCity(std::string newCity);
    void setState(std::string newState);
    void setZip(std::string newZip);
    void setServices(std::vector<std::string> newServices);
};


#endif //CS300TERMPROJECT_MEMBER_H
