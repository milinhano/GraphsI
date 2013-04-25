//
//  main.cpp
//  IsoForcaB
//
//  Created by Camila Taumaturgo on 24/04/13.
//  Copyright (c) 2013 Camila Taumaturgo. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "reader.h"
#include "algofatorial.h"

using namespace std;

int main(int argc, const char * argv[])
{

    Graph<int,int> g1(0,0), g2(0,0);

    reader(argv[1], &g1, &g2);

	if (&g1 == NULL || &g2 == NULL) {
		std::cout << "line " << __LINE__ << "from" << __FILE__ << std::endl;
		exit (1);
	}
    
    //Permutacao de n numeros
    int * s;
    int N, i;
    N = g1.getNumberNodes();
    cout << N << endl;
    //printf("\nentre com n:");
    //scanf("%d",&N);
    s = new int (N);
    // inicia o vetor
    for (i=1; i<=N; i++) s[i] = i;
    Permuta (s, 1, N,&g1,&g2);
    cout << endl;
    
	if (verifyDegree (&g1,&g2)) {
		cout << "São isomorfos" << endl;
	} else {
		cout << "Não São isomorfos" << endl;
	}

    return 0;
}

