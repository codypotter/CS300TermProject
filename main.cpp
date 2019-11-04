#include <iostream>

#include <json/json.h>  //JsonCPP include
#include <catch.hpp>    //Unit Testing library include

#include "Database.h"
#include "utils.h"

int main(int argc, char** argv) {

    Database database("data/sample-db.json");

    database.addMember(Member("one", "Belaman"));

    return 0;
}
