#pragma once
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/*
BinaryTree
Copyright © MaxRev 2017
All rights reserved
*/
struct Item {
	int id;
	std::string name, tel;
	friend ostream& operator<<(ostream&out ,const Item &i) {
		return out<<"#"<<i.id << " ²μ'ÿ: " << i.name.c_str() << " Òελ.: " << i.tel.c_str() << endl;
	}
	friend bool operator< (const Item& lhs, const Item& rhs) {
		return lhs.id < rhs.id;
	}
	friend bool operator> (const Item& lhs, const Item& rhs) { return rhs < lhs; }
	friend  bool operator<=(const Item& lhs, const Item& rhs) { return !(lhs > rhs); }
	friend bool operator>=(const Item& lhs, const Item& rhs) { return !(lhs < rhs); }
	friend  bool operator==(const Item& lhs, const Item& rhs) {
		return lhs.id == rhs.id;
	}
	friend 	 bool operator!=(const Item& lhs, const Item& rhs) { return !(lhs == rhs); }
	
};

using namespace std;
class BinaryTree {
  static int counter ;
public:
	int treeSize(struct Tree *node);
	int minDepth(struct Tree *node);
	int maxDepth(struct Tree *node);
	bool  isBalanced(struct Tree *node);
	Tree* minTree(struct Tree *node);
	Tree*  maxTree(struct Tree *node);
	Tree * succesorInOrder(struct Tree *node);
	void  reverseOrderPrint(struct Tree *node);
	Tree * lowestCommonAncestor(Tree *node, Tree *p, Tree *q);
	void  clear(struct Tree *node);
	void  printTreeInOrder(struct Tree *node);
	Tree * predecessorInOrder(struct Tree *node);
	void  printTreePostOrder(struct Tree *node);
	void  printTreePreOrder(struct Tree *node);
	void  pathFinder(struct Tree *node, int path[], int level);
	void  printTreeReverseOrder(struct Tree *node);
	bool  matchTree(Tree *r1, Tree *r2);
	bool  subTree(Tree *r1, Tree *r2);
	bool  isSubTree(Tree *r1, Tree *r2);
	void  mirror(Tree *r);
	int  getLevel(struct Tree *node, int elm, int level);
	void  level_even_odd(struct Tree *node);
	void  BreadthFirstTraversal(Tree *root);

	Tree* lookUp(struct Tree *node, int key);
	Tree* leftMost(struct Tree *node);
	void  BreadthFirst_LevelElement_Print
	(struct Tree *root, vector<vector<int> > &v);

	void  levelPrint
	(struct Tree *node, vector<vector<char>>&elm, int level);

	void  NthMax(struct Tree* t);
	void  TreeToArray(struct Tree *node, int a[]);
	Tree* root;
	void  FindAndPrintNode(Tree*node, int key);
};

struct Tree
{
	Item data;
	Tree *left;
	Tree *right;  
	Tree *parent;  
};

struct Tree *newTreeNode(Item data)
{
	Tree *node = new Tree;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	return node;
}

struct Tree* insertTreeNode(struct Tree *node, Item data)
{
	static Tree *p;
	Tree *retNode;

	if(node == NULL)  {
	    retNode = newTreeNode(data);
	    retNode->parent = p;
	    return retNode;
	}
	if(data <= node->data ) { 
	    p = node;
	    node->left = insertTreeNode(node->left,data);
	} 
	else {
	    p = node;
	    node->right = insertTreeNode(node->right,data);
	} 
	return node;
}
void  BinaryTree::FindAndPrintNode(Tree*node,int key) {
	Tree *fnd = this->lookUp(node, key);
	if (fnd != NULL) {
		cout << "\nFound: \n" << fnd->data << endl;
	}
	else cout << "\nNumber " << key << " NOT found\n";
}
	
Tree* BinaryTree::lookUp(struct Tree *node, int key)
{
	if(node == NULL) return node;

	if(node->data.id == key) return node;
	else {
	    if(node->data.id < key)
		return lookUp(node->right, key) ;
	    else
		return lookUp(node->left, key);
	}
}

Tree*  BinaryTree::leftMost(struct Tree *node)
{
	if(node == NULL) return NULL;
	while(node->left != NULL)
		node = node->left;
	return node;
}

int  BinaryTree::treeSize(struct Tree *node)
{
	if(node == NULL) return 0;
	else
	    return treeSize(node->left) + 1 + treeSize(node->right);
}

