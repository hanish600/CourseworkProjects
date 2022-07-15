#include "HTMLChecker.h"

/*
 * The file checks for errors in a
 * set of html strings using a queue and stack
 */

HTMLChecker::HTMLChecker() {
    self_closing_tags = {
            "<!doctype>", "<area>", "<base>", "<br>", "<col>", "<embed>", "<hr>",
            "<img>", "<input>", "<link>", "<meta>", "<param>", "<source>", "<track>", "<wbr>",
            "<!doctype/>", "<area/>", "<base/>", "<br/>", "<col/>", "<embed/>", "<hr/>",
            "<img/>", "<input/>", "<link/>", "<meta/>", "<param/>", "<source/>", "<track/>", "<wbr/>"
    };
}



/**
 * Takes the path of a html file and loads it into a
 * Queue one word at a time.  The method reads in the file
 * one character at a time, using a state machine with 4
 * states to parse the tags and words into a Queue for later
 * evaluation.
 *
 * @param file_path
 * @return true if the file could be read.
 */
bool HTMLChecker::load(const string &file_path) {
    // open the file and make sure there is something in it.
    fstream file_in(file_path, fstream::in);
    bool is_empty = file_in.peek() == std::ifstream::traits_type::eof();
    if (is_empty) return false;

    string buff = "";            // holds the word or tag string as we build it.
    char character;              // holds the char we read from the file
    State state = whitespace;    // set our initial state to whitespace

    // loop though each char in the file
    while (file_in >> noskipws >> character) {

        if (state == whitespace) {
            if (!isspace(character)) {
                // if you find a < is the start of a tag
                // otherwise its the start of a word
                if (character == '<') state = tag;
                else state = word;
                buff = character;
            }
        } else if (state == tag) {
            // if it's a > we've reached the end of the tag
            if (character == '>') {
                buff += '>';
                state = whitespace;
                // add the tag to the heml elements queue
                html_elements.push(buff);
                buff = "";

            } else if (isspace(character)) {
                // space in the tag means we're looking at attributes
                state = tag_attr;
            } else {
                buff += tolower(character);
            }
        } else if (state == tag_attr) {
            // in the tag attributes ignore everything but the >
            if (character == '>') {
                buff += '>';
                html_elements.push(buff);
                buff = "";
                state = whitespace;
            }
        } else if (state == word) {
            if (isspace(character)) {
                html_elements.push(buff);
                buff = "";
                state = whitespace;
            } else if (character == '<') {
                html_elements.push(buff);
                buff = "";
                state = tag;
                buff += character;
            } else {
                buff += character;
            }
        }
    }
    return true;
}

bool HTMLChecker::isValid() {
    // Obtains html openings
    stack<string> SetsOfStrings;
    // Obtains html closings
    queue<string> StringEnds;
    // Iterates until html_elements are empty
    for (;!html_elements.empty();) {

        // Removes words
        if (html_elements.front()[0]!='<')
        {
            html_elements.pop();
            continue;
        }

        // finds self closing tags
        unordered_set<string>::iterator finder = self_closing_tags.find(html_elements.front());
        if (finder != self_closing_tags.end()) {
            html_elements.pop();
            continue;
        }

        // finds closing tags
        if (html_elements.front()[1] == '/') {
            StringEnds.push(html_elements.front());
            html_elements.pop();
        }

        // finds opening tags
        if (!html_elements.empty()
        && html_elements.front()[0]=='<' && html_elements.front()[1]!='/')
        {
            SetsOfStrings.push(html_elements.front());
            html_elements.pop();
        }

        // Removes any opening and closing tags that are the same
        if (!SetsOfStrings.empty() && !StringEnds.empty())
        {
            // Check the front for the element
            if (SetsOfStrings.top()[1]==StringEnds.front()[2])
            {
                SetsOfStrings.pop();
                StringEnds.pop();
            }
            // Check the back element and swap it for popping
            else if (SetsOfStrings.top()[1]==StringEnds.back()[2])
            {
                StringEnds.front().swap(StringEnds.back());
                StringEnds.pop();
                SetsOfStrings.pop();
            }
        }
    }

    // remove the final set of opening and closing tags if any
    if (!SetsOfStrings.empty() && !StringEnds.empty())
    {
        if (SetsOfStrings.top()[1]==StringEnds.front()[2])
        {
            SetsOfStrings.pop();
            StringEnds.pop();
        }
    }

    // check if there are no more tags.
    if (SetsOfStrings.empty())
    {
        return true;
    }
    return false;
}



