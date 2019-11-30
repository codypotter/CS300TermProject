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
#include <cmath>

#include "Member.h"
#include "Provider.h"
#include "Service.h"
#include "ServiceEntry.h"

#include <json/json.h>

class Database {
public:
    // Constructor
    explicit Database(char* rootPath);

    // JSON Database Operations
    void update();

    // Utilities
    std::string generateNewID(int length);
    void printMembers();
    void printProviders();
    void printServices();
    void printDirectory();

    // CRUD Operations for Members
    std::string addMember(std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZip);
    bool removeMember(std::string memberID);

    // CRUD Operations for Providers
    std::string addProvider(std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZip);
    bool removeProvider(std::string providerID);

    // CRUD Operations for Services
    std::string addService(std::string serviceDate, std::string submissionDate, std::string memberID, std::string providerID, std::string serviceCode, int fee);
    bool removeService(std::string serviceID);

    // Getters
    Member& getMember(std::string memberID);
    Provider& getProvider(std::string providerID);
    Service& getService(std::string serviceID);
    ServiceEntry& getServiceEntry(std::string serviceEntryID);

    std::map<std::string, Member> members;
    std::map<std::string, Provider> providers;
    std::map<std::string, Service> services;
    std::map<std::string, ServiceEntry> directory;

private:
    std::string path;
    Json::Value rootRef;

    // JSON Database Operations
    void write();
    void reload();
};


#endif //CS300TERMPROJECT_DATABASE_H
