int characterMixer(string word, string dict[], int size, string results[]) { // Remove const
  string prefix = "";
  string rest = word;
  int count = 0;

  string arr[MAXDICTWORDS];
  // for (size_t i = 0; i < MAXDICTWORDS; i++) { // Fixes const prob?
  //   arr[i] = dict[i];
  // }


  makePermutations(arr, results, prefix, rest, count);
  return count;
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
void makePermutations(string dict[], string results[], string prefix, string rest, int& count) {
  int matches = 0;

  if (rest.size() == 0) {
    cout << prefix << endl; // An anagram posibility
    count += insertResults(dict, results, MAXDICTWORDS, MAXRESULTS, prefix);

  } else {
    loop(dict, results, 0, rest.size(), prefix, rest);
  }

  return matches;
}

// TODO: Check MAXRESULTS, actually work except for 1 element, return result inputs
int insertResults(string dict[], string results[], int dict_size, int results_size, string prefix, int& count) {
  if (dict_size == 0 || results_size == 0) {
    return 0;
  }

  if (isRepeat(results, 0, count, prefix)) {
    return 0;
  }

  if (prefix == dict[0]) {
    results[0] = prefix;
    return 1 + insertResults(dict + 1, results + 1, dict_size - 1, results_size - 1, prefix);
  } else
    return insertResults(dict + 1, results, dict_size - 1, results_size, prefix);

}

bool isRepeat(string results[], size_t i, int count, string prefix) {
  if (i >= count) {
    return false;
  } else if (goal == results[0]) {
    return true;
  } else
    isRepeat(results + 1, i + 1, count, prefix);
}
