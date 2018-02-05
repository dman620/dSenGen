/*
Programmer: Derek Mandl (https://github.com/dman620)
date created: Feb 05, 2018
-----------------------------------------------------------------------------------
this is the file that defines the "driving" structure behind the program.
This structure, called a LangTree, will be a tree structure.  Its shape will
be based off of a BNF grammar.  For instance consider the following BNF grammar:

<start> -> <a> | <b> | <c>
<a> -> app | asp | an
<b> -> but | Bon | beut
<c> -> coco | camp | <d> | <c>
<d> -> dangerous | dynamic

The LangTree would look like this:

         ---<start>--------------    ------------
	/           |            \  /            |         
 ----<a>-         -<b>-         -<c>-----        |
/     |  \       /  |  \       /     |    \      |
app asp  an    but  Bon  beut coco  camp   <d>----
                                           /   \
                                    dangerous   dynamic

This is a very roungh drawing of a tree,  but hopefully you can see the general form,
and how it is made based upon the grammar.
Each word enclosed in a < > will be a node in the tree (nonterminal symbol), and each
word without < > will just be a string (terminal symbol).

Each node can point to any ammount of other nodes, and each node can be pointed to by 
any ammount of other nodes.  This will allow you to be able to create recursive LangTrees
without any problem, as long as there will be a chance to exit out of the recursion. 
Obviously an infinite recursive grammar will not yeild anything usefull.
For example, <c> points to <d>, and <d> points back to <c>.  Thus this is a recursive
grammar.  This will not be a problem, however, as long as it also has other paths to 
follow.  The program will be working with random numbers, so it has a random chance 
to follow each path.  Thus, when generating a sentence, it has a chance to recurse,
and it also has a chance to go to one of the two nonterminals there (dangerous/dynamic)
*/

//this is the definition for the node class
struct LangNode{
  //I may implement a dynamic array in the future, but for now I will assume
  //that a reasonable maximum for number of nodes that can be pointed from/to
  //is 20

  //list of nodes that point to this node:
  struct LangNode* fromList[20];
  //list of nodes that this node points to:
  struct LangNode* toList[20];

  //this stores the number of elements in the fromList[]
  char numFrom;
  //this stores the number of elements in the toList[]
  char numTo;
  
  //this stores the name of the nonterminal symbol,
  //not including the < >
  char* name[];
};
