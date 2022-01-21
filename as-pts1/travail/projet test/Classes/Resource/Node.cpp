#include "../Header/Node.hpp"

Node::Node() {
	_x = 0;
	_y = 0;
	_idSalle = 0;
	_estConnection = false;
}
Node::Node(int idSalle, bool estConnection, int64_t x, int64_t y) {
	cout << "Make node, zone ID:" << idSalle << " estConnection?:" << estConnection << " x:" << x << " y:" << y << endl;
	_x = x;
	_y = y;
	_idSalle = idSalle;
	_estConnection = estConnection;
}
Node::Node(const Node& copyNode) {
	_x = copyNode._x;
	_y = copyNode._y;
	_idSalle = copyNode._idSalle;
	_estConnection = copyNode._estConnection;
	_lesNodes = copyNode._lesNodes;
	label = copyNode.label;
}

void Node::addConnection(Node uneNode) {
	_lesNodes.push_back(uneNode);
}

vector<Node>& Node::getConnections() {
	return _lesNodes;
}

bool Node::estConnection() const {
	return _estConnection;
}

int64_t Node::getX() const {
	return _x;
}
int64_t Node::getY() const  {
	return _y;
}

String Node::getLabel() const {
	return label;
}
void Node::setLabel(String s) {
	label = s;
}

int Node::getIdSalle() const {
	return _idSalle;
}

bool Node::operator!=(const Node& node) {
	return node.getX() != _x || node.getY() != node.getY();
}
bool Node::operator==(const Node& node) {
	return node.getX() == _x && node.getY() == _y;
	/*
		return node._idSalle == _idSalle && node._estConnection == _estConnection;*/
}