// Given the attached code for an AVL tree.  Modify the code to implement a red-black tree.  You do NOT need to implement removals!
#include <iostream>
#include <ctime>
#include <queue>

using namespace std;

template <class T>
class AVL;

template <class T>
T& max(T& left, T& right){
	if (left > right)
		return left;
	else
		return right;

}
template <class T>
T max(const T& left, const T& right){
	if (left > right)
		return left;
	else
		return right;

}

template <class T>
class AVLNode{
	AVLNode<T>* parent, *left, *right;
	int height;
	T data;
public:
	friend class AVL < T > ;
	AVLNode(const T& newdata = T(), AVLNode<T>* newparent = nullptr, AVLNode<T>* newleft = nullptr, AVLNode<T>* newright = nullptr) :
		data(newdata), parent(newparent), left(newleft), right(newright) {
		calcHeight();
	}
	void calcHeight(){
		int leftHeight = -1;
		int rightHeight = -1;
		if (left != nullptr)
			leftHeight = left->height;
		if (right != nullptr)
			rightHeight = right->height;
		height = max(leftHeight, rightHeight) + 1;
		if (parent) //Update all parent heights also
			parent->calcHeight();
	}
	void printInOrder()const{
		if (left != nullptr)
			left->printInOrder();
		cout << data <<"\t"<<height<< endl;
		if (right != nullptr)
			right->printInOrder();
	}
	void printPostOrder()const;
	int size()const{
		int leftSize = 0;
		int rightSize = 0;
		if (left != nullptr)
			leftSize = left->size();
		if (right != nullptr)
			rightSize = right->size();
		return 1 + leftSize + rightSize;
	}
	/*	int height()const{
			int leftSize = -1;
			int rightSize = -1;
			if (left != nullptr)
			leftSize = left->height();
			if (right != nullptr)
			rightSize = right->height();
			return 1 + max(leftSize, rightSize);
			}*/
	int depth() const{
		int parentDepth = -1;
		if (parent != nullptr)
			parentDepth = parent->depth();
		return 1 + parentDepth;
	}
};

template <class T>
void AVLNode<T>::printPostOrder()const{
	if (left != nullptr)
		left->printInOrder();
	if (right != nullptr)
		right->printInOrder();
	cout << data << endl;
}


template <class T>
class AVL{
	AVLNode<T>* root;
	int size;
	AVLNode<T>* recursiveCopy(AVLNode<T>* toCopy);
	void singleCCR(AVLNode<T>*& point);
	void doubleCR(AVLNode<T>*& point);
	void singleCR(AVLNode<T>*& point);
	void doubleCCR(AVLNode<T>*& point);
	int heightDiff(AVLNode<T>* point);
	void doRotation(AVLNode<T>* point);
public:
	AVL() :size(0){ root = nullptr; }

	//memory on the heap so.... here comes the big 3!
	AVL(const AVL<T>& rhs) :root(nullptr){ *this = rhs; }
	virtual ~AVL(){ clear(); }
	AVL& operator=(const AVL<T>& rhs);

	bool isInTree(const T& toFind) const{ return find(toFind) != nullptr; }
	bool isEmpty()const{ return root == nullptr; }
	int getSize()const { return size; }
	void remove(const T& toRemove){
		AVLNode<T>* item = find(toRemove);
		if (item != nullptr)
			remove(item);
	}
	void insert(const T&);
	void insert(const T&, AVLNode<T>*& point);
	void remove(AVLNode<T>*);
	AVLNode<T>* find(const T& toFind) const;
	void clear(){ while (!isEmpty()) remove(root); }
	void printInOrder()const{ root->printInOrder(); }
	void printPostOrder()const{ root->printPostOrder(); }
	void printLevelOrder()const;
};
template <class T>
void AVL<T>::printLevelOrder() const{
	queue<AVLNode<T>*> q;
	q.push(root);
	while (!q.empty()){
		AVLNode<T>* front = q.front();
		cout << front->data << "\t" << front->height << endl;
		if (front->left!=nullptr)
			q.push(front->left);
		if (front->right)
			q.push(front->right);
		q.pop();
	}
}
template <class T>
void AVL<T>::doubleCCR(AVLNode<T>*& point){
	singleCR(point->right);
	singleCCR(point);
}

template <class T>
void AVL<T>::doubleCR(AVLNode<T>*& point){
	singleCCR(point->left);
	singleCR(point);
}

template <class T>
void AVL<T>::singleCR(AVLNode<T>*& point){
	AVLNode<T>* grandparent = point;
	AVLNode<T>* parent = point->left;
	parent->parent = grandparent->parent;
	grandparent->parent = parent;
	grandparent->left = parent->right;
	parent->right = grandparent;
	if (grandparent->left != nullptr) //if we now have a left child, update its parent pointer
		grandparent->left->parent = grandparent;
	if (parent->parent == nullptr)//if we were the root, update the root!
		root = parent;
	else if (parent->parent->left == grandparent)
		parent->parent->left = parent;
	else
		parent->parent->right = parent;
	grandparent->calcHeight();
	parent->calcHeight();
}

