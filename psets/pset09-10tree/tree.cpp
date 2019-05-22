/*
 On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
 • Signed: 이예은  Section: 02  Student Number: 21800546
 */

/**
* File: tree.cpp, tree.h
* implements a binary tree and/or binary search tree(BST).* and
* AVL(Adelson-Velskii and Landis) tree.
*
* A binary search tree BST is a type of binary tree where the nodes
* are arranged in order: for each node, all elements in its left
* subtree are less to to node and all the elements in its right
* subtree are greater than the node. Many operations are the same
* either in a binary tree or in a binary search tree.
*
* - Some functions work for a binary tree and/or for a BST.
* - The code works on the node structure 'tree' that makes up the tree.
* - The algorithm, typically recursive, that iterates over the tree
* - Using a pointer to a pointer as an argument have been avoided.
*   Instead the function is to return a new root node after an
*   insertion or deletion, then it returns the root node as a
*   returned value.
*
* 04/20/2014	Creation	Youngsup Kim, idebtor@gmail.com
* 04/15/2016	treeprint() added for clearer visualization of tree
* 05/01/2016	Added AVL tree
* 10/20/2016    Switching from/to BST and AVL tree
* 04/02/2019	C++ version, utilized stl::vector and stl::queue partially
*
* Usage:
*	tree root = nullptr;
*   root = insert(root, 5); // the first node is created
*                           // it becomes the root
*   root = insert(root, 7); // a new node is added
*   root = trim(root, 5); // if first node is removed,
*                           // the new root is returned
*/

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include "tree.h"
using namespace std;

void treeprint(tree t);        // print the tree on console graphically

// returns the degree of a node, not a tree
int degree(tree t) {
	int d = 0;
	if (t->left != nullptr) d++;
	if (t->right != nullptr) d++;
	return d;
}

// Compute the max depth of a tree. It is the number of nodes along
// the longest path from the root node down to the farthest leaf node.
// height: 0 (undefined) for empty tree, 1 for root only tree
int height(tree node) {
	if (empty(node)) return 0;
	// compute the depth of each subree and return the larger one.
    
    int left = height(node->left);
    int right = height(node->right);
	//cout << "your code here\n";
    

    return max(left, right) + 1;
}

// Computes the size of the binary tree dyamically by
// traversing the nodes recursively.
int size(tree node) {
	if (node == nullptr) return 0;

	//cout << "your code here\n";
    
    return size(node->left) + size(node->right) + 1;
    
}

bool empty(tree t) {
	return t == nullptr;
}

int value(tree t) {
	if (t != nullptr) return t->key;
	return 0;
}

// frees all nodes while traversing the tree like postorder
tree clear(tree t) {
	if (t == nullptr) return nullptr;

    if((t->left!=nullptr)&&(t->right!=nullptr)){
        //cout << "step 2"<< endl;
        //cout << "now key : "<<t->key<< endl;
        
        t->left = clear(t->left);
        
        assert(t->left == nullptr);
        
        //cout << "step 2-1"<< endl;
        //cout << "now key : "<<t->key<< endl;
    }
    if(t->left==nullptr){
        //cout << "step 3"<< endl;
        //cout << "now key : "<<t->key<< endl;
        
        t->right=clear(t->right);
        assert(t->right == nullptr);
        //cout << "step 3-1"<< endl;
        //cout << "now key : "<<t->key<< endl;
    }
    else if(t->right==nullptr){
        //cout << "step 4"<< endl;
        //cout << "now key : "<<t->key<< endl;

        t->left=clear(t->left);
        assert(t->left == nullptr);
        //cout << "step 4-1"<< endl;
        //cout << "now key : "<<t->key<< endl;
    }
    
    if((t->left==nullptr)&&(t->right==nullptr)) {
        //cout << "step 1"<< endl;
        //cout << "now key : "<<t->key<< endl;
        
        delete t;
        return nullptr;
    }
	return nullptr;
}

