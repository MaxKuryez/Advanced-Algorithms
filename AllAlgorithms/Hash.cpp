#include <iostream>
#include <string>

using namespace std;
size_t Hash(string,int);
int LetsHash(string, string);
size_t PowerMod(size_t n, size_t m);
size_t ReHash(size_t Spow, char newC, char oldC, size_t oldhash);


int main(){

string pattern = "funf";
string text = "funfunfunf";

cout<<LetsHash(text, pattern);
}

size_t const S = 128;
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
