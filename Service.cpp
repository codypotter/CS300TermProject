//
// Created by Cody Potter on 11/1/2019.
//

#include "Service.h"

//////////////////// Constructors ////////////////////
/**
 * Constructor from a JSON Value (typically read from a file)
 * @param serviceRef - a reference to the json service value
 * @param key - the key to the serviceRef
 */
Service::Service(Json::Value& serviceRef, std::string key) {
    id =                key;
    serviceDate =       serviceRef["serviceDate"].asString();
    submissionDate =    serviceRef["submissionDate"].asString();
    memberID =          serviceRef["memberID"].asString();
    providerID =        serviceRef["providerID"].asString();
    serviceCode =       serviceRef["serviceCode"].asString();
    fee =               serviceRef["fee"].asInt();
}

/**
 * Constructor from a User Interface
 * @param newID
 * @param newServiceDate
 * @param newSubmissionDate
 * @param newMemberID
 * @param newProviderID
 * @param newServiceCode
 * @param newFee
 */
Service::Service(std::string newID, std::string newServiceDate, std::string newSubmissionDate, std::string newMemberID, std::string newProviderID, std::string newServiceCode, int newFee) {
    id =                newID;
    serviceDate =       newServiceDate;
    submissionDate =    newSubmissionDate;
    memberID =          newMemberID;
    providerID =        newProviderID;
    serviceCode =       newServiceCode;
    fee =               newFee;
}

//////////////////// Getters ////////////////////
/**
 * Gets a JSON value representation of the class instance
 * @return the JSON value
 */
Json::Value Service::getJsonValue() {
    Json::Value jsonValue;

    jsonValue["id"] = id;
    jsonValue["serviceDate"] = serviceDate;
    jsonValue["submissionDate"] = submissionDate;
    jsonValue["memberID"] = memberID;
    jsonValue["providerID"] = providerID;
    jsonValue["serviceCode"] = serviceCode;
    jsonValue["fee"] = fee;

    return jsonValue;
}