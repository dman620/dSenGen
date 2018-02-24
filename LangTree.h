#include <stdlib.h> //u_int8_t 8 bit unsigned int type


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

An example of a nonproductive recursive grammar:
<start> -> <end>
<end> -> <start>
as long as you avoid something like this, you'll be fine.
<start> -> <end>
<end> -> <start> | end
is a productive grammar because there is a chance for <end> to go to a terminal symbol.
*/


//the ammount of elements to extend an array by
//see: void extendArray()
#define EXTEND_SIZE 20;


//this is the definition for the node class
struct LangNode{
  //Dynamic array of LangNodes
  struct NodeArray{
    struct LangNode* nodes;
    size_t size;
    size_t used;
  } NodeArray;
  

  //dynamic array of nodes that point to this node:
  struct NodeArray fromList;
  //dynamic array of nodes that this node points to:
  struct NodeArray toList;

  //this stores the name of the nonterminal symbol,
  //not including the < >
  //and if toList is null, then this is the terminal symbol name
  char* name;
};

 //////////////////DYNAMIC ARRAY FUNCTIONS///////////////////////////
//call this to initialize the dynamic array/////////////////////////
void initArray(struct NodeArray a, size_t initSize){
  a.nodes = (struct LangNode*)malloc(initSize * sizeof(struct LangNode));
  a.size = initSize;
  a.used = 0;
}
//call this to insert an element into the array.  It will allocate
//more memory if needed
void insertNode(struct NodeArray a, struct LangNode element){
  if(a.size == a.used){
    a.size += EXTEND_SIZE;
    a.nodes = realloc(a.nodes, a.size * sizeof(struct LangNode));
  }
  a.nodes[a.used] = element;
  a.used++;
}
//call this to return memmory to the system.  DO NOT FORGET TO CALL THIS
void deleteArray(struct NodeArray a){
  free(a.nodes);
  a.size = 0;
  a.used = 0;
}
///////////////////////END DYNAMIC ARRAY FUNCTIONS/////////////////
