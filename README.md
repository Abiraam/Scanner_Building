# Scanner_Building
Writing a Scanner using an imperative language (C++) for the tokens specified by a pre-defined Regular Expression.

The scanner:
The scanner is for the tokens specified by the regular expression (including production rule for comment) given in page 54 of the text book.
You must use the DFA on page 57 as the basis for designing and implementing your scanner. Note that the DFA does not fully respect the production rule on id (i.e., the DFA will take read and write as id while they should be taken as a token of read and a token of write respectively). So, your scanner returns an ID token only if the id is not read or write. When the id is read or write, your scanner should return the token read and write respectively.
