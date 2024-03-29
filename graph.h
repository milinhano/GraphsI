//
//  graph.h
//  Isomorfismo
//
//  Created by Camila Taumaturgo on 21/04/13.
//  Copyright (c) 2013 Camila Taumaturgo. All rights reserved.
//

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <iostream>

template <class T>
class Vertex;

/**
 *  class T representa o tipo de rótulo do vértice
 *  class R representa o tipo do valor das arestas
 */
template <class T, class R>
class Graph
{
    
public:
	Graph(int _num_nodes, int _num_edges);
    
	void addEdge (const Vertex<T> & v2, const Vertex<T> & v1,const R & value);
    
	void removeEdge (const Vertex<T> & v2, const Vertex<T> & v1);
    
	void addVertex (const Vertex<T> & v);
    
	friend std::ostream & operator<< (std::ostream & out, const Graph<T,R> & G) {
        
		out << "printing Vertex \n";
		out << "Vertex:Label:Degree" << std::endl;
		for (int i=0; i < G.num_nodes; i++) {
			if (G.vertexSet[i].getIndex() > -1)
				out << G.vertexSet[i] << "\n";
		}
		out << "\nprintg Edges\n";
		for (int i=0; i < G.num_nodes; i++) {
			for (int j=0; j < i; j++) {
				if (G.adjMatrix[i][j] != 0) {
					out << G.vertexSet[i].getLabel();
					out << "--";
					out << G.vertexSet[j].getLabel();
					out << "\n";
				}
			}
		}
        
		return out;
	}
    
private:
    
	std::vector< std::vector<R> > adjMatrix;
	std::vector< Vertex<T> > vertexSet;
    
	int num_nodes;
	int num_edges;
    
};

template <class T, class R>
Graph<T,R>::Graph (int _num_nodes, int _num_edges)
: num_nodes (_num_nodes), num_edges(_num_edges)
{
	//definindo matrix que armazena peso de arestas do tipo R
	//R pode ser double, inteiro...
	adjMatrix = std::vector< std::vector<R> >
    ( _num_nodes, std::vector<R>(_num_nodes));
    
	vertexSet = std::vector< Vertex<T> >(_num_nodes);
}
template <class T, class R>
void Graph<T,R>::addEdge (const Vertex<T> & v1,
                          const Vertex<T> & v2, const R & value)
{
	int i = v1.getIndex();
	int j = v2.getIndex();
	adjMatrix[i][j] = value;
	adjMatrix[j][i] = value;
    
	addVertex (v1);
	addVertex (v2);
}

template <class T, class R>
void Graph<T,R>::addVertex (const Vertex<T> & v)
{
	int i = v.getIndex();
	if (vertexSet[i].getIndex() == -1) {
		vertexSet[i] = v;
	}
	vertexSet[i].increaseDegree ();
    
}

#endif


/**
 *
 *  Definição da classe Vertex.
 *
 */
#ifndef _VERTEX_H_
#define _VERTEX_H_

template <class T>
class Vertex {
    
public:
    
	Vertex() : index(-1), degree(0) {}
    
	Vertex (int _index, T _label);
    
	inline int getIndex () const {return index;}
	inline T getLabel () const {return label;}
    
	inline void increaseDegree (){degree++;}
	inline void decreaseDegree (){degree--;}
    
	friend std::ostream & operator << (std::ostream & out, const Vertex<T> v) {
        
		out << v.index << ":" << v.label << ":" << v.degree;
		return out;
        }
        
    private:
        int index;
        T label;
        int degree;
        };
        
        template <class T>
        Vertex<T>::Vertex (int _index, T _label)
        : index (_index), degree(0)
        {
            label = _label;
        }

#endif
