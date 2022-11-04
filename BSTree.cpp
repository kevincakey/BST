#include "BSTree.h"

using namespace std;

BSTree::BSTree()
{
	root = nullptr;
}

BSTree::~BSTree()
{
	deleteTree(root);
	root = nullptr;
}
void BSTree::deleteTree(Node* temp) {
	if (temp) {
		deleteTree(temp->getLeft());
		deleteTree(temp->getRight());
		delete temp;
	}
}

void BSTree::insert(const string& newString)
{
	//cout << "insert function start" << endl;
	Node* temp = new Node(newString, 1);
	//cout << "starting if statments" << endl;
	if (root == nullptr)
	{
		//cout << "root" << endl;
		root = temp;
		//temp->setLeft(nullptr);
		//temp->setRight(nullptr);
		return;
	}
	else if(search(newString))
	{
		//cout << "search" << endl;
		Node* temp = search(newString, root);
		temp->countGoUp();
		return;
	}
	else
	{
		//cout << "else" << endl;
		Node* curr = root;
		while(curr != nullptr)
		{
			if(temp->getData() < curr->getData())
			{
				if(curr->getLeft() == nullptr)
				{
					curr->setLeft(temp);
					curr = nullptr;
				}
				else
				{
					curr = curr->getLeft();
				}
			}
			else
			{
				if(curr->getRight() == nullptr)
				{
					curr->setRight(temp);
					curr = nullptr;

				}
				else
				{
					curr = curr->getRight();
				}
			}
		}
	}
}

Node* AVLTree::findPredecessor(Node* temp){
	if (temp->getRight() != nullptr) {
		return findPredecessor(temp->getRight());
	}
	return temp;
}

Node* AVLTree::findSuccessor(Node* temp) {
	if (temp->getLeft() != nullptr) {
		return findSuccessor(temp->getLeft());
	}
	return temp;
}

Node* AVLTree::remove(Node *temp, const string &key){
  if (temp == nullptr){
    return temp;
  }
  if (key < temp->getData()){
    temp->setLeft(remove(temp->getLeft(), key));
  }
  else if (key > temp->getData()){
    temp->setRight(remove(temp->getRight(), key));
  }
  else{
    if (temp->getCount() > 1){
      temp->countGoDown();
      return temp;
    }
    if (temp->getLeft()){
      Node *replacer = temp->getLeft();
      Node *itemp = temp;
      int counter = 0;
      while (replacer->getRight() != nullptr){
        itemp = replacer;
        replacer = replacer->getRight();
        counter++;
      }
      temp->setData(replacer->getData());
      temp->setCount(replacer->getCount());
      if(itemp->getRight() && !itemp->getLeft()){
          itemp->setRight(replacer->getLeft());
      }
      else if(itemp->getLeft()){
          itemp->setLeft(replacer->getLeft());
      }
      else{
          itemp->setLeft(nullptr);
      }
      
      delete replacer;
      return temp;
    }
    else if (temp->getRight()){
      Node *replacer = temp->getRight();
      Node *itemp = temp;
      int counter = 0;
      while (replacer->getLeft() != nullptr){
        itemp = replacer;
        replacer = replacer->getLeft();
        counter++;
      }
      temp->setData(replacer->getData());
      temp->setCount(replacer->getCount());
      if(itemp->getRight() && !itemp->getLeft()){
          itemp->setRight(replacer->getRight());
      }
      else if(itemp->getLeft()){
          itemp->setLeft(replacer->getRight());
      }
      else{
          itemp->setRight(nullptr);
      }
      delete replacer;
      return temp;
    }
    else{
      delete temp;
      return nullptr;
    }
  }
  return temp;
}
void BSTree::remove(const string &key){
  Node *temp = search(key, root);
  if (temp == nullptr){
  }
  else{
    root = remove(root, key);
  }
}
	//Node* itemp = root;
	//if(temp != itemp){
	//	while (itemp->getLeft() != temp && itemp->getRight() != temp) {
	//		//cout << "while loop start" << endl;
	//		if (key > itemp->getData()) {
	//			//cout << "if right" << endl;
	//			itemp = itemp->getRight();
	//		}
	//		else if (key < itemp->getData()) {
	//			//cout << "else left" << endl;
	//			itemp = itemp->getLeft();
	//		}
	//	}
	//}
	//cout << itemp->getData()<< endl;
	////cout << " we didnt make it here";
	//if (temp->getLeft() == nullptr && temp->getRight() != nullptr)
	//{
	//	if (itemp->getLeft() == temp) {
	//		itemp->setLeft(temp->getRight());
	//	}
	//	else if(itemp->getRight() == temp){
	//		itemp->setRight(temp->getRight());
	//	}
	//	else{
	//		root = temp->getRight();
	//	}
	//	delete temp;
	//}
	//else if (temp->getLeft() != nullptr && temp->getRight() == nullptr)
	//{
	//	if (itemp->getLeft() == temp) {
	//		itemp->setLeft(temp->getLeft());
	//	}
	//	else if(itemp->getRight() == temp){
	//		itemp->setRight(temp->getLeft());
	//	}
	//	else{
	//		root = temp->getLeft();
	//	}
	//	delete temp;
	//}
	//else {
	//	//cout << "REPLACER TIME BB";
	//	Node* replacer;
	//	replacer = findSuccessor(temp->getLeft());
	//	temp->setData(replacer->getData());
	//	remove(replacer->getData());
	//}


