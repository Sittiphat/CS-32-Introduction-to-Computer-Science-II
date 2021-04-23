//
//  main.cpp
//  Project2_CS32
//
//  Created by Sowmya Sridharan on 7/14/17.
//  Copyright © 2017 project. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
using namespace std;
const int MAXRESULTS   = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

void printPermutations (string prefix, string rest, const int&size, int& count, const string dict[], string results[]);
bool duplicate(string goal, string results[], int begin, int max);
int dictionary (string goal,  int size,const string dict[], string results[], int& count, string result_arr[]);

int readDictionary(istream &dictfile, string dict[])
{
    string word;
    dictfile>>word;
    if (dictfile.eof()) return 0;
    else
    {
        *dict=word;
        return 1 + readDictionary(dictfile, dict+1);
    }
    return 0;
}

void loop(int& count, const int&size, string results[], const string dict[], string prefix, string rest, int max, int x)//loop to avoid inner for loop in printPermutations function
{
    if (x >= max) return;
    printPermutations(prefix+rest[x], rest.substr(0,x)+rest.substr(x+1), size, count, dict, results);//adds character to prefix and deletes the character from rest
    loop(count, size, results,dict,prefix,rest,max,x+1);//recursion generated with updated values

}
void printPermutations (string prefix, string rest, const int& size, int& count, const string dict[], string results[])
{
    if (rest.length()==0) {
      cout << prefix << endl;
      count+=dictionary(prefix,size, dict, results,count, &results[count]);//if rest is empty
    }
    else
    {
        int l = rest.length();
        loop(count,size,results,dict,prefix,rest,l,0);//calling internal loop created above to avoid for loop
    }
}
int dictionary (string goal,  int size,const string dict[], string results[], int& count, string result_arr[])
{
    if (size==0) return 0;
    if (goal==*dict)//if match found
    {
        if(duplicate(goal,results, 0, count)) return 0;//checks for duplicates
        else {
          cout << "Result arr:" << goal << endl;
          *result_arr = goal;
          return 1;
          // return 1+dictionary(goal,size-1,dict+1, results, count, result_arr+1);
        }
    }
    else return dictionary(goal,size-1,dict+1,results,count,result_arr);
}
bool duplicate(string goal, string results[], int begin, int max)//checking for duplicates when rearranging letters
{
    if (begin >= max) return false;
    if (goal==*results) return true;
    else return duplicate(goal,results+1,begin+1, max);
}
int recursivePermute(string word, const string dict[], int size, string results[])
{
    int count = 0;
    printPermutations("",word,size,count,dict,results);
    return count;
}

void recurPrint(const string results[], int size)
{
    if (size==0) return;
    else {
        cout << "Matching word" << *results << endl;
        recurPrint(results+1, size+1);
    }

}


int main()
{
    string results[MAXRESULTS];
    string dict[MAXDICTWORDS];
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;

    dictfile.open("words.txt");
    if (!dictfile) {
        cout << "File not found!" << endl;
        return (1);
    }

    nwords = readDictionary(dictfile, dict);


    cout << "Please enter a string for an anagram: ";
    cin >> word;

    int numMatches = recursivePermute(word, dict, nwords, results);
    cout << numMatches << endl;
    for (size_t i = 0; i < 20; i++) {
      cout << results[i] << endl;
    }
    // if (!numMatches)
    //     cout << "No matches found" << endl;
    // else
    //     recurPrint(results, numMatches);
}
