#include <iostream>
#include "mdConverter.h"
#define CATCH_CONFIG_NO_POSIX_SIGNALS
//#define CATCH_CONFIG_MAIN  
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
using namespace std;
int main(){
	Catch :: Session().run();
	return 0;
}
TEST_CASE("File Read Test"){
	MDConverter T1;
	string correctResult ="#Sample Titlte \\n This is a paragraph \\n\\n This is **another** paragraph ... \\n";
	string testCase1 = T1.returnFileText("markdown-sample.md");
	REQUIRE(testCase1 == correctResult); 
}
