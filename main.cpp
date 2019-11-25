/**
 * Created by Bela, Cody Potter, Corbin Stark, Dan Scott, Forest Pearson, Max VanRaden
 */

#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <catch.hpp>    //Unit Testing library include

#include "Database.h"

int main(int argc, char** argv) {

    Database database("data/sample-db.json");

    int result = Catch::Session().run( argc, argv );

    return result;
}
