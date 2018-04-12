#include "NodeLayout.h"

NodeLayout::NodeLayout(std::vector<SDL_Point> &nodeData) {
	m_noOfNodes = nodeData.size() + 1;

	m_nodes = new Node*[m_noOfNodes];

	for (int i = 0; i < nodeData.size(); i++) {
		m_nodes[i] = new Node(nodeData.at(i), i);
		m_nodes[i]->setMarked(false);
	}

	addArcs();
}

void NodeLayout::addArcs() {


	//debug nodes
	m_nodes[0]->addArc(m_nodes[1]);
	m_nodes[1]->addArc(m_nodes[0]);


	m_nodes[1]->addArc(m_nodes[2]);
	m_nodes[2]->addArc(m_nodes[1]);

	m_nodes[2]->addArc(m_nodes[3]);
	m_nodes[3]->addArc(m_nodes[2]);

	m_nodes[3]->addArc(m_nodes[4]);
	m_nodes[4]->addArc(m_nodes[3]);


	m_nodes[4]->addArc(m_nodes[5]);
	m_nodes[5]->addArc(m_nodes[4]);

	m_nodes[1]->addArc(m_nodes[3]);
	m_nodes[3]->addArc(m_nodes[1]);

	m_nodes[2]->addArc(m_nodes[4]);
	m_nodes[4]->addArc(m_nodes[2]);

	m_nodes[4]->addArc(m_nodes[6]);
	m_nodes[6]->addArc(m_nodes[4]);

	//problem encountered with node late in gridnodes, commented out for now.

	//int col = 1;

	//for (int i = 0; i < m_noOfNodes; i++) {

	//	if (i == 2188)
	//	{
	//		std::cout << "what on earth bug is this" << std::endl;
	//	}

	//	if (i == (nodesPerLines * col)) {
	//		col++;
	//	}

	//	if ((i + nodesPerLines) < m_noOfNodes) {
	//		m_nodes[i]->addArc(m_nodes[i] + nodesPerLines);
	//		m_nodes[i + nodesPerLines]->addArc(m_nodes[i]);
	//	}

	//	if ((i + 1) < m_noOfNodes) {
	//		if (i < (nodesPerLines * col) - 1) {
	//			m_nodes[i]->addArc(m_nodes[i] + 1);
	//			m_nodes[i + 1]->addArc(m_nodes[i]);
	//		}
	//	}

	//	if (i + 1 + nodesPerLines < m_noOfNodes) {
	//		if (i < (nodesPerLines * col) - 1) {
	//			m_nodes[i]->addArc(m_nodes[i] + 1 + nodesPerLines);
	//			m_nodes[i + 1 + nodesPerLines]->addArc(m_nodes[i]);
	//		}
	//	}

	//	if ((i + 1) - nodesPerLines >= 0) {
	//		m_nodes[i]->addArc(m_nodes[(i + 1) - nodesPerLines]);
	//		m_nodes[(i + 1) - nodesPerLines]->addArc(m_nodes[i]);
	//	}
	//}

}

int NodeLayout::getNoOfNodes() {
	return m_noOfNodes;
}

Node** NodeLayout::getNodes() {
	return m_nodes;
}