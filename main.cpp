#include <iostream>

#define CATCH_CONFIG_NO_POSIX_SIGNALS
// #define CATCH_CONFIG_MAIN  
#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "StringSetter.h"
#include "mdConverter.h"

#include <string>

using namespace std;

int main()
{
	Catch :: Session().run();
	return 0;
}
// TEST_CASE("File Read Test")
//{
// 	MDConverter T1;
// 	string correctResult ="This is the first line\nThis is the second line\nThis is the third line\nThis is the fourth line";
// 	string testCase1 = T1.returnFileText("markdown-sample.md");
// 	REQUIRE(testCase1 == correctResult); 
// }
// TEST_CASE("write Out To FIle")
// {
// 	MDConverter T2;
// 	string correctResult2 = "This is our first text with only one line of text\n This is the second line of text";
// 	T2.writeOutToFile("This is our first text with only one line of text\nThis is the second line of text");
//  	REQUIRE(true == true); 

// }

// TEST_CASE("HTML starting labeling")
// {
// 	StringSetter T1;
// 	string correctResult1 = "<!DOCTYPE html>\n<html>\n<body>\n";
// 	string retVal = T1.htmlStartLabeling();
//  	REQUIRE(retVal == correctResult1); 
// }
// TEST_CASE("bold test")
// {
// 	string input = "**some text**";
// 	StringSetter s;
// 	REQUIRE(s.parse(input) == "<b>some text</b>\n");

// }
// TEST_CASE("bold test 2")
// {
// 	string input = "**some longer text**";
// 	StringSetter s;
// 	REQUIRE(s.parse(input) == "<b>some longer text</b>\n");

// }
// TEST_CASE("italics test")
// {
// 	string input = "*some text*";
// 	StringSetter s;
// 	REQUIRE(s.parse(input) == "<em>some text</em>\n");

// }
// TEST_CASE("italics test 2")
// {
// 	string input = "*some longer text*";
// 	StringSetter s;
// 	REQUIRE(s.parse(input) == "<em>some longer text</em>\n");

// }
// TEST_CASE("monospace test")
// {
// 	string input = "`some text`";
// 	StringSetter s;
// 	REQUIRE(s.parse(input) == "<code>some text</code>\n");

// }
// TEST_CASE("monospace test 2")
// {
// 	string input = "`some longer text`";
// 	StringSetter s;
// 	REQUIRE(s.parse(input) == "<code>some longer text</code>\n");
// }
TEST_CASE("header test 1")
{
	string input = "#This is header one";
	StringSetter s;
	REQUIRE(s.parse(input) == "<h1>This is header one</h1>");
}
TEST_CASE("header test 2")
{
	string input = "####This is header four";
	StringSetter s;
	REQUIRE(s.parse(input) == "<h4>This is header four</h4>");
}