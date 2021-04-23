#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

const int MAXRESULTS   = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

void makePermutations(const string dict[], string results[], int size, string prefix, string rest, int& count);
int insertResults(const string dict[], string results[], string preresults[], int size, string prefix, int& count);
bool isRepeat(string results[], size_t i, int count, string prefix);

int dictCreation(istream &dictfile, string dict[], int max_size) {

    string line;
    int i = 0;

    if (getline(dictfile, line) && max_size > 0) {
      dict[0] = line;
      i++;
    } else
      return 0;


    return i + dictCreation(dictfile, dict + 1, max_size - 1);
}

// TODO: Check for MAXDICTWORDS
int createDict(istream &dictfile, string dict[]) {


return dictCreation(dictfile, dict, MAXDICTWORDS);

/*  string line;
  int i = 0;


  if (getline(dictfile, line)) {
    dict[0] = line;
    i++;
  } else
    return 0;

  return i + createDict(dictfile, dict + 1);*/
}

/*// TODO: Return result inputs, make sure they don't repeat removed const? - it is solved with copying array...
int characterMixer(string word, string dict[], int size, string results[]) { // Remove const
  string prefix = "";
  string rest = word;
  int count = 0;

  string arr[MAXDICTWORDS];
  // for (size_t i = 0; i < MAXDICTWORDS; i++) { // Fixes const prob?
  //   arr[i] = dict[i];
  // }


  return makePermutations(arr, results, prefix, rest);
}

// Looks Good
void viewAnswers(const string results[], int size) {
  if (size == 0) {
    return;
  }

  cout << "Matching word " << results[0] << endl;

  viewAnswers(results + 1, size - 1);
}

// This looks good I think
void loop(string dict[], string results[], size_t i, int size, string prefix, string rest) { // Merge in loop
  if (i >= size) {
    return;
  }
  makePermutations(dict, results, prefix + rest[i], rest.substr(0, i) + rest.substr(i + 1, rest.size() - 1));
  loop(dict, results, i + 1, size, prefix, rest);
}

// TODO: Return results inputs
int makePermutations(string dict[], string results[], string prefix, string rest) {
  int matches = 0;

  if (rest.size() == 0) {
    cout << prefix << endl; // An anagram posibility
    if (insertResults(dict, results, MAXDICTWORDS, MAXRESULTS, prefix)) {
      matches++;
    }

  } else {
    loop(dict, results, 0, rest.size(), prefix, rest);
  }

  return matches;
}

// TODO: Check MAXRESULTS, actually work except for 1 element, return result inputs
bool insertResults(string dict[], string results[], int dict_size, int results_size, string prefix) {
  if (dict_size == 0 || results_size == 0) {
    return false;
  }

  if (prefix == dict[0]) {
    results[0] = prefix;
    return true;
    // insertResults(dict + 1, results + 1, dict_size - 1, results_size - 1, prefix);
  } else
    return insertResults(dict + 1, results, dict_size - 1, results_size, prefix);

  return false;
}*/

int characterMixer(string word, const string dict[], int size, string results[]) { // Remove const
  string prefix = "";
  string rest = word;
  int count = 0;

  string arr[MAXDICTWORDS];
  // for (size_t i = 0; i < MAXDICTWORDS; i++) { // Fixes const prob?
  //   arr[i] = dict[i];
  // }


  makePermutations(dict, results, size, prefix, rest, count);
  return count;
}


// This looks good I think
void loop(const string dict[], string results[], size_t i, int rest_size, string prefix, string rest, int& count, int size) { // Merge in loop
  if (i >= rest_size) {
    return;
  }
  makePermutations(dict, results, size, prefix + rest[i], rest.substr(0, i) + rest.substr(i + 1, rest.size() - 1), count);
  loop(dict, results, i + 1, rest_size, prefix, rest, count, size);
}

// TODO: Return results inputs
void makePermutations(const string dict[], string results[], int size, string prefix, string rest, int& count) {
  // int matches = 0;
  // string preresults[count];

  if (rest.size() == 0) {
    cout << prefix << endl; // An anagram posibility
    count += insertResults(dict, results, &results[count], size, prefix, count);

  } else {
    loop(dict, results, 0, rest.size(), prefix, rest, count, size);
  }

  // return matches;
}

// TODO: Check MAXRESULTS, actually work except for 1 element, return result inputs
int insertResults(const string dict[], string results[], string preresults[], int size, string prefix, int& count) {
  if (size == 0) {
    return 0;
  }

  // if (isRepeat(results, 0, count, prefix)) {
  //   return 0;
  // }

  if (prefix == dict[0]) {
    if (isRepeat(results, 0, count, prefix)) {
      return 0;
    } else {
      cout << "Result arr:" << prefix << endl;
      preresults[0] = prefix;
      return 1;
    }
    cout << "Result arr:" << prefix << endl; // Changing this changes depending on last prog run
    preresults[0] = prefix;
    return 1 + insertResults(dict + 1, results, preresults + 1, size - 1, prefix, count);
  } else
    return insertResults(dict + 1, results, preresults, size - 1, prefix, count);

}

bool isRepeat(string results[], size_t i, int count, string prefix) {
  // if (i >= count) {
  //   return false;
  // } else if (prefix == results[0]) {
  //   return true;
  // } else
  //   isRepeat(results + 1, i + 1, count, prefix);

  if (i >= count) {
    return false;
  }

  if (prefix == results[0]) {
    return true;
  } else
    return isRepeat(results + 1, i + 1, count, prefix);
}

// Looks Good
void viewAnswers(const string results[], int size) {
  if (size == 0) {
    return;
  }

  cout << "Matching word " << results[0] << endl;

  viewAnswers(results + 1, size - 1);
}


int main() {

  string results[MAXRESULTS];
  string dict[MAXDICTWORDS];
  ifstream dictfile;         // file containing the list of words
  int nwords;                // number of words read from dictionary
  string word;

  dictfile.open("words.txt");
  if (!dictfile) {
     cout << "File not found!" << endl;
     return 1;
  }

  nwords = createDict(dictfile, dict);
  cerr << nwords << endl;
  // for (size_t i = 0; i < 25144; i++) {
  //   cout << dict[i] << '\n';
  // }
  // cout << nwords << endl;

  // results[0] = "hello";
  // results[1] = "goodbye";


  cout << "Please enter a string for an anagram: ";
  cin >> word;

  int numMatches = characterMixer(word, dict, nwords, results);
  cout << numMatches << endl;

  if (!numMatches)
     cout << "No matches found" << endl;
  else
     viewAnswers(results, numMatches);

//   string exampleDict[] = {"kool", "moe", "dee"};
// int numResults = characterMixer("kloo", exampleDict, 3,
// results);
// assert(numResults == 1 && results[0] == "kool");

  return 0;
}
