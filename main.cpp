#include <iostream>
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN   
#include "catch.hpp"
using namespace std;
int main()
{
	Catch :: Session().run();
return 0;
}
//--
TEST_CASE("Test Template")  
{ 
	REQUIRE(100 == 100); 
}