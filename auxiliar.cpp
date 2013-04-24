//
//  auxiliar.cpp
//  Isomorfismo
//
//  Created by Camila Taumaturgo on 22/04/13.
//  Copyright (c) 2013 Camila Taumaturgo. All rights reserved.
//

#include "auxiliar.h"



using namespace std;

bool readInstance (const char * instanceF)
{
    string file(instanceF);
    string aux;
//  bool readAll = false;
    
    cout << file << endl;
    
    ifstream infile;
    infile.open(file.c_str());
    
    if (!infile.is_open())
    {
        cerr << endl << "Erro durante a abertura do arquivo de entrada [" << file << "].";
        cout << endl << endl;
        return EXIT_FAILURE;
    }
    
    infile >> numVer; //<! numero de vertices
    getline(infile,aux); //Ler o resto da linha

    
    mAdjG1 = new int *[numVer];
    for (int i = 0; i < numVer; i++) {
        mAdjG1[i] = new int [numVer];
    }
    
    for(int i = 0; i < numVer; i++){
        getline(infile,aux); //Ler a linha toda
         for(int j = 0; j < numVer; j++){
            char s = aux[j]; //
            //cout << "char " << s << endl;
            mAdjG1[i][j] = atoi(&s) ;
            if( (j < i) && (mAdjG1[i][j]==1) )
                numArG1++;
        }
    }

    getline(infile,aux); //<! Linha em branco
    
    mAdjG2 = new int *[numVer];
    for (int i = 0; i < numVer; i++) {
        mAdjG2[i] = new int [numVer];
    }
    
    for(int i = 0; i < numVer; i++){
        getline(infile,aux);
        for(int j = 0; j < numVer; j++){
            //infile >> mAdjG2[i][j];
            char s = aux[j];
            mAdjG2[i][j] = atoi(&s);
            if( (j < i) && (mAdjG2[i][j]==1) )
                numArG2++;
        }
    }

    //Imprimindo as matrizes
    cout << "Grafo G1" << endl;
    for(int i = 0; i < numVer; i++){
        for(int j = 0; j < numVer; j++){
            cout << mAdjG1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Numero de arestas é igual a " << numArG1 << endl;
    
    
    cout << "Grafo G2" << endl;
    for(int i = 0; i < numVer; i++){
        for(int j = 0; j < numVer; j++){
            cout << mAdjG2[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Numero de arestas é igual a " << numArG2 << endl;
    
        infile.close();
    
    
    return true;
    
}

