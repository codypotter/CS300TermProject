//
// Created by Cody Potter on 10/24/2019.
//
#include "include/json/json.h"
#include "Database.h"
#include <fstream>
#include <iostream>

Database::Database(char* rootPath) {
    std::cout << "running database constructor" <<std::endl;

    std::ifstream ifs(rootPath);
    Json::Reader reader;
    reader.parse(ifs, rootRef);

    Json::Value membersRef = rootRef["members"];
    Json::Value providersRef = rootRef["providers"];
    Json::Value servicesRef = rootRef["services"];

    for( Json::Value::iterator memberIterator = membersRef.begin() ; memberIterator != membersRef.end() ; memberIterator++ ) {
        members.push_back(Member(membersRef[memberIterator.key().asString()], memberIterator.key().asString()));
    }

    for( Json::Value::iterator providerIterator = providersRef.begin() ; providerIterator != providersRef.end() ; providerIterator++ ) {
        providers.push_back(Provider(providersRef[providerIterator.key().asString()], providerIterator.key().asString()));
    }

    for( Json::Value::iterator serviceIterator = servicesRef.begin() ; serviceIterator != servicesRef.end() ; serviceIterator++ ) {
        services.push_back(Service(servicesRef[serviceIterator.key().asString()], serviceIterator.key().asString()));
    }

}

bool Database::update() {
    Json::FastWriter writer;
    const std::string json_file = writer.write(rootRef);
    std::cout << json_file << std::endl; // currently writing to cout, just need to change this to an ofstream pointed at the json file and it'll write to the json database
    return true;
}

bool Database::addMember(Member newMember) {
    rootRef["members"][newMember.getID()] = newMember.getJsonValue();

    update();
    return true;
}