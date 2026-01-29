# Development Guide

This program features four classes MDConverter, StringSetter, LineSetter and TextMDCheck. The program has been optimized to just need an include statement for MDConverter but at the current moment, StringSetter is included to allow for better testing.

## MDConverter

The purpose of this class is to be the main driver for the conversion between markdown and html. This class sports three methods, and two of them are simply testing methods.

The main driver function is compileDoc which takes a single string argument specifying the path to search for the file. This will be the user's only interaction with the program. 

The returnFileText reads in the contents of the markdown file, which is then parsed via StringSetter.

The final method of mdConverter is writeOutToFile that takes in a string and rights to a file we have labeled demo-test.html. Possibly in the future we may choose to add the ability for the user to specify the file name.

## StringSetter

This class is the interface that creates the entire html document, parsing the file into it's html components and then storing the finish product in outputText, a private attribute of StringSetter.

There are two other public methods (htmlStartLabeling and htmlEndingLabeling) that both create the html start and end text.

One final public helper method of the StringSetter class is findEndtag. This function takes in a string, a tag to search for and the position of it's first occurance. This allows for the function to search for an end tag in the situation that the user did not include one and instead used the asterisk or other character as a character in a paragraph. 

There is one private method that is called to compile the entirety of LSElements. These are all the elements created when parsing the MD text. This is then stored into outputText for future writing and additions.

There are a host of variables included as private data members of StringSetter.

 . `bool inParagraph;` holds if the block we are currently parsing is a paragraph
 . `bool inList;` holds if the block we are currently parsing is a list
 . `bool ordered;` holds if the block we are currently parsing is an ordered list
 . `string outputText;` ending text in html format
 . `vector <LineSetter> LSElements;` all elements of the current html doc