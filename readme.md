# Readme:

### Hello, this is the readme for my Sentenge Generator, named dSenGen.

I have begun creating the data types and functions I need to carry out this project
In the future, this will be a sentence generator.

The user will be allowed to create a language grammar (BNF) that the program will parse.  It will then do some stuff and generate a structure that represents the grammar.  I call this structure a Language Tree.  Then it will generate a random sentence in the language defined by the grammar.

The language tree is a structure that is made up of two dynamic arrays of language tree nodes, and a char* containing the symbol name given.

This project is written in, and will be completed in C language.

##### The syntax of grammars accepted by the program shall be as follows:
\<Start\> -> \<NonTerminalName\> | terminalName"  
\<NonTerminalName\> -> terminalName2

Of course you may define as many Terminals and nonterminals as you wish.  The program should be able to handle any possible rule, including recursive rules.  Also you will be able to name the symbols whatever you want.  You will be able to start it with a symbol called \<end\> if you wish.

More information is available in the .c file.

Well, that's about it at this juncture.  What you see is what you get

Dman out
