#include "algofatorial.h"

bool verifyDegree (Graph<int,int> *g1, Graph<int,int> *g2)
{

	int num_nodes = g1->getNumberNodes ();

	std::vector<int> nodesG1 = std::vector<int> (num_nodes,0);
	std::vector<int> nodesG2 = std::vector<int> (num_nodes,0);
	for (int i=0; i < num_nodes; i++) {

		int index = g1->getVertex (i).getDegree ();
		nodesG1[index]++;

		index = g2->getVertex (i).getDegree ();
		nodesG2[index]++;
	}

	for (int i=0; i < num_nodes; i++) {

		if (nodesG1[i] != nodesG2[i]) return false;
	}



	return true;

}


