//
//  auxiliar.h
//  Isomorfismo
//
//  Created by Camila Taumaturgo on 22/04/13.
//  Copyright (c) 2013 Camila Taumaturgo. All rights reserved.
//

#ifndef Isomorfismo_auxiliar_h
#define Isomorfismo_auxiliar_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

extern int ** mAdjG1;
extern int ** mAdjG2;
extern int numVer;
extern int numArG1;
extern int numArG2;


bool readInstance (const char * );
void Troca(int v[],int i,int j);
void Gira_Esquerda(int v[],int go, int n);
void Imprima(int s[], int k);
void Permuta(int v[], int inicio, int n);


#endif