// does there exist a node with given key?
// search a key in binary search tree(BST) recursively.
bool contains(tree node, int key) {
    if (node == nullptr) return false;
    
    if (key  == node->key) return true;
    
    if (key  <  node->key)
        return contains(node->left, key);
    
    return contains(node->right, key);
}

// does there exist a node with given key?
// search a key in binary tree(BT) recursively.
bool containsBT(tree node, int key) {
	if (empty(node)) return false;
	if (key == node->key) return true;
	return containsBT(node->left, key) || containsBT(node->right, key);
}

// does there exist a key-value pair with given key?
// search a key in binary search tree(BST) iteratively
bool containsIteration(tree node, int key) {
	if (node == nullptr) return false;
	while (node) {
		if (key == node->key) return true;
		node = key < node->key ? node->left : node->right;
	}
	return false;
}

// returns a node with a key given if found in BST, otherwise nullptr.
tree find(tree node, int key) {
	if (empty(node)) return nullptr;

	if (key == node->key) return node;
	if (key < node->key)
		return find(node->left, key);
	return find(node->right, key);
}

// returns a node with a key given if found in BT, otherwise nullptr.
tree findBT(tree t, int key) {
	if (empty(t)) return nullptr;

	if (key == t->key) {
		cout << "findBT key: " << t->key << endl;
		return t;
	}

	tree node = findBT(t->left, key);
	if (node != nullptr) return node;

	return findBT(t->right, key);
}

// Inserts a new node with the key in given binary tree and
// returns the new node such that client use it properly.
tree grow(tree node, int key) {
	DPRINT(cout << ">grow key=" << key << endl;);
	if (node == nullptr) return new TreeNode(key);

	if (key < node->key)	// recur down the tree
		node->left = grow(node->left, key);
	else if (key > node->key)
		node->right = grow(node->right, key);

	// do nothing, the duplicate key is not allowed
	DPRINT(cout << "<grow returns key=" << node->key << endl;);
	return node;    // eventually returns the original root node
}



///////////////////////////////////////////////////////////////////
// trim
///////////////////////////////////////////////////////////////////
// removes the node with the key in a tree and returns the new root
tree trim(tree root, int key) {
    int num;
	if (root == nullptr) return root;	 // base case
	DPRINT(cout << ">trim: now we are at: " << root->key << endl;);
    if (key < root->key){
        DPRINT(cout << ">trim: step1: "  << endl;);

        root->left = trim(root->left, key);

    } else if (key > root->key) {
        DPRINT(cout << ">trim: step2: "  << endl;);

        root->right = trim(root->right, key);

    } else {
        if (root->left == nullptr) {
            DPRINT(cout << ">trim: step3: "  << endl;);
            
            tree rightnode = root->right;
            delete root;
            //root->right=trim(root->right,key);
            //delete root->right;
            root=rightnode;
            return root;
                    // your code here – trim the right one, return root
        }
        else if (root->right == nullptr) {
            
            tree leftnode = root->left;
            delete root;
            root=leftnode;
            
            //root->left=trim(root->left,key);
            DPRINT(cout << ">trim: step4: "  << endl;);
           // delete root->left;
            return root;
                    // your code here – trim the left one, return root
        }
        else {// two children case
            // get the successor: smallest in right subtree
            DPRINT(cout << ">trim: step5: "  << endl;);
            num = succ(root)->key;
            trim(root,num);
            root->key = num;

            // copy the successor's content to this "root" node
            if((root->left==nullptr)||(root->right==nullptr)){
            DPRINT(cout << ">trim: step6: "  << endl;);

            //trim(root, key);
            }
                        // trim the successor recursively, which has one or no child case
                    } }
    
	//cout << "your code here\n";

	DPRINT(if (root != nullptr) cout << "<trim returns: key=" << root->key << endl;);
	DPRINT(if (root == nullptr) cout << "<trim returns: nullptr)\n";);
	return root;
}
// removes the node with the key in a tree and returns the new root
tree trimplus(tree root, int key) {
    int num;
    if (root == nullptr) return root;     // base case
    DPRINT(cout << ">trim: now we are at: " << root->key << endl;);
    if (key < root->key){
        DPRINT(cout << ">trim: step1: "  << endl;);
        
        root->left = trimplus(root->left, key);
        
    } else if (key > root->key) {
        DPRINT(cout << ">trim: step2: "  << endl;);
        
        root->right = trimplus(root->right, key);
        
    } else {
        if (root->left == nullptr) {
            DPRINT(cout << ">trim: step3: "  << endl;);
            
            tree rightnode = root->right;
            delete root;
            //root->right=trim(root->right,key);
            //delete root->right;
            root=rightnode;
            return root;
            // your code here – trim the right one, return root
        }
        else if (root->right == nullptr) {
            
            tree leftnode = root->left;
            delete root;
            root=leftnode;
            
            //root->left=trim(root->left,key);
            DPRINT(cout << ">trim: step4: "  << endl;);
            // delete root->left;
            return root;
            // your code here – trim the left one, return root
        }
        else {// two children case
            // get the successor: smallest in right subtree
            DPRINT(cout << ">trim: step5: "  << endl;);
            int right_height=height(find(root,key)->right);
            int left_height=height(find(root,key)->left);
            
            cout << "right height : "<< right_height << endl;
            cout << "left height : "<< left_height << endl;


            if(left_height>right_height){
                num=pred(root)->key;
            } else num = succ(root)->key;
            trimplus(root,num);
            root->key = num;
            
            // copy the successor's content to this "root" node
            if((root->left==nullptr)||(root->right==nullptr)){
                DPRINT(cout << ">trim: step6: "  << endl;);
                
                
                //trim(root, key);
            }
            // trim the successor recursively, which has one or no child case
        } }

	DPRINT(if (root != nullptr) cout << "<trimplus returns: key=" << root->key << endl;);
	DPRINT(if (root == nullptr) cout << "<trimplus returns: nullptr)\n";);
	return root;
}

