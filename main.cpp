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
TEST_CASE("File Read Test")
{
	MDConverter T1;
	string correctResult ="This is the first line\nThis is the second line\nThis is the third line\nThis is the fourth line\n";
	string testCase1 = T1.returnFileText("markdown-sample.md");
	REQUIRE(testCase1 == correctResult); 
}
TEST_CASE("write Out To FIle")
{
	MDConverter T2;
	string correctResult2 = "This is our first text with only one line of text\n This is the second line of text";
	T2.writeOutToFile("This is our first text with only one line of text\nThis is the second line of text");
 	REQUIRE(true == true); 

}

// TEST_CASE("HTML starting labeling")
// {
// 	StringSetter T1;
// 	string correctResult1 = "<!DOCTYPE html>\n<html>\n<body>\n";
// 	string retVal = T1.htmlStartLabeling();
//  	REQUIRE(retVal == correctResult1); 
// }
TEST_CASE("header test 1")
{
	string input = "###This is header one";
	
	StringSetter s;
	string output1 = "<h3>This is header one</h3>\n";
	string output = s.parse(input);
	REQUIRE(output == "<h3>This is header one</h3>\n");

}
TEST_CASE("bold test 2")
{
	string input = "**some longer text**";
	StringSetter s;
	REQUIRE(s.parse(input) == "<b>some longer text</b>\n");

}
TEST_CASE("italics test")
{
	string input = "*some text*";
	StringSetter s;
	REQUIRE(s.parse(input) == "<em>some text</em>\n");

}
TEST_CASE("italics test 2")
{
	string input = "*some longer text*";
	StringSetter s;
	REQUIRE(s.parse(input) == "<em>some longer text</em>\n");

}
TEST_CASE("monospace test")
{
	string input = "`some text`";
	StringSetter s;
	REQUIRE(s.parse(input) == "<code>some text</code>\n");

}
TEST_CASE("monospace test 2")
{
	string input = "`some longer text`";
	StringSetter s;
	REQUIRE(s.parse(input) == "<code>some longer text</code>\n");

}


TEST_CASE("basic paragraph")
{
	string input = "this is a paragraph\n\n";
	StringSetter s;
	REQUIRE(s.parse(input) == "<p>this is a paragraph</p>\n");
}

TEST_CASE("paragraph w/ bold in it")
{
	string input = "this is a **bold** paragraph\n\n";
	StringSetter s;
	REQUIRE(s.parse(input) == "<p>this is a <b>bold</b> paragraph</p>\n");
}

TEST_CASE("DEMO"){
	string filePath = "demo-test.md";

	MDConverter td;
	td.compileDoc(filePath);
	REQUIRE(true == true);
}

TEST_CASE("DEMO 2"){
	string filePath = "markdown-test-mtpl-lines.md";
	MDConverter td;
	td.compileDoc(filePath);
	REQUIRE(true == true);
}

TEST_CASE("unordered list")
{
	string input = "  * this one\n * that one\n * the other one\n";
	StringSetter s;

	string output = s.parse(input);
	REQUIRE(output == "<ul>\n<li>this one</li>\n<li>that one</li>\n<li>the other one</li>\n</ul>\n");
}

TEST_CASE("ordered list")
{
	string input = "  1. this one\n 2. that one\n 3. the other one\n";
	StringSetter s;

	string output = s.parse(input);
	REQUIRE(output == "<ol>\n<li>this one</li>\n<li>that one</li>\n<li>the other one</li>\n</ol>\n");
}
TEST_CASE("Image Test 2")
{
	string input = "and a picture of me here: ![Me](https://avatars.githubusercontent.com/u/934916?v=4)";
	StringSetter Image1;
	string output = Image1.parse(input);
	REQUIRE(output == "<p>and a picture of me here: <img src=\"https://avatars.githubusercontent.com/u/934916?v=4\" alt=\"Me\"></p>\n");
}


TEST_CASE("Link Test")
{
    string input = "[Carthage Website](https://www.carthage.edu/)";
    StringSetter link1;
    string output = link1.parse(input);
    REQUIRE(output == "<a href=\"https://www.carthage.edu/\">Carthage Website</a>\n");
}