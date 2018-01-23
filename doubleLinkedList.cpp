#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *prev;
	Node *next;
};

void initNode(Node *tmpHead, int n) {  //initialize the Node
	tmpHead->data = n;
	tmpHead->prev = NULL;
	tmpHead->next = NULL;
}

// display all nodes in LinkedList
void displayNodes(Node *cur) {
	cout << "$ ";
	while (cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << "*" << endl;
}

// add a new node at the end of LinkedList
void addNode(Node *cur, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	while (cur->next != NULL) {
		cur = cur->next;
	}		
	cur->next = newNode;
	newNode->prev = cur;
}

// add a new node to front of LinkedList
void addFront(Node **tmpHead, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *tmpHead;
	newNode->prev = NULL;
	*tmpHead = newNode; 
	newNode->next->prev = newNode;
}

// remove a node at front of LinkedList
void removeFront(Node **tmpHead) {
	if ((*tmpHead)->next != NULL){
		(*tmpHead) = (*tmpHead)->next;
		delete (*tmpHead)->prev;
		(*tmpHead)->prev = NULL;		
	}
	else
		delete *tmpHead;
}

// reverse the display order of all nodes in LinkedList
void displayNodesReverse(Node *tmpHead) {
	Node *cur = tmpHead;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	while (cur) {
		cout << cur->data << " ";
		cur = cur->prev;
	}
	cout << endl;
}

void main() {
	Node *head = new Node;
	initNode(head, 22);
	displayNodes(head);
	addNode(head, 33);
	addNode(head, 44);
	displayNodes(head);
	addFront(&head, 11);
	displayNodes(head);
	displayNodesReverse(head);
	removeFront(&head);
	displayNodes(head);
}

