/**
 * Created by Bela, Cody Potter, Corbin Stark, Dan Scott, Forest Pearson, Max VanRaden
 */

#include <iostream>
#include <catch.hpp>    //Unit Testing library include

#include "Database.h"

int main(int argc, char** argv) {

    Database database("data/sample-db.json");

    database.printMembers();
    database.printProviders();
    database.printServices();

    database.addMember("Cody", "Osprey Street", "Beaverton", "OR", "97007");
    database.update();

    database.printMembers();

    return 0;
}