template <class T>
void AVL<T>::singleCCR(AVLNode<T>*& point){
	AVLNode<T>* grandparent = point;
	AVLNode<T>* parent = point->right;
	parent->parent = grandparent->parent;
	grandparent->parent = parent;
	grandparent->right = parent->left;
	parent->left = grandparent;
	if (grandparent->right != nullptr) //if we now have a right child, update its parent pointer
		grandparent->right->parent = grandparent;
	if (parent->parent == nullptr)//if we were the root, update the root!
		root = parent;
	else if (parent->parent->right == grandparent)
		parent->parent->right = parent;
	else
		parent->parent->left = parent;
	grandparent->calcHeight();
	parent->calcHeight();
}


template <class T>
AVLNode<T>* AVL<T>::recursiveCopy(AVLNode<T>* toCopy){
	if (toCopy == nullptr)
		return nullptr;
	AVLNode<T>* temp = new AVLNode<T>(toCopy->data, nullptr, recursiveCopy(toCopy->left), recursiveCopy(toCopy->right));
	if (temp->left != nullptr)
		temp->left->parent = temp;
	if (temp->right != nullptr)
		temp->right->parent = temp;
	return temp;
}

template <class T>
AVL<T>& AVL<T>::operator=(const AVL<T>& rhs){
	if (this == &rhs)
		return *this;
	clear();
	root = recursiveCopy(rhs.root);
	size = rhs.size;
	return *this;
}

template <class T>
void AVL<T>::remove(AVLNode<T>* toRemove){
	if (root == nullptr)
		return; //Remove from an empty tree????
	if (toRemove->left == nullptr && toRemove->right == nullptr){ //leaf node case
		if (toRemove->parent == nullptr){
			root = nullptr;
		}
		else if (toRemove == toRemove->parent->left) //left child!
			toRemove->parent->left = nullptr; //fix the parent's pointer!
		else
			toRemove->parent->right = nullptr;
		delete toRemove;
		size--;
	}
	else if (toRemove->right == nullptr){ //has one (left) child
		if (toRemove->parent == nullptr){
			root = toRemove->left;
			root->parent = nullptr;
		}
		else if (toRemove == toRemove->parent->left){ //we're the left child of our parent
			toRemove->parent->left = toRemove->left;
			toRemove->left->parent = toRemove->parent;
		}
		else{
			toRemove->parent->right = toRemove->left;
			toRemove->left->parent = toRemove->parent;
		}
		delete toRemove;
		size--;
	}
	else if (toRemove->left == nullptr){ //has one right child, almost same solution as left child only
		if (toRemove->parent == nullptr){
			root = toRemove->right;
			root->parent = nullptr;
		}
		else if (toRemove == toRemove->parent->left){ //we're the left child of our parent
			toRemove->parent->left = toRemove->right;
			toRemove->right->parent = toRemove->parent;
		}
		else{
			toRemove->parent->right = toRemove->right;
			toRemove->right->parent = toRemove->parent;
		}
		delete toRemove;
		size--;
	}
	else{ //sigh... two children!
		AVLNode<T>* temp = toRemove->right;
		while (temp->left != nullptr)
			temp = temp->left;
		toRemove->data = temp->data;
		remove(temp);
	}

}

template <class T>
AVLNode<T>* AVL<T>::find(const T& toFind) const{
	AVLNode<T>* temp = root;
	while (temp != nullptr && temp->data != toFind){
		if (toFind < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}

template <class T>
void AVL<T>::insert(const T& toInsert, AVLNode<T>*& point){
	if (point==nullptr)
		point = new AVLNode<T>(toInsert);
	else if (toInsert < point->data){
		insert(toInsert, point->left);
		point->left->parent = point; //update parent pointer
		point->calcHeight();
		if (heightDiff(point) > 1){
			doRotation(point);
		}
	}
	else{
		insert(toInsert, point->right);
		point->right->parent = point;
		point->calcHeight();
		if (heightDiff(point) > 1){
			doRotation(point);
		}
	}
}

template <class T>
void AVL<T>::insert(const T& toInsert){
	insert(toInsert, root);
}
template <class T>
void AVL<T>::doRotation(AVLNode<T>* point){
	int leftChild = -1;
	int rightChild = -1;
	if (point->left != nullptr)
		leftChild = point->left->height;
	if (point->right != nullptr)
		rightChild = point->right->height;

	if (leftChild > rightChild){//CR, but is it single or double?
		int leftGC = -1;
		int rightGC = -1;
		if (point->left->left != nullptr)
			leftGC = point->left->left->height;
		if (point->left->right != nullptr)
			rightGC = point->left->right->height;
		if (leftGC > rightGC) // single rotation
			singleCR(point);
		else
			doubleCR(point);
	}
	else{//definitely a CCR, but which one?
		int leftGC = -1;
		int rightGC = -1;
		if (point->right->left != nullptr)
			leftGC = point->right->left->height;
		if (point->right->right != nullptr)
			rightGC = point->right->right->height;
		if (leftGC > rightGC) // double rotation
			doubleCCR(point);
		else
			singleCCR(point);
	}
}


template<class T>
int AVL<T>::heightDiff(AVLNode<T>* point){
	int leftHeight = -1;
	int rightHeight = -1;
	if (point->left != nullptr)
		leftHeight = point->left->height;
	if (point->right != nullptr)
		rightHeight = point->right->height;
	return (abs(leftHeight - rightHeight));
}


int main(){
	
	AVL<int> b;
	srand(time(NULL));
	for (int i = 0; i < 25; i++){
		int val = rand() % 1000;
		b.insert(val);
	}
	b.printLevelOrder();
}