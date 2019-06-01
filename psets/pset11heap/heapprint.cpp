/*Include the following line at the top of your every file with your name signed.
 On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: lee yeeun*/

/**
* File: heapprint.cpp
*	converts a heap data structure in an array into a complete
*	binary tree and invokes treeprint() in treeprint.cpp
*
* @Author	Youngsup Kim, idebtor@gmail.com
* 05/05/2016	Creation
* 05/05/2019	Simplified using std::queue
*
* Algorithm to build a binary tree(BT) from a complete binary tree(CBT).
* 0. If the CBT size is zero, return a nullptr.
* 1. initialize the tree (BT) with the first key from CBT
* 2. queue the tree root node.
* 3. Loop until the queue is empty
*    Get a next key from the CBT
*    Get the front node in the queue.
*    If the left child of this front node doesn¡¯t exist,
*        set the left child as the new node.
*	 else if the right child of this front node doesn¡¯t exist,
*        set the right child as the new node.
* 4. If the front node has both the left child and right child,
*        dequeue() it.
* 5. enqueue() the new node.
*/

#include <iostream>
#include <cassert>
#include <queue>
#include "heap.h"
#include "treenode.h"
#include <math.h>


void treeprint(tree t);

void heapprint(heap p) {
	DPRINT(std::cout << ">heapprint\n";);
	if (empty(p)) return;

	//std::cout << "your code here\n";
    tree root = new TreeNode(p->nodes[1]); 
    tree temp = root;
    std::queue<tree> que;  // using stl
    que.push(root);
    
    int i = 1;
    
    while(!que.empty()){
        root=que.front();

        if (i < p->N)
        {
            root->left = new TreeNode(p->nodes[++i]); //EnQueue
            que.push(root->left);
        }
        if(i < p->N)
        {
            root->right = new TreeNode(p->nodes[++i]); //EnQueue
            que.push(root->right);
        }
        que.pop();
      //  root=que.front();

       // treeprint(root);

    }
    
    
    /*
     A.Get a next key from the CBT and make a new node
     
     B. Get the front node in the queue.
     C. If the left child of this front node doesnÕt exist,
     set the left child as the new node.
     else if the right child of this front node doesnÕt exist,
     set the right child as the new node.
     D. If the front node has both the left child and right child, dequeue it.
     E. enqueue the new node.
     */
    /*
    while(!que.empty()){
        temp=que.front();
        que.pop();
        v.push_back(temp->key);  //process node
        
        if(temp->left)
            que.push(temp->left); //EnQueue
        if(temp->right)
            que.push(temp->right); //EnQueue
        
    }
    */
    root = temp;
    treeprint(root);
    //tree root = *p;

	// treeprint_levelorder(root);  // may use this instead of heapprint_levelorder()
	DPRINT(std::cout << "<heapprint\n";);
}

void heapprint_levelorder(heap p) {
	DPRINT(std::cout << ">heapprint_levelorder\n";);
	if (empty(p)) return;
	int N = size(p);                   // number of nodes, N is the last index
	int max_level = height(N);         // total number of levels, starting at 1
	int i = 1;
	while (i <= N) {
		for (int level = 0; level < max_level; level++) {
			int n = (int)pow(2, level);            // n is max nodes per level
			for (int k = 0; k < n && i <= N; k++)   // disply one level
				std::cout << p->nodes[i++] << " ";
			std::cout << std::endl;
		}
	}
	DPRINT(std::cout << "<heapprint_levelorder\n";);
}
