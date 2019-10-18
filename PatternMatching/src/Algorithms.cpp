#include "Algorithms.h"

///FSM

int CharState(string pat, int StateNum, int state, int CharN)
{
    if (state < StateNum && CharN == pat[state])
        return state+1;
    int StatePoint, i;

    for (StatePoint = state; StatePoint > 0; StatePoint--)
    {
        if (pat[StatePoint-1] == CharN)
        {
            for (i = 0; i < StatePoint-1; i++)
                if (pat[i] != pat[state-StatePoint+1+i])
                    break;
            if (i == StatePoint-1)
                return StatePoint;
        }
    }

    return 0;
}


void TheCartProd(string pat, int StateNum, int **TF)
{
    int state, CharN;
    for (state = 0; state <= StateNum; ++state)
        for (CharN = 0; CharN < 255; ++CharN)
            TF[state][CharN] = CharState(pat, StateNum, state, CharN);
}


int FSM(string pat, string text)
{
    int StateNum = pat.size();
    int N = text.size();
    int match = 0;

    int** TF = new int*[StateNum+1];
    for(int i = 0; i < StateNum+1; ++i)
      TF[i] = new int[255];

    TheCartProd(pat, StateNum, TF);
    int i, state=0;
    for (i = 0; i < N; i++)
    {
        state = TF[state][text[i]];
        if (state == StateNum){
            match++;
        }
    }
    return match;
}

///Hash

size_t const S = 256;
size_t const W = 997;

size_t Hash(string text,int len){
size_t h = 0;
for (int k = 0; k <len; k++)
    h = ((h*S)%W + text[k])%W;
return h;
}

size_t ReHash(size_t Spow, char newC, char oldC, size_t oldhash){
oldhash = (oldhash - (oldC * Spow)%W + W)%W;
oldhash = (oldhash*S%W + newC)%W;
return oldhash;
}

int LetsHash(string text, string pat){
 int match = 0;
 size_t PatHash = Hash (pat, pat.size());
 size_t TextHash;
 size_t Spow = PowerMod(S,pat.size() - 1);
 //cout<<"The power of S:"<<Spow<<endl;
 for (int i = 0; i < text.size(); i++){
    if (i == 0)
       TextHash = Hash (text, pat.size());
    else
       TextHash = ReHash(Spow,text[i + pat.size() - 1], text[i - 1], TextHash);
    if (PatHash == TextHash){
        match++;
        for (int j = 0; j < pat.size(); j++){
             if (text[i+j] != pat[j]){
                 match--;
                 break;
             }
        }
    }
 }
 return match;
}

size_t PowerMod(size_t n, size_t m){
size_t res = 1;
for (int i = 0 ; i < m; i++)
     res = (res * n )% W;
return res;
}

///KMP

void preKmp(string x, int m, int *kmpNext) {
  int i = 0;
  int j = kmpNext[0] = -1;

   while (i < m) {
      while (j > -1 && x[i] != x[j])
         j = kmpNext[j];
      i++;
      j++;
      if (x[i] == x[j])
         kmpNext[i] = kmpNext[j];
      else
         kmpNext[i] = j;
   }
}


int KMP(string x, string y) {

   int i = 0;
   int j = 0;
   int match = 0;
   int *kmpNext = new int[x.size()]();
   preKmp(x, x.size(), kmpNext);


   while (j < y.size()) {
      while (i > -1 && x[i] != y[j])
         i = kmpNext[i];
      i++;
      j++;
      if (i >= x.size()) {
         match++;
         i = kmpNext[i];
      }
   }
   return match;
}

///Sunday

int Sunday(string text, string pat)
{
      bool Map[256] = {false};
      for (int i = 0; i< pat.size(); i++)
      {
          Map[pat[i] - 97] = true;
      }

     int match = 0;
   for (int i = 0; i < text.size(); i++)
   {
         if (text[i] == pat[0])
         {

             match++;
             int i_tmp = i + 1;
             for (int it_2 = 1; it_2 < pat.size(); it_2++)
             {
                  if (text[i_tmp] != pat[it_2])
                      {
                          match--;
                          if (!Map[text[i + pat.size()] - 97])
                            {
                                   if ( i + pat.size() < text.size() - pat.size() - 1){
                                   i = i + pat.size();
                                    }
                             }
                          break;
                      }
                   i_tmp++;
             }
            //cout<< text[i + pat.size()]<<Map[text[i + pat.size()] - 97]<<endl;

         }
         if (!Map[text[i + pat.size()] - 97]&&!Map[text[i]])
            {
                if ( i + pat.size() < text.size() - pat.size() - 1){
                    i = i + pat.size();
                }
            }
   }
   return match;
}

///BruteForce

int BruteForce(string  text, string  pat)
{
   int match = 0;
   for (int i = 0; i < text.size(); i++)
   {
         if (text[i] == pat[0])
         {
             //cout<< text[i],pat[0];
             match++;
             int i_tmp = i + 1;
             for (int it_2 = 1; it_2 < pat.size(); it_2++)
             {
                  if (text[i_tmp] != pat[it_2])
                      {
                          match--;
                          break;
                      }
                   i_tmp++;
             }
         //if (match == true)
         //   break;
         }

   }
   return match;
}
