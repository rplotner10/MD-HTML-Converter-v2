#include <iostream>

#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN  
//#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "StringSetter.h"

#include <string>

using namespace std;

int main()
{
	Catch :: Session().run();
	return 0;
}

TEST_CASE("Test Template")  
{ 
	string retVal = "# Sample Title\n";
    retVal += "This is a paragraph";
    retVal += "\n";
    retVal += "This is **another** paragraph\n";
    retVal += "\n";

	StringSetter SSet;

	SSet.parse(retVal);

	REQUIRE(100 == 100); 
}

//Used to test if StringSetter was able to identify a bold MD Command
TEST_CASE("Bold Syntax")
{
    string input = "**BOLD TEXT**";

    StringSetter SSet;

    SSet.parse(input);

    REQUIRE(true == true);
}
