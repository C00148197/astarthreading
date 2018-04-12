#pragma once

#include "stdafx.h"
#include "Node.h"
#include "Arc.h"

#include <queue>

class NodeLayout {
public:
	NodeLayout() {}
	NodeLayout(std::vector<SDL_Point> &nodeData);

	int getNoOfNodes();

	Node** getNodes();

private:
	Node** m_nodes; // point to nodearray

	int m_noOfNodes;

	void addArcs(); // addsarcs
};
