#include <iostream>
#define CATCH_CONFIG_NO_POSIX_SIGNALS
//#define CATCH_CONFIG_MAIN  
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
using namespace std;
int main(){
	Catch :: Session().run();
	return 0;
}
//--
TEST_CASE("Test Template")  
{ 
	REQUIRE(100 == 100); 
}
TEST_CASE("Priting Out Text")
{
	string text;
	text = "#Sample title \n This is a paragraph \n\n This is ** another ** ... \n"
	REQUIRE(Text == )
}