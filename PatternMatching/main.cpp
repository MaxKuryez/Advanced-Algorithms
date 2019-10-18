#include <iostream>
#include <string>
#include "Algorithms.h"
#include <fstream>
#include <streambuf>
#include <chrono>
#include <windows.h>
#include <iomanip>

using namespace std;

int main()
{


string pat = "jnljl";
//string text = "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj";
ifstream fin("C:\\Users\\HP\\Desktop\\AdvancedAlgProj\\Text.txt");
ofstream res("C:\\Users\\HP\\Desktop\\AdvancedAlgProj\\Result10.txt");
string text((istreambuf_iterator<char>(fin)),
                 istreambuf_iterator<char>());
//cout<<text;


double freq = 0.0;
    LARGE_INTEGER x;
    QueryPerformanceFrequency(&x);
    freq = x.QuadPart/1000.0;

cout<<text.size()<<endl;
QueryPerformanceCounter(&x);
std::int64_t start = x.QuadPart;
FSM(pat,text);
QueryPerformanceCounter(&x);
std::int64_t end = x.QuadPart;
std::int64_t taken = end - start;
cout<<"FSM: "<< std::setw(8) << std::fixed << " " << " " <<taken / freq<< std::endl;

QueryPerformanceCounter(&x);
start = x.QuadPart;
LetsHash(text,pat);
QueryPerformanceCounter(&x);
end = x.QuadPart;
taken = end - start;
cout<<"Hash: "<< std::setw(8) << std::fixed << " " << " " <<taken / freq<< std::endl;
cout<<endl;


QueryPerformanceCounter(&x);
start = x.QuadPart;
Sunday(text,pat);
QueryPerformanceCounter(&x);
end = x.QuadPart;
taken = end - start;
cout<<"Sunday: "<< std::setw(8) << std::fixed << " " << " " <<taken / freq<< std::endl;
cout<<endl;


QueryPerformanceCounter(&x);
start = x.QuadPart;
//KMP(pat,text);
LetsHash(text,pat);
QueryPerformanceCounter(&x);
end = x.QuadPart;
taken = end - start;
cout<<"Hash: "<< std::setw(8) << std::fixed << " " << " " <<taken / freq<< std::endl;
cout<<endl;

QueryPerformanceCounter(&x);
start = x.QuadPart;
BruteForce(text,pat);
QueryPerformanceCounter(&x);
end = x.QuadPart;
taken = end - start;
cout<<"BruteForce: "<< std::setw(8) << std::fixed << " " << " " <<taken / freq<< std::endl;
cout<<endl;





}
