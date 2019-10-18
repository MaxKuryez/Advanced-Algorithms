#include <iostream>
#include <string>

using namespace std;

int CharState(string pat, int StateNum, int state, int CharN);
void TheCartProd(string pat, int StateNum, int **TF);
int FSM(string pat, string text);

int main(){
string pat = "lol";
string text = "loloolololo";

cout<<FSM(pat,text);

}

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
