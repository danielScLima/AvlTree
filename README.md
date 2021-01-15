AVL Tree
====================
Build with Travis: [![Build Status](https://www.travis-ci.com/danielScLima/AvlTree.svg?branch=master)](https://www.travis-ci.com/danielScLima/AvlTree)

This repository has a project with the implementation of a AVL Tree.

It is written in C++.

The code of the AVL Tree is independent of platform.

Is has two possible main files:

* [Codes](#markdown-header)
	* [A main that triggers unit test;](#markdown-header-emphasis)

	* [A Qt project to manage the AVL Tree (With Gui).](#markdown-header-strikethrough)
	
The library used to make the Unit Test is the Catch v2.12.3. The code is already in this repository.

The Qt project generates images of the AVL Tree, using the lib Graphviz.
Install this lib in your computer for you to be able to create such images.

The code was written containing the Doxygen documentation.

- - -

You have several options to build the project: 
====================

* [Build tools](#markdown-header)
	* [Makefile (using the file named MakefileGeneral);](#markdown-header-emphasis)
	* [CMake.](#markdown-header-emphasis)
	* [Qt Project (With QMake).](#markdown-header-emphasis)

The project has no leaks (Fully tested with Valgrind).

All the unit tests are ok.

- - -

The functionalities available are: 
====================

* [Functionalities](#markdown-header)
	* [Insert;](#markdown-header-emphasis)
	* [Search;](#markdown-header-emphasis)	
	* [Remove;](#markdown-header-emphasis)
	* [In-order traversal;](#markdown-header-emphasis)
	* [Pos-order traversal;](#markdown-header-emphasis)
	* [Pre-order traversal;](#markdown-header-emphasis)
	* [In-level traversal;](#markdown-header-emphasis)
	
- - -

Sample images: 
====================

## Type of view 1

![Alt text](images/sample1.png)

## Type of view 2

![Alt text](images/sample2.png)

Rotations in images: 
====================

## Left Rotation
### Inserting 50
![Alt text](images/leftrot/1.png)
### Inserting 60
![Alt text](images/leftrot/2.png)
### Inserting 70
![Alt text](images/leftrot/3.png)

## Right Rotation
### Inserting 50
![Alt text](images/rightrot/1.png)
### Inserting 40
![Alt text](images/rightrot/2.png)
### Inserting 30
![Alt text](images/rightrot/3.png)

## Left-right Rotation
### Inserting 50
![Alt text](images/leftrightrot/1.png)
### Inserting 40
![Alt text](images/leftrightrot/2.png)
### Inserting 45
![Alt text](images/leftrightrot/3.png)

## Right-left Rotation
### Inserting 50
![Alt text](images/rightleftrot/1.png)
### Inserting 60
![Alt text](images/rightleftrot/2.png)
### Inserting 55
![Alt text](images/rightleftrot/3.png)




Qt gui project: 
====================
The qt gui application gui is shown below:

## Type of view 1
![Alt text](images/guisample1.png)

## Type of view 2
![Alt text](images/guisample2.png)


Pre-order: 
====================

![Alt text](images/preorder.png)

In-order: 
====================

![Alt text](images/inorder.png)

Pos-order: 
====================

![Alt text](images/posorder.png)

In-level: 
====================

![Alt text](images/inlevel.png)

