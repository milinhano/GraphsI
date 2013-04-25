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

void Imprima(int s[], int k) {
    // int i;
    printf("\n");
    //int nodes = numVer;
    int ** mAdjAux;
    mAdjAux = new int *[numVer];
    for (int i = 0; i < numVer; i++) {
        mAdjAux[i] = new int [numVer];
    }
    
    //for (int p=1; p<=k; p++){
    for (int i=0, p1 = 1 ; i < numVer ; i++, p1++) {
        for (int j=0, p2 =1; j < numVer; j++, p2++) {
            //cout << "i = " << i << " j = " << j << " s[p1] -1= " << s[p1]-1 << " s[p2]-1 = " << s[p2]-1 << endl;
            //if(i==j)mAdjAux[i][j] = 0;
            //else{
                mAdjAux[i][j] = mAdjG2[s[p1]-1][s[p2]-1];
                //aux[i][j] = x;
                cout << mAdjAux[i][j]<< " ";
            //}
            //        int x = g2->getAdja(s[p1]-1, s[p2]-1);
            //      aux[i][j] = x;
            //cout << aux[i][j] << " ";
        }
        cout << endl;
    }
    
    //}//printf("%4d", s[p]);
    cout << "Verificar se mAdjG1 e mAdjAux sao iguais" << endl;
    bool igual = true;
    for (int i=0 ; i < numVer ; i++) {
        for (int j=0; j < numVer; j++) {
            cout << i << " " << j << endl;
            cout << mAdjAux[i][j] << endl;
            cout << mAdjG1[i][j] << endl;
            if(mAdjAux[i][j] !=  mAdjG1[i][j]){
                igual = false;
                break;
            }
        }
        if(igual == false) break;
    }
    if(igual == false) cout << "Nao sao iguais";
    
}

// função Permuta
void Permuta(int v[],int inicio, int n)
{
    Imprima(v, n);
    if (inicio<n)
    {
        int i,j;
        for(i=n-1; i>=inicio; i--)
        {
            for(j=i+1; j<=n; j++)
            {
                Troca(v,i,j);
                Permuta(v,i+1,n);
            }
            Gira_Esquerda(v,i,n);
        }
    }
}


