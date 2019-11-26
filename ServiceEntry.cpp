//
// Created by enjoi on 11/26/2019.
//

#include "ServiceEntry.h"

ServiceEntry::ServiceEntry(Json::Value &serviceEntryRef, std::string key){
    name =      serviceEntryRef["name"].asString();
    id =        key;
    fee =       serviceEntryRef["fee"].asInt();
}

Json::Value ServiceEntry::getJsonValue() {
    Json::Value jsonValue;

    jsonValue["name"] = name;
    jsonValue["id"] = id;
    jsonValue["fee"] = fee;

    return jsonValue;
}