int  BinaryTree::maxDepth(struct Tree *node)
{
	if(node == NULL || (node->left == NULL && node->right == NULL)) 
            return 0;

	int leftDepth = maxDepth(node->left);
	int rightDepth = maxDepth(node->right);

	return leftDepth > rightDepth ? 
				leftDepth + 1 : rightDepth + 1;
}

int  BinaryTree::minDepth(struct Tree *node)
{
	if(node == NULL || (node->left == NULL && node->right == NULL)) 
            return 0;

	int leftDepth = minDepth(node->left);
	int rightDepth = minDepth(node->right);

	return leftDepth < rightDepth ? 
				leftDepth + 1 : rightDepth + 1;
}

bool  BinaryTree::isBalanced(struct Tree *node)
{
	if(maxDepth(node)-minDepth(node) <= 1) 
	    return true;
	else
	    return false;
}

Tree*   BinaryTree::minTree(struct Tree *node)
{
	if(node == NULL) return NULL;
	while(node->left) 
	    node = node -> left;
	return node;
}

Tree*  BinaryTree::maxTree(struct Tree *node)
{
	while(node->right) 
	    node = node -> right;
	return node;
}


Tree * BinaryTree::succesorInOrder(struct Tree *node)
{
	if(node->right != NULL) return minTree(node->right);

	Tree *y = node->parent;
	while(y != NULL && node == y->right) {
	    node = y;
	    y = y->parent;
	}
	return y;
}

Tree * BinaryTree::predecessorInOrder(struct Tree *node)
{
	if(node->left != NULL) return maxTree(node->left);

	Tree *y = node->parent;
	while(y != NULL && node == y->left) {
	    node = y;
	    y = y->parent;
	}
	return y;
}

void  BinaryTree::reverseOrderPrint(struct Tree *node)
{
	if(node == NULL) return;
	if(node->left == NULL && node->right == NULL) {
		cout << node->data << " ";
		return;
	}
	
	reverseOrderPrint(node->right);
	cout << node->data << " ";
	reverseOrderPrint(node->left);
}
 
Tree * BinaryTree::lowestCommonAncestor(Tree *node, Tree *p, Tree *q)
{
	Tree *left, *right;
	if(node == NULL) return NULL;
	if(node->left == p || node->left == q
		|| node->right == p || node->right == q) return node;
	
	left = lowestCommonAncestor(node->left,p,q);
	right = lowestCommonAncestor(node->right, p,q);
	if(left && right) 
	    return node;
	else 
	    return (left) ? left : right;	
}

void  BinaryTree::clear(struct Tree *node)
{
	if(node != NULL) {
	    clear(node->left);
	    clear(node->right);
	    delete node;
	}
}

void  BinaryTree::printTreeInOrder(struct Tree *node)
{
	if (node == NULL) {
		return;
	}
	printTreeInOrder(node->left);
	cout << node->data<<endl;
	printTreeInOrder(node->right);
}
int BinaryTree::counter = 0;

void  BinaryTree::printTreePostOrder(struct Tree *node)
{
	if(node == NULL) return;

	printTreePostOrder(node->left);
	printTreePostOrder(node->right);
	cout << node->data<< endl;
}

void  BinaryTree::printTreePreOrder(struct Tree *node)
{
	if(node == NULL) return;

	cout << node->data << endl;
	printTreePreOrder(node->left);
	printTreePreOrder(node->right);
}


void  BinaryTree::printTreeReverseOrder(struct Tree *node)
{
	if(node == NULL) return;
	if(node->left == NULL && node->right == NULL) {
		cout << node->data<< endl;
	    return;
	}
	
	printTreeReverseOrder(node->right);
	cout<< node->data << endl;
	printTreeReverseOrder(node->left);
}

void  BinaryTree::pathFinder(struct Tree *node, int path[], int level)
{
	if(node == NULL) return;
	if(node->left == NULL && node->right == NULL) {
	    path[level] = node->data.id;
	    for(int i = 0; i <= level; i++) {
		cout << (char)path[i];
	    }
	    cout << endl;
	    return;
	}

	path[level] = node->data.id;
	pathFinder(node->left, path, level+1);
	pathFinder(node->right, path, level+1);
}

