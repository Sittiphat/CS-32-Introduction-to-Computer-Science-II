#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include <cassert>

using namespace std;

const int MAXRESULTS   = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

void makePermutations(const string dict[], string results[], int& size, string prefix, string rest, int& count);
void loop(const string dict[], string results[], size_t i, int rest_size, string prefix, string rest, int& count, int& size);
int insertResults(const string dict[], string results[], int size, string prefix, int& count);
bool isRepeat(string results[], size_t i, int& count, string prefix);


int dictCreation(istream &dictfile, string dict[], int max_size) {
    string line;
    int i = 0;

    // If we are able to read the line in file and it has not yet reached MAXDICTWORDS,
    // then we keep on adding words to the dict[] array
    if (getline(dictfile, line) && max_size > 0) {
      dict[0] = line;
      i++;
    } else
      return 0; // If we have reached our array size limit, we stop accumulating sum
      // of the number of items in the dict[] array

    // We keep on adding to our element size through head recursion of dict file,
    // decrementing MAXDICTWORDS until we reach its base case to stop adding elements
    return i + dictCreation(dictfile, dict + 1, max_size - 1);
}

// We pass in an input stream from a file we delcare on main
// The inner recursive function eventually returns element size of the array
int createDict(istream &dictfile, string dict[]) {
  return dictCreation(dictfile, dict, MAXDICTWORDS); // This recursive function passes MAXDICTWORDS so that it can be a base case
}

// Copies all distinct permutations that are anagrams in results[] array and returns its element size
int characterMixer(string word, const string dict[], int size, string results[]) {
  string prefix = ""; // Our algorithm will create all undistinct string permutations
  string rest = word; // into prefix from rest through a char swap algorithm
  int count = 0;

  makePermutations(dict, results, size, prefix, rest, count); // Recursively creates all string permutations
  return count; // Returns the count
}

// Creates all possible string permutations, similar to the Spec FAQ example
void makePermutations(const string dict[], string results[], int& size, string prefix, string rest, int& count) {
  if (rest.size() == 0) { // When prefix is filled and rest is empty, we have a permuation
    // cerr << prefix << endl; // An anagram posibility
    if (count >= MAXRESULTS) { // If we pass results[] max array size we stop and return
      return;
    }
    count += insertResults(dict, results, size, prefix, count);

  } else { // Emulates for loop as described per Spec FAQ
    loop(dict, results, 0, rest.size(), prefix, rest, count, size);
  } // We begin at 0 and increment until we reach the word's string size
}

// Takes the parameters similar to what we find inside a for loop with statement values we usually would need
// inside of a for loop
void loop(const string dict[], string results[], size_t i, int rest_size, string prefix, string rest, int& count, int& size) { // Merge in loop
  if (i >= rest_size) {
    return;
  }
  // Creates mutual recursion to emulate for loop. Therefore, our first recursive loop switches the first element
  // The second loop swaps all second elements after inititating the first element swap from first recursive for loop
  // If we are dealing with a three element string then we get the permutation or repeat this process until we reach last element
  makePermutations(dict, results, size, prefix + rest[i], rest.substr(0, i) + rest.substr(i + 1, rest.size() - 1), count);
  loop(dict, results, i + 1, rest_size, prefix, rest, count, size);
}

// TODO: Check MAXRESULTS
// Inserts the distinct anagrams found in the dictionary[] array
int insertResults(const string dict[], string results[], int size, string prefix, int& count) {
  if (size == 0) { // Our base case after decrementing the nWords of dict[] which was passed through recursion earlier in our first recursive functions
    return 0;
  }

  if (prefix == dict[0]) {
    if (isRepeat(results, 0, count, prefix)) { // If it is a repeat we do not add the string permutation to the result array and do not accumulate our recursion counter, returning 0
      return 0;
    } else {
      // cerr << "Result arr:" << prefix << endl; // Save element into result array
      results[count] = prefix;
      return 1; // After adding to the result array we accumulate the result element count
    }
  } else // We keep looking through the dict[] array if we do not find a match until we go through it all or reach MAXRESULTS
    return insertResults(dict + 1, results, size - 1, prefix, count);
}

// Checks to see if we are met with string permutations that repeat because of consecutive same adjacent characters
bool isRepeat(string results[], size_t i, int& count, string prefix) {
  if (i >= count) { // Once we get past result element size, we know there is no longer a possible of repeats
    return false;
  } else if (prefix == results[0]) {
    return true; // If the prefix is the same as result it is a repeat
  } else
    return isRepeat(results + 1, i + 1, count, prefix); // i gets closer to the base case of reaching count which is the result array's element size
}

// View our anagram matches after looking through the dictionary
void viewAnswers(const string results[], int size) {
  if (size == 0) { // The base case after recursively decrementing results[] element size
    return;
  }

  cout << "Matching word " << results[0] << endl; // User prompt per Specs

  // Decrement size to reach base and increment array to view next element
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
      return (1);
  }

  nwords = createDict(dictfile, dict);

  // cerr << nwords << endl; // Number of elements in dict[]

  // for (size_t i = 0; i < 25144; i++) {
  //   cerr << dict[i] << '\n';
  // }
  // results[0] = "hello";
  // results[1] = "goodbye";

  cout << "Please enter a string for an anagram: ";
  cin >> word;

  int numMatches = characterMixer(word, dict, nwords, results);
  // cerr << numMatches << endl; // Number of elements in results[]
  if (!numMatches)
      cout << "No matches found" << endl;
  else
      viewAnswers(results, numMatches);

  // string exampleDict[] = {"kool", "moe", "dee"};
  // int numResults = characterMixer("kloo", exampleDict, 3,
  // results);
  // assert(numResults == 1 && results[0] == "kool");

  return 0;
}
