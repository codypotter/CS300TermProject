//
// Created by Cody Potter on 11/1/2019.
//

#ifndef CS300TERMPROJECT_SERVICE_H
#define CS300TERMPROJECT_SERVICE_H

#include <vector>
#include <string>
#include "include/json/json.h"

class Service {
private:
    std::string id;
    std::string serviceDate;
    std::string submissionDate;
    std::string memberID;
    std::string providerID;
    std::string serviceCode;
    int fee;

public:
    // Constructor
    Service(Json::Value& serviceRef, std::string key);

    // Getters
    std::string getID();
    std::string getServiceDate();
    std::string getSubmissionDate();
    std::string getMemberID();
    std::string getProviderID();
    std::string getServiceCode();
    std::string getFee();

    // Setters
    void setID(std::string newID);
    void setServiceDate(std::string newDate);
    void setSubmissionDate(std::string newDate);
    void setMemberID(std::string newID);
    void setProviderID(std::string newID);
    void setServiceCode(std::string newCode);
    void setFee(int newFee);
};


#endif //CS300TERMPROJECT_SERVICE_H
