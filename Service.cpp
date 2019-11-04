//
// Created by Cody Potter on 11/1/2019.
//

#include "Service.h"

Service::Service(Json::Value& serviceRef, std::string key) {
    id =                key;
    serviceDate =       serviceRef["service date"].asString();
    submissionDate =    serviceRef["submission date"].asString();
    memberID =          serviceRef["member id"].asString();
    providerID =        serviceRef["provider id"].asString();
    serviceCode =       serviceRef["service code"].asString();
    fee =               serviceRef["fee"].asInt();

    std::cout << "service constructor called. ID: " << id << std::endl;
}