// returns a successor of the tree
tree succ(tree node) {
	if (node != nullptr && node->right != nullptr)
		return minimum(node->right);
	return nullptr;
}

// returns a predeccessor of the tree
tree pred(tree node) {
	if (node != nullptr && node->left != nullptr)
		return maximum(node->left);
	return nullptr;
}

// Given a binary search tree, return the min or max key in the tree.
// Don't need to traverse the entire tree.
tree maximum(tree node) {			// returns max node
    if(node == nullptr || node->right==nullptr) return node;
	//cout << "your code here\n";
	return maximum(node->right);
}

tree minimum(tree node) {			// returns min node
    if(node== nullptr || node->left==nullptr) return node;
    //cout << "your code here\n";
    return minimum(node->left);
}

// Given a binary tree, its node values in inorder are passed
// back through the argument v which is passed by reference. 
void inorder(tree node, vector<int>& v) {
	DPRINT(cout << ">inorder size=" << v.size() << endl;);
	//cout << "your code here\n";
    
    if (node == nullptr) return;
    inorder(node->left,v);
    v.push_back(node->key);
    inorder(node->right,v);
	DPRINT(cout << "<inorder key=" << node->key << endl;);
}

// Given a binary tree, its node values in postorder are passed
// back through the argument v which is passed by reference. 
void postorder(tree node, vector<int>& v) {
	DPRINT(cout << ">postorder size=" << v.size() << endl;);
    
    if (node == nullptr) return;
    
    postorder(node->left,v);
    postorder(node->right,v);
    v.push_back(node->key);

    
	//cout << "your code here\n";
	DPRINT(cout << "<postorder key=" << node->key << endl;);
}

// Given a binary tree, its node values in preorder are passed
// back through the argument v which is passed by reference. 
void preorder(tree node, vector<int>& v) {
	DPRINT(cout << ">preorder size=" << v.size() << endl;);
    if (node == nullptr) return;

    v.push_back(node->key);
    preorder(node->left,v);
    preorder(node->right,v);
    
	//cout << "your code here\n";
	DPRINT(cout << "<preorder key=" << node->key << endl;);
}