bool BSTree::search(const string& key) const // recrusive
{
	//cout << "search function start" << endl;
	Node* temp = search(key, root);

	if (temp != nullptr) {
		//cout << "search function end true" << endl;
		return true;
	}
	else {
		//cout << "search function end false" << endl;
		return false;
	}
}

Node* BSTree::search(const string& key, Node* temp) const
{
	//cout << "search helper start" << endl;
	if(temp == nullptr){
		//cout << "temp == nullptr beginning" << endl;
		return nullptr;
	}
	if (temp->getData() == key) 
	{
		//cout << "temp->getData == key" << endl;
		//cout << temp->getData() << endl;
		return temp;
	}
	else if(temp->getData() < key)
	{
		return search(key, temp->getRight());//stop 1
	}
	else if(temp->getData() > key)
	{
		return search(key, temp->getLeft());
	}
	if (temp->getData() == key) 
	{
		//cout << "search helper function end" << endl;
		//cout << temp->getData() << endl;
		return temp;
	}
	//cout << "temp == nullptr end" << endl;
	return nullptr;
}

string BSTree::largest() const
{
	Node* temp = root;
	if (temp == 0) {
		return "";
	}
	while (temp->getRight()) {
		temp = temp->getRight();
	}
	return temp->getData();
}

string BSTree::smallest() const
{
	Node* temp = root;
	if (temp == 0) {
		return "";
	}
	while (temp->getLeft()) {
		temp = temp->getLeft();
	}
	return temp->getData();
}

int BSTree::height(const string& h) const
{
	Node* temp = search(h, root);
	if (temp == nullptr) {
		return -1;
	}
	else {
		int i = height(temp);
		
		return i;
	}
}
int BSTree::height(Node* temp) const{
	if (temp != 0) {
		int tright = height(temp->getRight());
		int tleft = height(temp->getLeft());
		if (tright > tleft) {
			return 1 + tright;
		}
		else {
			return 1 + tleft;
		}
	}
	else {
		return -1;
	}
}

void BSTree::preOrder() const{
	preOrder(root);
}
void BSTree::postOrder() const{
	postOrder(root);
}
void BSTree::inOrder() const{
	inOrder(root);
}
void BSTree::preOrder(Node* temp) const{
	if (temp != nullptr) {
		cout << temp->getData() << '(' << temp->getCount() << ')' << ", ";
		preOrder(temp->getLeft());
		preOrder(temp->getRight());
	}
}
void BSTree::postOrder(Node* temp) const {
	if (temp !=nullptr) {
		postOrder(temp->getLeft());
		postOrder(temp->getRight());
		cout << temp->getData() << '(' << temp->getCount() << ')' << ", ";
	}
}
void BSTree::inOrder(Node* temp) const{
	if(temp != nullptr){
		inOrder(temp->getLeft());
        cout << temp->getData() << '(' << temp->getCount() << ')' << ", ";
		inOrder(temp->getRight());
	}
}