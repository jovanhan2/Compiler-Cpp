Documentation
=============


AST
===

Overview Diagram
----------------

![my-ast.png](https://cloud.githubusercontent.com/assets/2521843/24332734/d7333e6e-1243-11e7-8027-0e56c0977a61.png)

Description
-----------

### Top Level
`Function List` or `Declaration List`.

The reason for this is that statements will be in functions, whilst declarations can occur outside. (*globalvariables*)

### Function List
Contains a `FunctionDeclaration` or a `Function`, both of which have a parameterList.

### Function
A `Function` will have a `statementList` or `declarationList`.

The main reason I split up the declaration and statements is because in C89/90 all variables must be declared before being used in statements.
### DeclarationList
Contains any number of `declarations`

Each `declaration` will have a `type` and `variable id`
* `Type` : int,char - etc
* 'Variable id' : Any variable

A 'declaration' also may contain a `Assignment Op` and a `EXPR` *(int x = 5 + 5;)*

### StatementList
Any number of `Statements`.

A `Statement` can be :
* `While,If,For Loops`
* `Return statement`
* `Function Call`
* `Assignment`

Basically, **anything** that can be written inside a function

### While,If,For Loops
Contains `Condition` and `StatementList`

`Condition` contains
* `COMPARITOR` : EXPR cond-OP EXPR | EXPR (*expression*)
* `COMPARE` : COMPARE cond-OP COMPARITOR  | COMPARITOR

whereby `cond-Op` are conditional operators (<,!=,==, etc)

`StatementList`will contain the code that will be run for each branch of the if, while, for loops.

### Expressions
`EXPR` can be any number of `Variables`, `Numbers` and `operators`

`Operators` can be + , - , / , *


Strengths
---------

### Strength 1

Extending the tree - adding new node types. It's incredibly easy to add new nodes as the tree is based on an OOP style. All that is required is creating a new class, and writing the required virtual functions. This enables extensibility and ease of modification.

### Strength 2

Modularity in code. Splitting up the classes ensures that even though one particular class doesn't work the rest of the code can still be compiled. This makes it easy to test each class and debug where an error might occur.

Limitations
-----------

### Limitation 1

Extending the tree - adding new operations. Because I've utilised virtual functions in an OOP style, for example adding a function to output ARM assembly will require changing every **single** class and adding the required code.

### Limitation 2
Because of the OOP style, there are huge amounts of typing compared to other styles. This is because every class needs to have their own constructors, members and the required virtual function, making it a hassle to type.

Variable binding
================

General approach
----------------

First I used created a helper class which would contain all global variables and would be in charge of mappings and allocation. Then I passed the class pointer into all of my print-assembly virtual functions, enabling me to access all of the required variables anywhere.

The class contains functions for managing the registers, and all classes can use getters and setters to modify the register allocated. For register allocation I first set the register to a certain number depending on the class, then each time a variable used a register I would increment to the next register.

* For example, the parameter class would start with $4, whereas I set the arithmetic class to use $8 onwards.

* Furthermore all variables declared are pushed to the stack, along with the frame pointer and return address.

For variable bindings, I used a `map` data structure in my helper class with provided functions for looking up/adding to the map. All parameters would be declared as variables, only with an additional store instruction. The map would then store the variable ID and the offset in the stack. The stack is always set to 25 bytes, allocated every function call.

Strengths
---------
### Strength 1
By having every variable/parameter saved to stack it was easy to perform operations as I did not have to worry about overriding registers. This was key, especially for the extremely complex statements.

### Strength 2
By having a helper class, I essentially had full control of global variables that I could use throughout my code. This made it easy to set flags (for example, if it's `return`) by using members of the helper class, then checking elsewhere if it was implemented.

Limitations
-----------
### Limitation 1
Without register allocation, my method will become incorrect once extremely complex statements are used. Every arithmetic operation completed results in an increment to the next register, and if the statement is too long the registers will start to override existing values *($26-$31)* or use non-existing registers *(>$31)*

### Limitation 2
By relying completely on the stack, there is always the chance of stack overflow as I have defined the stack size to be always 25 bytes. This will happen if there are too many variables/parameters/operations/function calls within the function.

Reflection
==========

Strengths
---------

### Strength 1

Arithmetic operations. Nested and complex operations almost always work because each time an operation occurs the next register is used to store the result. This ensures that no values are overwritten.

### Strength 2
Loops. Every label is completely unique, ensuring that there is no ambiguity in branches. By having the same basic branch placement for each `if` and `while`, it is much easier to implement `if-else` and `For` by simply building on top of the existing branches.

Scope for Improvement
---------------------

_What parts of your compiler do you think could be improved?_

- _This is not looking for things like "It should support more C constructs". What
  would you need to do or change in order to support those things?_

### Improvement 1

Register allocation. Having a map that can keep track which registers are used would enable the compiler to re-use registers.  The map would contain all registers, and a boolean value to flag if it is being used. This would be placed into the helper class which is passed throughout the program, enabling every function to have access to the map.


### Improvement 2

Stack. Not saving everything to the stack. By implementing register allocation I can utilise the registers instead. Furthermore, stack allocation can be dynamic instead of static by having a function that counts the number of statements and relevant items (function calls, statements, etc).


Functionality (not assessed)
============================

Which of these features does your compiler support (insert
an `x` to check a box):

* 1 - [x] Local variables
* 2 - [x] Integer arithmetic
* 3 - [x] While
* 4 - [x] IfElse
* 5 - [x] For
* 6 - [x] Function calls
* 7 - [ ] Arrays
* 8 - [ ] Pointers
* 9 - [ ] Strings
* 10 - [ ] Structures
* 11 - [ ] Floating-point

Note that all features will be tested, regardless of what
appears here. This is documentation of what you expect to work,
versus what doesn't work.


Feedback (not assessed)
=======================

_What aspects of your compiler would you like feedback on.
Be specific, as "what could I have done differently" is
too general to answer._

### Feedback 1

Was there a simpler way to keep track of the registers for each of the arithmetic operation (especially nested)?

### Feedback 2

Would it have been better to have the more hierarchal structure in the grammar instead of having many classes as the base class?
