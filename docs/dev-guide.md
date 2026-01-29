# Development Guide

This program features four classes MDConverter, StringSetter, LineSetter and TextMDCheck. The program has been optimized to just need an include statement for MDConverter but at the current moment, StringSetter is included to allow for better testing.

## MDConverter

The purpose of this class is to be the main driver for the conversion between markdown and html. This class sports three methods, and two of them are simply testing methods.

The main driver function is compileDoc which takes a single string argument specifying the path to search for the file. This will be the user's only interaction with the program. 

The returnFileText reads in the contents of the markdown file, which is then parsed via StringSetter.

The final method of mdConverter is writeOutToFile that takes in a string and rights to a file we have labeled output.html. Possibly in the future we may choose to add the ability for the user to specify the file name.

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

 ## LineSetter

 This class creates html elements that are later compiled into the StringSetter class and further the output html file.

There is a constructor that possesses no arguments. This sets the iP, hC, and iL bools to false. 

There are 9 html elements that are created using this class. They each have methods called to intialize the variables.

1.  `void bold(int start, int end, string line);` 
2.  `void italics(int start, int end, string line);`
3.  `void monospace(int start, int end, string line);`
4.  `void paragraph(string line);`
5.  `void header(int headers,string lineInput);`
6.  `void list(vector <string> listStrings, bool ordered);`
7.  `void listElement(string std);` 
8.  `void images(string link, string linkDescription, int start, int end);`
9. `void links(string link, string title, int start, int end);`
10. `void hL();`

The start and end indexes are the start of lineInput text that pertains to the html element. For example it would start at the first * and end at the last * for italics.

There are two more methods used. compileLine() creates the html tag syntax for the LineSetter element. This is then called by compileLS for each LineSetter element in the markdown doc. setAllFalse() is a helper method that is called in the constructor setting the bools to false.

The private data memebrss in this class are used in compiling the html document.

1. `bool iP`
2. `bool hC`
3. `bool iL`
4. `int startPos`
5. `int endPos`
6. `string startTag`
7. `string endTag`
8. `string text`
9. `vector <LineSetter> children`

## TextMDCheck

This class is a helper class for StringSetter. The method is called to determine if the text is bold, italics, or monospace. This is abstracted to also be called when creating a paragraph element.

`LineSetter checkMD(bool &inPara, int charIndex, string line);` outputs a LineSetter element if it finds one starting on the charIndex. If it does not it outputs an empty element and sets inPara to true;