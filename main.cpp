//
//  main.cpp
//  Isomorfismo
//
//  Created by Camila Taumaturgo on 21/04/13.
//  Copyright (c) 2013 Camila Taumaturgo. All rights reserved.
//

#include <iostream>
#include "graph.h"
#include "auxiliar.h"

#define PESO 0

/* >>>>>>>>>> GLOBAL VARIABLE DECLARATIONS <<<<<<<<<< */

int ** mAdjG1;
int ** mAdjG2;
int numVer; //numero total de vertices -  só iremos testar quando o numero de vertices forem igual
int numArG1 = 0; //numero de arestas
int numArG2 = 0; //numero de arestas
//OBS: Quando o numero de arestas forem diferentes, tb podemos dizer que os grafos naum sao isomorfos

/* ------ END OF GLOBAL VARIABLE DECLARATIONS ------- */

using namespace std;

int main(int argc, const char * argv[])
{
    
    //Sera feita a leitura das matrizes de adjacencia
    //eh necessario ler apenas a matriz inferior a diagonal principal
    //o nome do arquivo é passado como argumento Ex ./grafo g1
    
    if (argc != 2) {
		cout << "The program could not be initialized due to a parameter error. To execute this program use:" << endl;
		cout << ".\\graph g1" << endl;
		exit (1);
	}
    
    bool resp;
    
	resp = readInstance (argv[1]);
	if (!resp) {
		cout << "It was not possible to read the instance file.\nVerify the file and try again.\nThe program will be finished." << endl;
		exit (1);
	}

    if(numArG1 != numArG2){
        cout << "Os grafos naum sao isomorfos. Numero de arestas diferentes." << endl;
        return true;
    }

    
    //Ao construir o grafo seria mais interessante apenas passar o número de vértices
    Graph<int,double> graph1(numVer,numArG1);
    Graph<int,double> graph2(numVer,numArG1);

    
    cout << "-------------GRAPH 1" << endl;
    for(int i = 0; i < numVer; i++){
        for(int j = 0; j < numVer; j++){
            if( j < i ) {
                if( mAdjG1[i][j] == 1)
                    graph1.addEdge(Vertex<int>(i,i), Vertex<int>(j,j), 10);
            }
            else break;
        }
    }
    cout << graph1 << endl;
    
    cout << "-------------GRAPH 2" << endl;
    for(int i = 0; i < numVer; i++){
        for(int j = 0; j < numVer; j++){
            if( j < i ) {
                if( mAdjG2[i][j] == 1)
                    graph2.addEdge(Vertex<int>(i,i), Vertex<int>(j,j), 10);
            }
            else break;
        }
    }
    cout << graph2 << endl;
    
      
    return 0;
}

