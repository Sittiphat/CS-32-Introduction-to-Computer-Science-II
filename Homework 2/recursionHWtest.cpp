#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int product(unsigned int m, unsigned int n);
int digitCount(int num, int digit);
string terribleTriplets(string n);
string hipToBeSquare(string str);
bool summerSolstice(const int a[], int size, int target);
bool isThisTheEnd(string maze[], int nRows, int nCols,
int sr, int sc, int er, int ec);

int main() {

  int arr[] = {2, 4, 8};
  int empty[] = {};

  assert(product(5, 3) == 15);
  assert(product(5, 1) == 5);
  assert(product(1, 5) == 5);
  assert(product(0, 0) == 0);
  assert(product(1, 1) == 1);
  assert(product(1, 100) == 100);
  assert(product(100, 1) == 100);
  assert(product(100, 100) == 10000);

  assert(digitCount(18838, 8) == 3);
  assert(digitCount(55555, 3) == 0);
  assert(digitCount(0, 0) == 0);
  assert(digitCount(900009, 9) == 2);

  assert(terribleTriplets("goodbye") == "go333odbye");
  assert(terribleTriplets("yyuu") == "y333yu333u");
  assert(terribleTriplets("aaaa") == "a333a333a333a");
  assert(terribleTriplets("happy") == "hap333py");

  assert(hipToBeSquare("abc[ghj]789") == "[ghj]");
  assert(hipToBeSquare("[x]7") == "[x]");
  assert(hipToBeSquare("4agh[y]") == "[y]");
  assert(hipToBeSquare("4agh[]") == "[]");

  assert(summerSolstice(arr, 3, 10) == true);
  assert(summerSolstice(arr, 3, 6) == true);
  assert(summerSolstice(arr, 3, 11) == false);
  assert(summerSolstice(arr, 3, 0) == true);
  assert(summerSolstice(empty, 0, 0) == true);

  // cout << terribleTriplets("happy") << endl;
  // cout << hipToBeSquare("4agh[y]") << endl;
  // cout << summerSolstice(arr, 3, 12) << endl;

  cout << "Passed Tests!" << endl << endl;


  string maze[10] = {
    "XXXXXXXXXX",
    "X.......@X",
    "XX@X@@.XXX",
    "X..X.X...X",
    "X..X...@.X",
    "X....XXX.X",
    "X@X....XXX", // Middle of this line (6,4)
    "X..XX.XX.X",
    "X...X....X",
    "XXXXXXXXXX"
    };
  if (isThisTheEnd(maze, 10, 10, 6, 4, 1, 1))
    cout << "Solvable!" << endl;
  else
  cout << "Out of luck!" << endl;


  return 0;

}

int product(unsigned int m, unsigned int n) {
  // Under this condition, 0*0 always equals zero
  if (m == 0 || n == 0) {
    return 0;
  }
  if (n == 1) { // Base Case where when n gets to 1 we stop decrementing and begin adding up
    return m;
  }
  // By decremening 1, we get the the base case when m * 1 is m,
  // then through tail recursion we add m back up (n - 1) times
  // eventually giving our total sum,
  return product(m, n - 1) + m;
}

int digitCount(int num, int digit) {
  // Once we have throw away each 10 base, and reached 0, we have
  // gone through every decimal place in num
  if (num == 0) {
    return 0;
  }

  // If one's place is the target digit, we divide by 10
  // to throw that place away and increment 1 to add during tail recursion
  if (num % 10 == digit) {
    return digitCount(num / 10, digit) + 1;
  } else
    return digitCount(num / 10, digit); // If our one's place is not our target digit,
                                        // we just throw away one's place until base case
}

string terribleTriplets(string n) {
  // Base Case where we are left with one char in the substring
  if (n.size() == 1) {
    return n;
  }
  // In the beginning we initialize triplet to empty string
  string triplet = "";
  if (n[0] == n[1]) {
    triplet = "333"; // When we see two consecutive chars, triplet is now "333"
    // While we get ready to append it during our tail recursive calls.
  }
  // Triplet is either empty or not so during tail recursion, it appends it to the
  // string if we deem the substring had consecutive chars. We also need to append the
  // first element of the substring to sandwhich the "333" together.
  return n[0] + triplet + terribleTriplets(n.substr(1));
}


string hipToBeSquare(string str) {
  // if (str[0] == '[' && str[str.size() - 1]) == ']' {
  //   return str;
  // }
  //
  // hipToBeSquare(str.substr(1, size() - 1));


  // First we create substrings continually removing from the front until we hit a left bracket
  if (str[0] == '[') {
    if (str[str.size() - 1] == ']') { // We do the same but now removing from back until we hit right bracket
      return str; // Once we have now have removed both sides through substring we return our target string
    }

    // Makes string shorter from back
    return hipToBeSquare(str.substr(0, str.size() - 1));

    // return str;
  }

  // Makes string shorter from front
  return hipToBeSquare(str.substr(1));




  // if (str[str.size() - 1] == ']') {
  //   return str;
  // }

  // // Makes string shorter from back
  // return hipToBeSquare(str.substr(0, str.size() - 1));
}

bool summerSolstice(const int a[], int size, int target) {

  // This is always true since empty array is zero
   if (target == 0) {
     return true;
   }

   // If size is 0 then it doesn't equal anything
   // Also, this is the base case when we can no longer create subarrays
   if (size == 0) {
     return false;
   }

   // If the first element is not incuded in the sum
   if (summerSolstice(a + 1, size - 1, target)) {
     return true;
     // If the first element is included in the sum
   } else if (summerSolstice(a + 1, size - 1, target - a[0])) {
     return true;
   } else
   return false; // If does not equal to any of above sums we return false

}


bool isThisTheEnd(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {

  maze[sr][sc] = '#'; // Drop a bread crump to mark player has already been there
  if (sr == er && sc == ec)
    return true; // We are at the finish line then return true and chain true returns through tail recursion

  // First condition is to check the bounds, second is to determine if pathway is walkable, and third if we hit a roadblock
  // and need to continue to other directions. Once our base case is true (reaches destination) then we chain
  // true values by popping it back through tail recursion.
  if (sr > 0 && maze[sr-1][sc] == '.' && isThisTheEnd(maze, nRows, nCols, sr - 1, sc, er, ec))
    return true;
  if (sr < (nRows - 1) && maze[sr+1][sc] == '.' && isThisTheEnd(maze, nRows, nCols, sr + 1, sc, er, ec))
    return true;
  if (sc > 0 && maze[sr][sc-1] == '.' && isThisTheEnd(maze, nRows, nCols, sr, sc - 1, er, ec))
    return true;
  if (sc < (nCols - 1) && maze[sr][sc+1] == '.' && isThisTheEnd(maze, nRows, nCols, sr, sc + 1, er, ec))
    return true;

  return false; // If all conditions fail (met roadblocks all 4-directions) we return false.
}
