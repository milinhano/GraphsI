#ifndef _READER_H_
#define _READER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "graph.h"

template <class T, class R>
void reader (char * _file, Graph<T,R> *g1, Graph<T,R> * g2)
{

	std::ifstream file;
	file.open (_file);

	std::string aux;
	std::string tmp;

	int num_vertex;
	file >> num_vertex;

	int count = 0;

	while (file.good () ) {

		file >> aux;

		const char * line = aux.c_str ();

		for (int i=0; i < count; i++) {
			tmp = line[i];
			int number = atoi(tmp.c_str() );
			if (number == 1 && i != count){
				Vertex<int> v1(i,i),  v2(count,count);
				g1->addEdge (v1,v2,1);
				g1->getVertex ( v1.getIndex () ).addNeighboor (v2);
				g1->getVertex ( v2.getIndex () ).addNeighboor (v1);
			}

		}


		if (count == 9) break;
		count++;

	}


	count = 0;
	while (file.good ()) {

		file >> aux;
		const char * line = aux.c_str ();

                for (int i=0; i < count; i++) {
                        tmp = line[i];
                        int number = atoi(tmp.c_str() );
                        if (number == 1 && i != count){
                                Vertex<int> v1(i,i),  v2(count,count);
                                g2->addEdge (v1,v2,1);
				g2->getVertex ( v1.getIndex () ).addNeighboor (v2);
				g2->getVertex ( v2.getIndex () ).addNeighboor (v1);
                        }

                }

                if (count == 9) break;
                count++;
	}

}

#endif
