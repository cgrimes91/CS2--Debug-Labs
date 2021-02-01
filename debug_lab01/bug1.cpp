///////////////////////////////////////////////////////////////////////////
//  bug1.cpp
//   
// 
//   Created by jmaletic on 9/9/13.
// 
//   This code prints out a sets of random numbers, no duplicates per set.
//
//   There is a bug in this code.  It compiles but seems to get into an infinit loop.
//   Find the bug.
//
//   Step 1: Compile the program clang++ -Wall bug1.cpp -o buggy
//           Run it ./buggy  ctrl c to break it.
//   Step 2: Read over the code and figure out what it does a bit.
//           Insert print statements into the different loops to 
//           determine where the infinite loop is occurring.
//           Start in the main and work down the call stack.
//   Step 3: Once you figure out what loop is the problem try to 
//           figure out what it is supposed to do and why its broken.
//   Step 4: Make the fix and compile/run the program
//   Step 5: Does it work?  



#include <iostream>
#include <cstdlib>

const int MAX             = 6;
const int SIZE_OF_SAMPLES = 3;
const int REP             = 5;

bool inArray     (int[], int, int  ); // tells if num is already present in array
void UniqRandInt (int,   int, int[]); // make arrary of ints



///////////////////////////////////////////////////////////////////////////
int main() {
  // std::cerr<<"in main\n";

    int arr[SIZE_OF_SAMPLES];
    
    srand(9809);  //Seed random number generator.
    

    for (int i = 0; i < REP; i++) {
      // std::cerr<<"in first for loop main"<< std::endl;
        UniqRandInt(MAX, SIZE_OF_SAMPLES, arr);
        for(int j = 0; j < SIZE_OF_SAMPLES; j++) {
	  // std::cerr<<"in second for loop main"<< std::endl;
            std::cout << arr[j] << " ";
        }
        std::cout << std::endl;
    }
    // std::cerr<< "end main"<<std::endl;
    return 0;
}
// max==6 size_of_samples==3 rep==5
///////////////////////////////////////////////////////////////////////////
// result[n] will be initialized with a set of random numbers, no duplicates
//           Values between 0 and max.
// max==6  n==3 result==arr
void UniqRandInt(int max, int n, int result[]) {

    int cntr = 0, r;
    // std:: cerr<<"in unique rand int"<<std::endl;
    while(cntr < n) {
      // std::cerr<<" in while loop unique rand"<<std::endl;
        r = rand();  //Get random number
        r = r % (max + 1);
        if (!(inArray(result, cntr, r))) {
	  // std::cerr<<"in if loop unique rand"<<std::endl;
           result[cntr] =  r;
	     cntr++;
        }
    }
    return;
}

///////////////////////////////////////////////////////////////////////////
// Check if x is included in array[] of arrSize.
// Returns: 1 if x is a member
//           0 if x is not a member
// 
bool inArray(int array[], int arrSize, int x) {
  // std::cerr<<" in array funct"<<std::endl; 
  for (int i = 0; i < arrSize; ++i) {
    // std::cerr<<"in for loop in array funct"<<std::endl;   
    if (array[i] == x) {
      // std::cerr<<"in if loop in array funct"<<std::endl;
            return true;
        }
    }
    return false;
}
