#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<string>
using namespace std;
class Node
{
private:
	Node* left = nullptr;
	Node* right = nullptr;
	string data = "";
	int count = 0;
public:
	Node();
	Node(string tdata, int tcount);
	int const getCount() const;
	string const getData() const;
	Node* const getLeft() const;
	Node* const getRight() const;
	void setData(string tdata);
	void setCount(int tcount);
	void countGoUp();
	void countGoDown();
	void setLeft(Node* temp);
	void setRight(Node* temp);
};
#endif