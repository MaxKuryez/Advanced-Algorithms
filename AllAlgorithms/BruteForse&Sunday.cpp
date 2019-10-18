#include <iostream>
#include <string>
#include <vector>

using namespace std;

int BruteForce(string , string );
int Sunday(string , string );

int main()
{
  string Text = "lololololo", pat = "lol";
   //65
   //90

  cout<<BruteForce(Text,pat);
  cout<<Sunday(Text,pat);
}

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

int Sunday(string text, string pat)
{
      bool Map[26] = {false};
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
                          break;
                      }
                   i_tmp++;
             }
            //cout<< text[i + pat.size()]<<Map[text[i + pat.size()] - 97]<<endl;
            if (!Map[text[i + pat.size()] - 97]&&!Map[i])
            {
                i += pat.size();
            }
         }

   }
   return match;
}
