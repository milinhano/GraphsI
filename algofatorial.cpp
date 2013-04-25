//
//  algofatorial.cpp
//  IsoForcaB
//
//  Created by Camila Taumaturgo on 24/04/13.
//  Copyright (c) 2013 Camila Taumaturgo. All rights reserved.
//

#include "algofatorial.h"
#include <vector>
using namespace std;

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
    
    //	for (int i=0; i < num_nodes; i++) {
    //		if (nodesG1[i] != nodesG2[i]) return false;
    //	}
    
#ifdef DEBUG
	std::cout << "Debug information\n";
    
	g1->xdotToFile ("g1.dot");
    
	std::cout << "Graph 1 degrees\n";
	for (int i=0; i < num_nodes;i++) {
		std::cout << nodesG1[i] << " ";
	}
	std::cout << std::endl;
    
	g2->xdotToFile ("g2.dot");
    
	std::cout << "Graph 2 degrees\n";
    for (int i=0; i < num_nodes;i++) {
        std::cout << nodesG2[i] << " ";
    }
    std::cout << std::endl;
#endif
    
	for (int i=0; i < num_nodes; i++) {
        if (nodesG1[i] != nodesG2[i]) return false;
    }
    
	return true;
    
}

void Troca(int v[],int i,int j)
{
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

// Gira_Esquerda
void Gira_Esquerda(int v[],int go,int n)
{
    int tmp = v[go];
    for (int i=go; i<n; i++)
    {
        v[i] = v[i+1];
    }
    v[n] = tmp;
}

void Imprima(int s[], int k,  Graph<int,int> *g1, Graph<int,int> *g2) {
   // int i;
    printf("\n");
   int nodes = g1->getNumberNodes();
    vector< vector<int> > aux(nodes,vector<int>(nodes));
    
    //for (int p=1; p<=k; p++){
        for (int i=0, p1 = 1 ; i < nodes ; i++, p1++) {
			for (int j=0, p2 =1; j < nodes; j++, p2++) {
                //cout << "i = " << i << " j = " << j << " s[p1] -1= " << s[p1]-1 << " s[p2]-1 = " << s[p2]-1 << endl;
                if(i==j)aux[i][j] = 0;
                else{
                    int x = g2->getAdja(s[p1]-1, s[p2]-1);
                    aux[i][j] = x;
                    cout << aux[i][j] << " ";
                }
        //        int x = g2->getAdja(s[p1]-1, s[p2]-1);
          //      aux[i][j] = x;
                //cout << aux[i][j] << " ";
            }
            cout << endl;
        }
        
    //}//printf("%4d", s[p]);
    
    
}

// função Permuta
void Permuta(int v[],int inicio, int n, Graph<int,int> *g1, Graph<int,int> *g2)
{
    Imprima(v, n, g1, g2);
    if (inicio<n)
    {
        int i,j;
        for(i=n-1; i>=inicio; i--)
        {
            for(j=i+1; j<=n; j++)
            {
                Troca(v,i,j);
                Permuta(v,i+1,n,g1, g2);
            }
            Gira_Esquerda(v,i,n);
        }
    }
}