// Given a binary tree, its nodes in level-order is passed
// back through the argument v which is passed by reference. 
// Use std::queue to store the nodes during traverse the tree.
void levelorder(tree node, vector<int>& v) {
	DPRINT(cout << ">levelorder";);
    
    queue<tree> que;
    if (!node) return;
    que.push(node);
    tree temp=node;
    while (temp){
        //temp = node;
        que.push(node);

        if(node->left!=nullptr) que.push(node->left);
        if(node->right!=nullptr) que.push(node->right);

        if (que.empty()) return ;

        temp = que.front();

        que.pop();
    
        //3. if its left child is not null, enqueue it.
        //4. if its right child is not null, enqueue it.
        //5. que.pop() – remove the node in the queue.
    }

    
	//cout << "your code here\n";

	DPRINT(cout << "<levelorder size=" << v.size() << endl;);
}

// does this binary tree satisfy symmetric order?
// is the tree rooted at x a BST with all keys between min and max?
// Another solution: Do an inorder traversal of the tree and store
// the node values in an array.If the array is in sorted order,
// its a valid BST otherwise not.
bool _isBST(tree x, int min, int max) {
	if (x == nullptr) return true;
	DPRINT(cout << ">_isBST key=" << x->key << "\t min=" << min << " max=" << max << endl;);

    if((x->key > max)||(x->key < min)) {
        return false;
    }
    
//    int min_right = minimum(x->right)->key-1;
//    int max_left = maximum(x->left)->key+1;
    if( x->right != nullptr && x->left != nullptr ){
        
    }
    return _isBST(x->right, x->key+1, max) && _isBST(x->left, min, x->key-1);
    
	//cout << "your code here\n";

	DPRINT(cout << "<_isBST key=" << x->key << "\t min=" << min << " max=" << max << endl;);
	//return false;
}

// returns true if the tree is a binary search tree, otherwise false.  
bool isBST(tree root) {
	if (empty(root)) return true;

	int min = value(minimum(root));
	int max = value(maximum(root));
	return _isBST(root, min-1, max+1);    // to check the same key add -/+ 1
    
}
 
///////////   testing code  ///////////////////////////////////////
// While doing Inorder traversal, we can keep track of previously
// visited node. If the value of the currently visited node is
// less than the previous value, then tree is not BST.
bool _isBSTinOrder(tree root, tree *prev) {
	// traverse the tree in inorder fashion and keep track of prev node
	if (root == nullptr) return true;

	if (!_isBSTinOrder(root->left, prev)) return false;

	// Allows only distinct valued nodes
	if (*prev != nullptr && root->key <= (*prev)->key) return false;
	*prev = root;
	return _isBSTinOrder(root->right, prev);
}

bool isBSTinOrder(tree root) {
	tree prev = nullptr;
	return _isBSTinOrder(root, &prev);
}
///////////////////////////////////////////////////////////////////


///////////////// stress test - insert, trim ////////////////////
// shuffles an int array contents
void shuffle(int* arr, int N) {
	DPRINT(cout << ">shuffle N=" << N << endl;);
	if (N <= 1) return;
	DPRINT(srand(0));    // for the same sequence of rand() for debugging
	for (int i = 0; i < N; i++) {
		int x = rand() % (N - 1);
		int t = arr[i];
		arr[i] = arr[x];
		arr[x] = t;
	}
	DPRINT(cout << "<shuffled" << endl;);
}

// returns an int array that has randomly mixed numbers
// between start to start + N
void randomN(int* arr, int N, int start) {
	DPRINT(cout << ">random N=" << N << endl;);
	for (int i = 0; i < N; i++)
		arr[i] = start + i;
	shuffle(arr, N);

#ifdef DEBUG
	cout << "randomN: ";
	for (int i = 0; i < N; i++) cout << arr[i] << " ";
	printf("\n");
#endif
	DPRINT(cout << "<random" << endl;);
}