bool  BinaryTree::matchTree(Tree *r1, Tree *r2)
{

	if(r1 == NULL && r2 == NULL)
	    return true;

	if(r1 == NULL || r2 == NULL)
	    return false;

	if(r1->data != r2->data)
	    return false;
	return (matchTree(r1->left, r2->left) && 
			matchTree(r1->right, r2->right));
}

bool  BinaryTree::subTree(Tree *r1, Tree *r2)
{

	if(r1 == NULL)
	    return false;
	if(r1->data == r2->data)
	    if(matchTree(r1, r2)) return true;
	return 
            (subTree(r1->left, r2) || subTree(r1->right, r2));
}

bool  BinaryTree::isSubTree(Tree *r1, Tree *r2)
{

	if(r2 == NULL) 
	    return true;
	else
	    return subTree(r1, r2);
}


void  BinaryTree::mirror(Tree *r)
{
	if(r == NULL) return;
	
	Tree *tmp;
	mirror(r->left);
	mirror(r->right);


	tmp = r->right;
	r->right = r->left;
	r->left = tmp;
}


void  BinaryTree::BreadthFirstTraversal(Tree *root)
{
	if (root == NULL) return;
	deque <Tree *> queue;
	queue.push_back(root);

	while (!queue.empty()) {
	    Tree *p = queue.front();
		cout << "Numder: " << p->data<< endl;
	    queue.pop_front();

	    if (p->left != NULL)
		queue.push_back(p->left);
	    if (p->right != NULL)
		queue.push_back(p->right);
	}
	cout << endl;
} 


int  BinaryTree::getLevel(struct Tree *node, int elm, int level)
{
	if(node == NULL) return 0;
	if(elm == node->data.id) 
	    return level;
	else if(elm < node->data.id) 
	    return getLevel(node->left, elm, level+1);
	else 
	    return getLevel(node->right, elm, level+1);
}


void  BinaryTree::BreadthFirst_LevelElement_Print
               (struct Tree *root, vector<vector<int> > &v)
{
	if(root == NULL) return;
	deque<Tree *> q;
	q.push_back(root);
	while(!q.empty()) {
	    Tree *p =  q.front();
	    int lev = getLevel(root, p->data.id, 0);
	    v[lev].push_back(p->data.id);
	    q.pop_front();
	    if(p->left) q.push_back(p->left);
	    if(p->right)q.push_back(p->right);
	}
	return;
}



void  BinaryTree::levelPrint(struct Tree *node, vector<vector<char> >&elm, int level)
{
	if(node == NULL) return;
	// leaf nodes
	if(node->left == NULL && node->right == NULL) {
	    elm[level].push_back(node->data.id);
	    return;
	}
	// other nodes
	elm[level++].push_back(node->data.id);
	levelPrint(node->left, elm, level);
	levelPrint(node->right, elm, level);
}


void  BinaryTree::NthMax(struct Tree* t)
{        
	static int n_th_max = 5;
	static int num = 0;
	if(t == NULL) return;        
	NthMax(t->right);        
	num++;        
	if(num == n_th_max)                
	    cout << n_th_max << "-th maximum number is " 
                 << t->data << endl;        
	NthMax(t->left);
}


void  BinaryTree::TreeToArray(struct Tree *node, int a[]){
	static int pos = 0; 
  
	if(node){ 
	    TreeToArray(node->left,a); 
	    a[pos++] = node->data.id; 
	    TreeToArray(node->right,a); 
       } 
} 

void  BinaryTree::level_even_odd(struct Tree *node)
{
	vector<char> evenVec, oddVec;
	if (node == NULL) return;
	deque<struct Tree*> que;
	que.push_back(node);

	while(!que.empty()) 
	{
	    struct Tree *p = que.front();
	    int level = getLevel(node, p->data.id, 0) ;
	    if (level % 2 == 0) 
		evenVec.push_back(p->data.id);
	    else
		oddVec.push_back(p->data.id);
	    que.pop_front();
	    if(p->left)  que.push_back(p->left);
	    if(p->right) que.push_back(p->right);
	}
	
	cout << "even level elements : ";
	for(size_t i = 0; i < evenVec.size(); i++) 
            cout << evenVec[i] << " ";
	cout << endl << "odd level elements : ";
        for(size_t i = 0; i < oddVec.size(); i++) 
            cout << oddVec[i] << " ";
	cout << endl;
}

/*
BinaryTree
Copyright © MaxRev 2017
All rights reserved
*/