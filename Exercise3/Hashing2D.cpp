#include <iostream>
#include <string>

using namespace std;

void Hash(string*,int*,int,int);
void Rehash(string *, int *, int, int, int);
int ExtHash(int*, int, int);   ///external hashing
int ReExtHash(int*,int,int,int);
bool Lets2DHash(string*, string*, int ,int);
size_t PowerMod(size_t n, size_t m);

int main(){
int TextLeng = 4; /// For convenience my text would be also a square
int PatLeng = 2;
int *H = new int[TextLeng]();
int *A = new int[PatLeng]();
string text[TextLeng] = {"adoaa","aona","aaaa","aaaa"};
string pat[PatLeng] = {"do","on"};
cout<<Lets2DHash(text,pat,TextLeng,PatLeng);
}

size_t const S = 257;
unsigned int P = 1023;

void Hash(string *text,int *H,int hei, int len){
for (int i = 0; i < hei; i++){
  for (int k = 0; k < len; k++){
      H[i] = ((H[i]*S) + text[i][k])&P;

  }
}
}

void Rehash(string *text, int *OldH, int hei, int len, int index){
    int Spow = PowerMod(S,len - 1);
for (int i = 0; i < hei; i++){
   OldH[i] = (OldH[i] - (text[i][index] * Spow) + P + 1)&P;
   OldH[i] = (OldH[i]*S + text[i][index + len])&P;
}
}

int ExtHash(int* Hash ,int len, int index){
int ExtH = 0;
for (int i = 0; i < len; i++){
    ExtH = ((ExtH*S) + Hash[i+index])&P;
}
return ExtH;
}

int ReExtHash(int* Hash ,int OldH, int len, int index){
  int Spow = PowerMod(S,len - 1);
  OldH = (OldH - (Hash[index]*Spow) + P + 1)&P;
  OldH = (OldH*S + Hash[index + len])&P;
  return OldH;
}

bool Lets2DHash(string * text, string * pat, int TextLeng, int PatLeng){

bool Match = false;
int *A = new int[PatLeng]();
Hash(pat,A,PatLeng,PatLeng);
int PatHash = ExtHash(A,PatLeng,0);
int TextHash;
int *H = new int[TextLeng]();

for (int i = 0; i < TextLeng - PatLeng + 1; i++){

    if (i == 0)
      Hash(text, H, TextLeng, PatLeng);
    else
      Rehash(text,H,TextLeng,PatLeng,i - 1);
    for (int j = 0; j < TextLeng - PatLeng + 1; j++){
      if (j == 0)
        TextHash = ExtHash(H,PatLeng,0);
      else
        TextHash = ReExtHash(H,TextHash,PatLeng,j - 1);
      if (TextHash == PatHash){
        cout<<"Column: "<<i<<"Row: "<<j<<endl;
        Match = true;
        for (int k = 0; k < PatLeng; k++){
            for (int p = 0; p < PatLeng; p++)
                if (text[k+j][p+i] != pat[k][p]){
                    Match = false;                     ///checking part
                    break;
                }
             if (Match == false)
                break;
        }
      }
    }
}
return Match;
}

size_t PowerMod(size_t n, size_t m){
size_t res = 1;
for (int i = 0 ; i < m; i++)
     res = (res * n )&P;
return res;
}
