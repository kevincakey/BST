#include "Node.h"
Node::Node(){
	count = 0;
	data = "";
	left = nullptr;
	right = nullptr;
}
Node::Node(string tdata, int tcount){
	count = tcount;
	data = tdata;
	left = nullptr;
	right = nullptr;
}
Node* const Node::getLeft() const{
	return left;
}
Node* const Node::getRight() const{
	return right;
}
int const Node::getCount() const{
	return count;
}
string const Node::getData() const{
	return data;
}
void Node::setData(string temp){
	data = temp;
}
void Node::setCount(int temp){
	count = temp;
}
void Node::countGoDown(){
	count--;
}
void Node::countGoUp(){
	count++;
}
void Node::setLeft(Node* temp)
{
	left = temp;
}
void Node::setRight(Node* temp)
{
	right = temp;
}