//
//
//      COMPILE THIS FILE WITH THE COMMAND: cl -EHsc testing_the_test_library.cpp
//      (or if you use Linux/Mac, g++ -std=c+11 -Wall testing_the_test_library.cpp)
//
//

#define CATCH_CONFIG_RUNNER
#include "../include/catch.hpp"
#include "../include/json/json.h"
#include "../Database.h"
Database TEST_DB("../data/test-db.json");

int main (int argc, char* argv[] ) {
    int result = Catch::Session().run(argc, argv);
    return result;
}

TEST_CASE( "Update database and check for correct member data in map", "[database]") {
    // setup
    std::string newMemberID = TEST_DB.addMember("TestName", "TestStreet", "TestCity", "TestState", "TestZip");

    // method to test
    TEST_DB.update();

    // running tests
    REQUIRE( TEST_DB.members.at(newMemberID).name == "TestName" );
    REQUIRE( TEST_DB.members.at(newMemberID).street == "TestStreet" );
    REQUIRE( TEST_DB.members.at(newMemberID).city == "TestCity" );
    REQUIRE( TEST_DB.members.at(newMemberID).zip == "TestZip" );
    REQUIRE( TEST_DB.members.at(newMemberID).id == newMemberID );
    REQUIRE( TEST_DB.members.at(newMemberID).isValid );

    TEST_DB.members.erase(newMemberID);
    TEST_DB.update();

}

TEST_CASE( "Update database and check for correct provider data in map", "[database]") {
    // setup
    std::string newProviderID = TEST_DB.addProvider("TestName", "TestStreet", "TestCity", "TestState", "TestZip");

    // method to test
    TEST_DB.update();

    // running tests
    REQUIRE( TEST_DB.providers.at(newProviderID).name == "TestName" );
    REQUIRE( TEST_DB.providers.at(newProviderID).street == "TestStreet" );
    REQUIRE( TEST_DB.providers.at(newProviderID).city == "TestCity" );
    REQUIRE( TEST_DB.providers.at(newProviderID).zip == "TestZip" );
    REQUIRE( TEST_DB.providers.at(newProviderID).id == newProviderID );

    TEST_DB.providers.erase(newProviderID);
    TEST_DB.update();

}

TEST_CASE( "Update database and check for correct service data in map", "[database]") {
    // setup
    std::string newServiceID = TEST_DB.addService("TestServiceDate", "TestSubmissionDate", "TestMemberID", "TestProviderID", "TestServiceCode", 99);
    TEST_DB.update();

    REQUIRE( TEST_DB.services.at(newServiceID).serviceDate == "TestServiceDate" );
    REQUIRE( TEST_DB.services.at(newServiceID).submissionDate == "TestSubmissionDate" );
    REQUIRE( TEST_DB.services.at(newServiceID).memberID == "TestMemberID" );
    REQUIRE( TEST_DB.services.at(newServiceID).providerID == "TestProviderID" );
    REQUIRE( TEST_DB.services.at(newServiceID).serviceCode == "TestServiceCode" );
    REQUIRE( TEST_DB.services.at(newServiceID).fee == 99 );

    TEST_DB.services.erase(newServiceID);
    TEST_DB.update();
}

TEST_CASE( "Update database and check for correct member data in datafile", "[database]") {
    // setup
    std::string newMemberID = TEST_DB.addMember("TestName", "TestStreet", "TestCity", "TestState", "TestZip");

    // method to test
    TEST_DB.update();

    std::ifstream ifs("../data/test-db.json");
    Json::Reader reader;
    Json::Value rootRef;
    reader.parse(ifs, rootRef);


    // running tests
    REQUIRE( rootRef["members"][newMemberID]["name"] == "TestName" );
    REQUIRE( rootRef["members"][newMemberID]["street"] == "TestStreet" );
    REQUIRE( rootRef["members"][newMemberID]["city"] == "TestCity" );
    REQUIRE( rootRef["members"][newMemberID]["state"] == "TestState" );
    REQUIRE( rootRef["members"][newMemberID]["zip"] == "TestZip" );
    REQUIRE( rootRef["members"][newMemberID]["id"] == newMemberID );
    REQUIRE( rootRef["members"][newMemberID]["isValid"] == true );

    TEST_DB.members.erase(newMemberID);
    TEST_DB.update();
}
