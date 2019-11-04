//
// Created by Cody Potter on 11/1/2019.
//

#ifndef CS300TERMPROJECT_PROVIDER_H
#define CS300TERMPROJECT_PROVIDER_H

#include <vector>
#include <string>
#include "include/json/json.h"

class Provider {
private:
    std::string name;
    std::string id;
    std::string street;
    std::string city;
    std::string state;
    std::string zip;

    std::vector<std::string> services;

public:
    // Constructor
    Provider(Json::Value& providerRef, std::string key);

    // Getters
    std::string getName();
    std::string getID();
    std::string getStreet();
    std::string getCity();
    std::string getState();
    std::string getZip();
    std::vector<std::string> getServices();

    // Setters
    void setName(std::string newName);
    void setID(std::string newID);
    void setStreet(std::string newStreet);
    void setCity(std::string newCity);
    void setState(std::string newState);
    void setZip(std::string newZip);
    void setServices(std::vector<std::string>newServices);
};


#endif //CS300TERMPROJECT_PROVIDER_H
