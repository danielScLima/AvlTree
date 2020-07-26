// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "avltree.h"

TEST_CASE( "Testing the insert call in the avl tree", "[single-file]" )
{
	AvlTree avl;
	AVLNode* node50 = avl.insertInterface(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	AVLNode* node40 = avl.insertInterface(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	AVLNode* node60 = avl.insertInterface(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	AVLNode* node35 = avl.insertInterface(35);
	REQUIRE( node35 != nullptr);
	REQUIRE( node35->data == 35 );
	AVLNode* node45 = avl.insertInterface(45);
	REQUIRE( node45 != nullptr);
	REQUIRE( node45->data == 45 );
	
	AVLNode* node55 = avl.insertInterface(55);
	REQUIRE( node55 != nullptr);
	REQUIRE( node55->data == 55 );
	AVLNode* node65 = avl.insertInterface(65);
	REQUIRE( node65 != nullptr);
	REQUIRE( node65->data == 65 );
	
	REQUIRE( avl.getRoot()->data == 50 );
	REQUIRE( node50->data == 50 );
	
	REQUIRE( node50->left->data == 40 );
	REQUIRE( node50->right->data == 60 );
	
	REQUIRE( node40->left->data == 35 );
	REQUIRE( node40->right->data == 45 );
	
	REQUIRE( node60->left->data == 55 );
	REQUIRE( node60->right->data == 65 );
}

TEST_CASE( "Testing the remove in the binary tree", "[single-file]" )
{
	AvlTree avl;
	AVLNode* node50 = avl.insertInterface(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	AVLNode* node40 = avl.insertInterface(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	AVLNode* node60 = avl.insertInterface(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	REQUIRE( avl.getRoot()->data == 50 );
	REQUIRE( node50->data == 50 );
	
	REQUIRE( node50->left->data == 40 );
	REQUIRE( node50->right->data == 60 );
	
	AVLNode* rem = avl.removeInterface(40);
	REQUIRE( rem != nullptr );
	REQUIRE( rem->data == 40 );
	REQUIRE( avl.getRoot()->left == nullptr );
	delete rem;
	
	rem = avl.removeInterface(60);
	REQUIRE( rem != nullptr );
	REQUIRE( rem->data == 60 );
	REQUIRE( avl.getRoot()->right == nullptr );
	delete rem;
	
	rem = avl.removeInterface(50);
	REQUIRE( rem != nullptr );
	REQUIRE( rem->data == 50 );
	REQUIRE( avl.getRoot() == nullptr );
	delete rem;
}

TEST_CASE( "Testing the remove call in the binary tree in a second case", "[single-file]" )
{
	AvlTree avl;
	AVLNode* node50 = avl.insertInterface(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	AVLNode* node40 = avl.insertInterface(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	AVLNode* node60 = avl.insertInterface(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	REQUIRE( avl.getRoot()->data == 50 );
	REQUIRE( node50->data == 50 );
	
	REQUIRE( node50->left->data == 40 );
	REQUIRE( node50->right->data == 60 );
	
	AVLNode* rem = avl.removeInterface(50);
	REQUIRE( rem != nullptr );
	REQUIRE( rem->data == 50 );
	REQUIRE( avl.getRoot()->right != nullptr );
	REQUIRE( avl.getRoot()->right->data == 60 );
	delete rem;
	
	REQUIRE( avl.getRoot() != nullptr );
	REQUIRE( avl.getRoot()->data == 40 );
	REQUIRE( avl.getRoot()->left == nullptr );
	
}

TEST_CASE( "Testing the search call in the binary tree", "[single-file]" )
{
	AvlTree avl;
	AVLNode* node50 = avl.insertInterface(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	AVLNode* node40 = avl.insertInterface(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	AVLNode* node60 = avl.insertInterface(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	REQUIRE( avl.getRoot()->data == 50 );
	REQUIRE( node50->data == 50 );
	
	REQUIRE( node50->left->data == 40 );
	REQUIRE( node50->right->data == 60 );
	
	REQUIRE( avl.search(50));
	REQUIRE( avl.search(40));
	REQUIRE( avl.search(60));
}

TEST_CASE( "Testing in level order traversal", "[single-file]" )
{
	AvlTree avl;
	AVLNode* node50 = avl.insertInterface(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	AVLNode* node40 = avl.insertInterface(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	AVLNode* node60 = avl.insertInterface(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	AVLNode* node35 = avl.insertInterface(35);
	REQUIRE( node35 != nullptr);
	REQUIRE( node35->data == 35 );
	AVLNode* node45 = avl.insertInterface(45);
	REQUIRE( node45 != nullptr);
	REQUIRE( node45->data == 45 );
	
	AVLNode* node55 = avl.insertInterface(55);
	REQUIRE( node55 != nullptr);
	REQUIRE( node55->data == 55 );
	AVLNode* node65 = avl.insertInterface(65);
	REQUIRE( node65 != nullptr);
	REQUIRE( node65->data == 65 );
	
	std::string ret = avl.InLevelOrder();
	std::string strMustbe = "50 40 60 35 45 55 65 ";
	REQUIRE(ret.compare(strMustbe) == 0);
}

TEST_CASE( "Testing pre order traversal", "[single-file]" )
{
	AvlTree avl;
	AVLNode* node50 = avl.insertInterface(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	AVLNode* node40 = avl.insertInterface(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	AVLNode* node60 = avl.insertInterface(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	AVLNode* node35 = avl.insertInterface(35);
	REQUIRE( node35 != nullptr);
	REQUIRE( node35->data == 35 );
	AVLNode* node45 = avl.insertInterface(45);
	REQUIRE( node45 != nullptr);
	REQUIRE( node45->data == 45 );
	
	AVLNode* node55 = avl.insertInterface(55);
	REQUIRE( node55 != nullptr);
	REQUIRE( node55->data == 55 );
	AVLNode* node65 = avl.insertInterface(65);
	REQUIRE( node65 != nullptr);
	REQUIRE( node65->data == 65 );
	
	std::string ret = avl.preOrder();
	std::string strMustbe = "50 40 35 45 60 55 65 ";
	REQUIRE(ret.compare(strMustbe) == 0);
}

TEST_CASE( "Testing in order traversal", "[single-file]" )
{
	AvlTree avl;
	AVLNode* node50 = avl.insertInterface(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	AVLNode* node40 = avl.insertInterface(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	AVLNode* node60 = avl.insertInterface(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	AVLNode* node35 = avl.insertInterface(35);
	REQUIRE( node35 != nullptr);
	REQUIRE( node35->data == 35 );
	AVLNode* node45 = avl.insertInterface(45);
	REQUIRE( node45 != nullptr);
	REQUIRE( node45->data == 45 );
	
	AVLNode* node55 = avl.insertInterface(55);
	REQUIRE( node55 != nullptr);
	REQUIRE( node55->data == 55 );
	AVLNode* node65 = avl.insertInterface(65);
	REQUIRE( node65 != nullptr);
	REQUIRE( node65->data == 65 );
	
	std::string ret = avl.inOrder();
	std::string strMustbe = "35 40 45 50 55 60 65 ";
	REQUIRE(ret.compare(strMustbe) == 0);
}

TEST_CASE( "Testing pos order traversal", "[single-file]" )
{
	AvlTree avl;
	AVLNode* node50 = avl.insertInterface(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	AVLNode* node40 = avl.insertInterface(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	AVLNode* node60 = avl.insertInterface(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	AVLNode* node35 = avl.insertInterface(35);
	REQUIRE( node35 != nullptr);
	REQUIRE( node35->data == 35 );
	AVLNode* node45 = avl.insertInterface(45);
	REQUIRE( node45 != nullptr);
	REQUIRE( node45->data == 45 );
	
	AVLNode* node55 = avl.insertInterface(55);
	REQUIRE( node55 != nullptr);
	REQUIRE( node55->data == 55 );
	AVLNode* node65 = avl.insertInterface(65);
	REQUIRE( node65 != nullptr);
	REQUIRE( node65->data == 65 );
	
	std::string ret = avl.posOrder();
	std::string strMustbe = "35 45 40 55 65 60 50 ";
	REQUIRE(ret.compare(strMustbe) == 0);
}

TEST_CASE( "Testing the insert call of a duplicated entry in the binary tree", "[single-file]" )
{
	AvlTree avl;
	REQUIRE(avl.insertInterface(50) != nullptr);
	REQUIRE(avl.insertInterface(60) != nullptr);
	REQUIRE(avl.insertInterface(70) != nullptr);
	
	REQUIRE(avl.insertInterface(50) == nullptr);
	REQUIRE(avl.insertInterface(60) == nullptr);
	REQUIRE(avl.insertInterface(70) == nullptr);
}
