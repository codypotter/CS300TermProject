//
// Created by Cody Potter on 11/1/2019.
//

#ifndef CS300TERMPROJECT_SERVICE_H
#define CS300TERMPROJECT_SERVICE_H

#include <vector>
#include <string>
#include "include/json/json.h"

class Service {
public:
    std::string id;
    std::string serviceDate;
    std::string submissionDate;
    std::string memberID;
    std::string providerID;
    std::string serviceCode;
    int fee;

    // Constructor
    Service(Json::Value& serviceRef, std::string key);
    Service(std::string id, std::string serviceDate, std::string submissionDate, std::string memberID, std::string providerID, std::string serviceCode, int fee);

    // Getters
    Json::Value getJsonValue();

};


#endif //CS300TERMPROJECT_SERVICE_H
