//
// Created by Cody Potter on 10/24/2019.
//

#ifndef CS300TERMPROJECT_DATABASE_H
#define CS300TERMPROJECT_DATABASE_H

#include <iterator>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>

#include "Member.h"
#include "Provider.h"
#include "Service.h"

#include "include/json/json.h"

class Database {
public:
    // Constructor
    Database(char* rootPath);

    // JSON Database Operations
    void update();

    // Utilities
    std::string generateNewID(int length);
    void printMembers();
    void printProviders();
    void printServices();

    // CRUD Operations for Members
    void addMember(std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZip);
    bool removeMember(std::string memberID);

    // CRUD Operations for Providers
    void addProvider(std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZip);
    bool removeProvider(std::string providerID);

    // CRUD Operations for Services
    void addService(std::string serviceDate, std::string submissionDate, std::string memberID, std::string providerID, std::string serviceCode, int fee);
    bool removeService(std::string serviceID);

    std::map<std::string, Member> members;
    std::map<std::string, Provider> providers;
    std::map<std::string, Service> services;

private:
    std::string path;
    Json::Value rootRef;

    // JSON Database Operations
    void write();
    void reload();
};


#endif //CS300TERMPROJECT_DATABASE_H
