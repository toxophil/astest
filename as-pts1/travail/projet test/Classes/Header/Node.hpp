#ifndef DEF_NODE
#define DEF_NODE

#include "Room.hpp"
#include "Connection.hpp"

#include <iostream>
using namespace std;
#include <vector>

class Node {
private:
	int _idSalle;
	bool _estConnection;
	int64_t _x;
	int64_t _y;
	vector<Node> _lesNodes;
	String label;
public:
	Node();
	Node(int idSalle, bool estConnection, int64_t x, int64_t y);
	Node(const Node& copyNode); // Copy Constructor

	void addConnection(Node uneNode);
	vector<Node>& getConnections();
	bool estConnection() const;

	int64_t getX() const;
	int64_t getY() const;
	int Node::getIdSalle() const;

	String getLabel() const;
	void setLabel(String);

	bool Node::operator!=(const Node&);
	bool Node::operator==(const Node&);
};

#endif