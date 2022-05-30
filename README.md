# Scanner_Building
Writing a Scanner using an imperative language (C++) for the tokens specified by a pre-defined Regular Expression.

The scanner:
The scanner is for the tokens specified by the regular expression (including production rule for comment) given in page 54 of the text book.
You must use the DFA on page 57 as the basis for designing and implementing your scanner. Note that the DFA does not fully respect the production rule on id (i.e., the DFA will take read and write as id while they should be taken as a token of read and a token of write respectively). So, your scanner returns an ID token only if the id is not read or write. When the id is read or write, your scanner should return the token read and write respectively.

The task:
Here is the task: Write a scanner using an imperative language: C/C++ (in this option, your program must be compilable using gcc or g++.), Java, Python.

Your program must have the scan function. Its precondition is that the current pointer of the input file is NOT at the end of file (EOF). It scans from the current pointer of the input file and stops when either a valid token or invalid token can be decided. In the case of a valid token, scan returns the token type (i.e., the left hand side symbol of the corresponding production rule. E.g.,forproductionruleid -> letter letter∧,thetokentypeofaninput”abc”wouldbe id); otherwise, it returns an error flag. Note here when deciding a token you must use the “longest possible token” rule. Your scanner should also deal with the read and write token correctly.
The scanner takes the name of a text file from the command line. It outputs to the console error if there is any non-valid token in the input file; the list of tokens otherwise.
Your implementation should be based on the automata in on Page 57 of the textbook.
Commandline Invocation: scanner <input file name>
If there is any non-token string in the input file, your program should exit and output to the console only:

          error.
          
Otherwise, your program outputs only the list of tokens in the form of

          (token1, token2, ...).
          
Example Input File: foo.txt with the following content: 
    read
    /* foo
    bar */
    *
    five 5
Example Commandline: scanner foo.txt

Example Output: (read, times, id, number).
Note that your scanner does NOT output the token of comment. In fact, your function scan
should completely ignore all comments in the input. In the example, the next token of times is id, instead of comment.

A More Challenging Task: 

In this task, the input of your program is a file containing the description of an automata,
and a file F2 containing a program.
If there is any non-token string in F2, your program should exit and output to the console
only:
          error.
Otherwise, your program outputs only the list of tokens in the form of 
          (token1, token2, ...).
          
You must have a scan function whose input is an opened file, and output is the longest possible token type of the token starting from the current point of the input file. In this question, we talk about token type only. If you are interested in working out the token content for each token, the content should never contain white spaces separating the token from other tokens or comment. 
Remember, in this project, we don’t take comment as a token. We simply ignore them when recognizing tokens in an input program. For example, input /*123*/abc has only one token whose content is abc.

The file containing the automata is a text file with 6 sets in order:

    {c1,c2,...,ci,...} 
    {s1,s2,...,sj,...} 
    {i1}
    {f1,f2...} 
    {(si,ck,sj),...} 
    {(f1,t1),(f2,t2),...}
    
Every set starts with { and ends with }. The first set lists all characters that a programmer can use EXCEPT the THREE characters ’{’, ’}’ and ’,’. The characters are separated by ’,’. The second contains all states of the automata which are separated by ’,’. Each state is a number with possibly more than two digits. The third set has a single element inside it which is the initial state of the automata. The fourth set includes all final states. The fifth is a set of triples each of which is of the format (si, ck, sj), where ck can be any member from the first set, that represents the transition that the character ck brings the automata from state si to state sj. The last set indicates the token type of each final state. Specifically, an element (fj, tj) of the set means that the token type of the final state f j is tj which is a sequence of letters.

The following is an example of a file that represents the automata in the picture below.

    {a,A}
    {1,2,3}
    {1}
    {2,3} 
    {(1,a,2),(2,a,2),(1,A,3),(3,A,3)} 
    {(3,captal),(2,low)}
    
In this automata, only characters a and A are allowed. There are 3 states: 1, 2, and 3. 1 is the initial state; both 2 and 3 are final states. State 2 and 3 represent token type capital and low respectively.
