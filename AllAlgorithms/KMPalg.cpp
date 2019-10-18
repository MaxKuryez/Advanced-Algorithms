#include <iostream>
#include <string>

using namespace std;

int KMP(string x, string y);
void preKmp(string x, int m, int *kmpNext);

int main(){

   string pat = "lol";
   string text = "lololololklolol";
   cout<<KMP(pat,text);

}

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