// inserts N numbers of keys in the tree(AVL or BST), based
// on the current menu status.
// If it is empty, the key values to add ranges from 0 to N-1.
// If it is not empty, it ranges from (max+1) to (max+1 + N).
tree growN(tree root, int N, bool AVLtree) { // recode tree.cpp
    int start = empty(root) ? 0 : value(maximum(root)) + 1;
    
    int* arr = new (nothrow) int[N];
    assert(arr != nullptr);
    randomN(arr, N, start);
    
    for (int i = 0; i < N; i++) root = grow(root, arr[i]);
    
    if (AVLtree) root = rebalanceTree(root);
    
    delete[] arr;
    return root;
}

// removes randomly N numbers of nodes in the tree(AVL or BST).
// It gets N node keys from the tree, trim one by one randomly.
tree trimN(tree root, int N, bool AVLtree) {
    vector<int> vec;
    inorder(root, vec);
    shuffle(vec.data(), vec.size());
    int tsize = size(root);
    assert(vec.size() == tsize);   // make sure we've got them all
    int count = N > tsize ? tsize : N;
    for (int i = 0; i < count; i++) root = trim(root, vec[i]);
    if (AVLtree) root = rebalanceTree(root);
    return root;
}

////////////////////////// AVL Tree ///////////////////////////////
bool balanced(tree node) {
	int factor = balanceFactor(node);
	return (factor >= -1 && factor <= 1) ? true : false;
}

// returns the balance factor or (height of left - height of right)
int balanceFactor(tree node) {
	DPRINT(cout << " bf" << endl;);
	if (node == nullptr) return 0;
	int left = height(node->left);
	int right = height(node->right);
	DPRINT(cout << " bf at(" << node->key << "): " << (left - right)
		        << "\t (l=" << left << ", " << "r= " << right << ") \n";);
	return left - right;
}

// returns true if the tree is AVL tree.
// this is a helper function for isAVL().
bool _isAVL(tree root) {
	if (!balanced(root)) return false;
	if (root->left != nullptr && !_isAVL(root->left))  return false;
	if (root->right != nullptr && !_isAVL(root->right)) return false;
	return true;
}
bool isAVL(tree root) {
	if (root == nullptr) return true;
	if (!isBST(root)) return false;
	return _isAVL(root);
}

tree rotateLL(tree node) {
	DPRINT(cout << "\t[LL]case at " << node->key << endl;);
	tree child = node->left;
	node->left = child->right;
	child->right = node;
	return child;
}

tree rotateRR(tree node) {
	DPRINT(cout << "\t[RR]case at " << node->key << endl;);
	tree child = node->right;
	node->right = child->left;
	child->left = node;
	return child;
}

tree rotateLR(tree node) {
	DPRINT(cout << "\t[LR]case at " << node->key << endl;);
	tree child = node->left;
	node->left = rotateRR(child);
	return rotateLL(node);
}

tree rotateRL(tree node) {
	DPRINT(cout << "\t[RL]case at " << node->key << endl;);
	tree child = node->right;
	node->right = rotateLL(child);
	return rotateRR(node);
}

// rebalnces at the node only, not recursively, and
// returns the node that may be different from the input node
tree rebalance(tree node) {
	DPRINT(cout << ">rebalance at:" << node->key << endl;);
    
        int bf = balanceFactor(node);
        if (bf >= 2) {
            if (balanceFactor(node->left) >= 1)
                node = rotateLL(node);
            else
                node = rotateLR(node);
            }
            else if (bf <= -2) {
                // LL // LR
                if (balanceFactor(node->right) <= -1) node = rotateRR(node);
                else
                    node = rotateRL(node);
            }
            return node;

	DPRINT(cout << "<rebalance returning" << endl;);
}

