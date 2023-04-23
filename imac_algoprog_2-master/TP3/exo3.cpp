// #include "tp1.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
#include <time.h>
#include <stack>
#include <queue>
#include <cstdint>

using std::size_t;

struct SearchTreeNode
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    void initNode(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

	void insertNumber(int value) {
        if (value < this->value && this->left == nullptr){
            this->left = new SearchTreeNode(value);
        }
        else if (value > this->value && this->right == nullptr){
            this->right = new SearchTreeNode(value);;
        }
        else if (value > this->left->value){
            this->right->insertNumber(value);
        }
        else this->left->insertNumber(value);
    }

	uint64_t height() const	{

        int heightL = 0;
        int heightR = 0;

        if(this->left==nullptr && this->right==nullptr){
            return 1;
        }
        if(this->left != nullptr){
            heightL = this->left->height();
        }
        if(this->right != nullptr){
            heightR = this->right->height();
        }
        
        return 1+std::max(heightL, heightR);
        
    }

	uint64_t nodesCount() const {
        int heightL = 0;
        int heightR = 0;

        if(this->left==nullptr && this->right==nullptr){
            return 1;
        }
        if(this->left != nullptr){
            heightL = this->left->nodesCount();
        }
        if(this->right != nullptr){
            heightR = this->right->nodesCount();
        }
        
        return 1+heightL+heightR;
	}

	bool isLeaf() const {
        if(this->left==nullptr && this->right==nullptr){
            return true;
        }
       else{
            return false;
       }
        
	}

	void allLeaves(SearchTreeNode* leaves[], uint64_t& leavesCount) {
        if(this->isLeaf()==true){
            leaves[leavesCount]==this;
            leavesCount++;
        }
        // fill leaves array with all leaves of this tree
	}

	void inorderTravel(SearchTreeNode* nodes[], uint64_t& nodesCount) {
        // fils gauche
        if(this->left != nullptr){
              this->left->inorderTravel(nodes, nodesCount);
        }
        // parent
        nodes[nodesCount] == this;
        nodesCount++;
        // fils droit
        if (this->right != nullptr)
        {
            this->right->inorderTravel(nodes, nodesCount);
        }

        // fill nodes array with all nodes with inorder travel
	}

	void preorderTravel(SearchTreeNode* nodes[], uint64_t& nodesCount) {
        // parent
        nodes[nodesCount] == this;
        nodesCount++;
        // fils gauche
        if(this->left != nullptr){
              this->left->inorderTravel(nodes, nodesCount);
        }
        // fils droit
        if (this->right != nullptr)
        {
            this->right->inorderTravel(nodes, nodesCount);
        }
        // fill nodes array with all nodes with preorder travel
	}

	void postorderTravel(SearchTreeNode* nodes[], uint64_t& nodesCount) {
        // fils gauche
        if(this->left != nullptr){
              this->left->inorderTravel(nodes, nodesCount);
        }
        // fils droit
        if (this->right != nullptr)
        {
            this->right->inorderTravel(nodes, nodesCount);
        }
        // parent
        nodes[nodesCount] == this;
        nodesCount++;
        // fill nodes array with all nodes with postorder travel
	}

	SearchTreeNode* find(int value) {
        if(value == this->value){
            return this; 
        }
        else if(this->left != nullptr){
            return this->left->find(value);
        }
        else if(this->right != nullptr){
            return this->right->find(value);
        }
        else{
            return nullptr;
        }
        // find the node containing value
		
	}

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    SearchTreeNode(int value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    SearchTreeNode* get_left_child() const {return left;}
    SearchTreeNode* get_right_child() const {return right;}
};

SearchTreeNode* createNode(int value) {
    return new SearchTreeNode(value);
}

// à changer car j'ai copié mais je voulais juste vérifier que ça fonctionnait rapidement car j'ai envie de dormir
void printTree(SearchTreeNode* root) {
    if (root == NULL)
        return;
    std::cout << root->get_value() << " ";
    printTree(root->get_left_child());
    printTree(root->get_right_child());
}


int main(int argc, char *argv[])
{
	SearchTreeNode* root = createNode(5);
    root->insertNumber(3);
    root->insertNumber(7);
    printTree(root);
}
