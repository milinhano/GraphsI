#ifndef _ALGOFAT_H_
#define _ALGOFAT_H_

#include "graph.h"

//redefining types
//typedef Graph<int,int> Graph;
//typedef Vertex<int> Vertex;

#define false 0
#define true 1

//interface of the algorithm
bool verifyDegree (Graph<int,int> *g1, Graph<int,int> *g2);

#endif