// rebalances AVL tree at the root just once;
// It finds the first unbalanced node and invokes rebalance() at that node.
// You may have to repeat this process as necessary to change a binary
// search to into a valid AVL tree
tree _rebalanceTree(tree node) {
	if (node == nullptr) return nullptr;

	if (balanced(node)) {
		node->left = _rebalanceTree(node->left);
		node->right = _rebalanceTree(node->right);
		return node;
	}
	DPRINT(cout << " Found 1st unbalanced node at " << node->key << endl;);
	node = rebalance(node);
	return node;
}

tree buildAVL(int* v, int n) {
    if (n <= 0) return nullptr;
    
    int mid = n/2;
    
    tree newTree = new TreeNode(*(v+mid));
    newTree->left = buildAVL(v, mid);
    newTree->right = buildAVL(v+mid+1, n-mid-1);
    // construct and set a TreeNode and initial values, use the [mid] element of v.
    // your code here – recursive buildAVL() calls for left & right
    // from 0 to mid-1 (or mid number of nodes)
    return newTree;
}

tree rebalanceTree(tree node) { // may need a better solution here
	DPRINT(cout << ">rebalanceTree " << endl;);
    if (node == nullptr) return nullptr;
    // you may use inorder() to get an array of keys or nodes
    vector<int> v;
    inorder(node, v);
    
    // if you use an array of nodes, you just reconstructs AVL tree using nodes.
    clear(node);
    // if you use an array of keys, the root should be cleared (or deallocated)
    
    // your code here // O(n)
    return buildAVL(v.data(), v.size()); // O(n)
	//cout << "your code here\n";

	DPRINT(cout << "<rebalanceTree " << endl;);
}



#if 1
// inserts a node in the AVL tree and rebalance it.
// this works in O(1), instead of O(log n)
tree growAVL(tree node, int key) {
	DPRINT(cout << ">growAVL key=" << key << endl;);
    if (node == nullptr) return new TreeNode(key);
    
    if (key < node->key)    // recur down the tree
        node->left = growAVL(node->left, key);
    else if (key > node->key)
        node->right = growAVL(node->right, key);
    // your code here
    return rebalance(node);
	// cout << "your code here\n";
}
#endif

// removes a node with key in the AVL tree and rebalance it.
tree trimAVL(tree node, int key) {
	DPRINT(cout << ">trimAVL key=" << key << " at " << node->key << endl;);

	// step 1 - BST trim as usual
    int num;
    if (node == nullptr) return node;     // base case
    DPRINT(cout << ">trim: now we are at: " << node->key << endl;);
    if (key < node->key){
        DPRINT(cout << ">trim: step1: "  << endl;);
        
        node->left = trimAVL(node->left, key);
        
    } else if (key > node->key) {
        DPRINT(cout << ">trim: step2: "  << endl;);
        
        node->right = trimAVL(node->right, key);
        
    } else {
        if (node->left == nullptr) {
            DPRINT(cout << ">trim: step3: "  << endl;);
            
            tree rightnode = node->right;
            delete node;
            //root->right=trim(root->right,key);
            //delete root->right;
            node=rightnode;
            return node;
            // your code here – trim the right one, return root
        }
        else if (node->right == nullptr) {
            
            tree leftnode = node->left;
            delete node;
            node=leftnode;
            
            //root->left=trim(root->left,key);
            DPRINT(cout << ">trim: step4: "  << endl;);
            // delete root->left;
            return node;
            // your code here – trim the left one, return root
        }
        else {// two children case
            // get the successor: smallest in right subtree
            DPRINT(cout << ">trim: step5: "  << endl;);
            num = succ(node)->key;
            trimAVL(node,num);
            node->key = num;
            
            // copy the successor's content to this "root" node
            if((node->left==nullptr)||(node->right==nullptr)){
                DPRINT(cout << ">trim: step6: "  << endl;);
                
                //trim(root, key);
            }
            // trim the successor recursively, which has one or no child case
        } }	//cout << "your code here\n";
    //return rebalance(node);
	// step 2 - get the balance factor of this node
	DPRINT(if (node != nullptr)
		cout << "<trimAVL key=" << key << " is done, now rebalance at " << node->key << endl;);
	return rebalance(node);
}


