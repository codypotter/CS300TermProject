//
// Created by Cody Potter on 11/1/2019.
//

#include "Provider.h"

#include <utility>

//////////////////// Constructors ////////////////////
/**
 * Constructor for Json Value
 * @param providerRef - a reference to a Json::Value with the new provider data (typically from a file)
 * @param key - the key to the corresponding providerRef (typically from a file)
 */
Provider::Provider(Json::Value& providerRef, std::string key) {
    name =      providerRef["name"].asString();
    id =        std::move(key);
    street =    providerRef["street"].asString();
    city =      providerRef["city"].asString();
    state =     providerRef["state"].asString();
    zip =       providerRef["zip"].asString();

    for (const auto & i : providerRef["services"]) {
        services.push_back(i.asString());
    }

}

/**
 * Constructor for User Interface
 * @param newID - new identifier (must be unique; see database.generateNewActorID()
 * @param newName - new provider's name
 * @param newStreet - new provider's street
 * @param newCity - new provider's city
 * @param newState - new provider's state
 * @param newZip - new provider's zip
 */
Provider::Provider(std::string newID, std::string newName, std::string newStreet, std::string newCity, std::string newState, std::string newZip) {
    name =      std::move(newName);
    id =        std::move(newID);
    street =    std::move(newStreet);
    city =      std::move(newCity);
    state =     std::move(newState);
    zip =       std::move(newZip);
}

//////////////////// Getters ////////////////////
/**
 * Generate a JSON::Value from the class instance
 * @return a JSON Value representation of the class
 */
Json::Value Provider::getJsonValue() {
    Json::Value jsonValue;

    jsonValue["name"] = name;
    jsonValue["id"] = id;
    jsonValue["street"] = street;
    jsonValue["city"] = city;
    jsonValue["state"] = state;
    jsonValue["zip"] = zip;

    for (int i = 0; i < services.size(); i++) {
        jsonValue["services"][i] = services[i];
    }

    return jsonValue;
}