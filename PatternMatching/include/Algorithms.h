#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <string>
#include <iostream>


using namespace std;

///FSM

int CharState(string pat, int StateNum, int state, int CharN);
void TheCartProd(string pat, int StateNum, int **TF);
int FSM(string pat, string text);

///Hash

size_t Hash(string,int);
int LetsHash(string, string);
size_t PowerMod(size_t n, size_t m);
size_t ReHash(size_t Spow, char newC, char oldC, size_t oldhash);

///KMP

int KMP(string x, string y);
void preKmp(string x, int m, int *kmpNext);

///BruteForce

int BruteForce(string , string );

///Sunday

int Sunday(string , string );
#endif // ALGORITHMS_H
