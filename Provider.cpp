//
// Created by Cody Potter on 11/1/2019.
//

#include "Provider.h"

Provider::Provider(Json::Value& providerRef, std::string key) {
    name =      providerRef["name"].asString();
    id =        key;
    street =    providerRef["street"].asString();
    city =      providerRef["city"].asString();
    state =     providerRef["state"].asString();
    zip =       providerRef["zip"].asString();

    for (int i = 0; i < providerRef["services"].size(); i++) {
        services.push_back(providerRef["services"][i].asString());
    }

    std::cout << "provider constructor called. ID: " << id << std::endl;
}