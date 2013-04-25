//
//  algofatorial.h
//  IsoForcaB
//
//  Created by Camila Taumaturgo on 24/04/13.
//  Copyright (c) 2013 Camila Taumaturgo. All rights reserved.
//

#ifndef __IsoForcaB__algofatorial__
#define __IsoForcaB__algofatorial__

#include <iostream>

#include "graph.h"

//redefining types
//typedef Graph<int,int> Graph;
//typedef Vertex<int> Vertex;

#define false 0
#define true 1

//interface of the algorithm
bool verifyDegree (Graph<int,int> *g1, Graph<int,int> *g2);
void Troca(int v[],int i,int j);
void Gira_Esquerda(int v[],int go, int n);
void Imprima(int s[], int k,  Graph<int,int> *g1, Graph<int,int> *g2);
void Permuta(int v[], int inicio, int n, Graph<int,int> *g1, Graph<int,int> *g2);

#endif /* defined(__IsoForcaB__algofatorial__) */
