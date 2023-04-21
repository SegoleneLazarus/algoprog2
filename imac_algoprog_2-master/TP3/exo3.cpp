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

	uint height() const	{

        int heightL = 0;
        int heightR = 0;

        if(this->left==nullptr && this->right==nullptr){
            return 1;
        }
        if(this->left != nullptr){
            heightL = this->left.height();
        }
        if(this->right != nullptr){
            heightR = this->right.height();
        }
        
        return 1+std::max(heightL + heightR);
        
    }

	uint nodesCount() const {
        int heightL = 0;
        int heightR = 0;

        if(this->left==nullptr && this->right==nullptr){
            return 1;
        }
        if(this->left != nullptr){
            heightL = this->left.nodesCount();
        }
        if(this->right != nullptr){
            heightR = this->right.nodesCount();
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

	void allLeaves(Node* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree
	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
	}

	void preorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel
	}

	Node* find(int value) {
        // find the node containing value
		return nullptr;
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
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new SearchTreeNode(value);
}

int main(int argc, char *argv[])
{
	
}
