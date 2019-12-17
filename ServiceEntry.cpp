//
// Created by enjoi on 11/26/2019.
//

#include "ServiceEntry.h"

/**
 * Constructor for the ServiceEntry class
 * @param serviceEntryRef - A reference to the json value in the directory
 * @param key - the service code
 */
ServiceEntry::ServiceEntry(Json::Value &serviceEntryRef, std::string key){
    name =      serviceEntryRef["name"].asString();
    id =        key;
    fee =       serviceEntryRef["fee"].asInt();
}

/**
 * Gets a JSON Value representation of the data
 * @return - JSON Value of the service entry
 */
Json::Value ServiceEntry::getJsonValue() {
    Json::Value jsonValue;

    jsonValue["name"] = name;
    jsonValue["id"] = id;
    jsonValue["fee"] = fee;

    return jsonValue;
}
