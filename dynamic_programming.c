/* VISHISTA MOTUPALLI
  181210031
  CSE 2ND YEAR */
  
/* UPLOADING DYNMAIC PROGRAMMING
 WITH A WELL KNOWN EXAMPLE PROGRAM:
 EGG DROPPING PUZZLE: The following is a description of the instance of this famous puzzle involving n=2 eggs and a building with k=36 floors.

Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the eggs to break on landing.
 We make a few assumptions:

…..An egg that survives a fall can be used again.
…..A broken egg must be discarded.
…..The effect of a fall is the same for all eggs.
…..If an egg breaks when dropped, then it would break if dropped from a higher floor.
…..If an egg survives a fall then it would survive a shorter fall.
…..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.

If only one egg is available and we wish to be sure of obtaining the right result, 
the experiment can be carried out in only one way. 
Drop the egg from the first-floor window; if it survives, drop it from the second floor window. Continue upward until it breaks.
*/

// OUTPUT: Minimum number of trials in worst case with 2 eggs and 10 floors is 4  
# include <stdio.h> 
# include <limits.h> 
  
// A utility function to get maximum of two integers 
int max(int a, int b) 
{ return (a > b)? a: b; } 
  
/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
int eggDrop(int n, int k) 
{ 
    // If there are no floors, then no trials needed. OR if there is 
    // one floor, one trial needed. 
    if (k == 1 || k == 0) 
        return k; 
  
    // We need k trials for one egg and k floors 
    if (n == 1) 
        return k; 
  
    int min = INT_MAX, x, res; 
  
    // Consider all droppings from 1st floor to kth floor and 
    // return the minimum of these values plus 1. 
    for (x = 1; x <= k; x++) 
    { 
        res = max(eggDrop(n-1, x-1), eggDrop(n, k-x)); 
        if (res < min) 
            min = res; 
    } 
  
    return min + 1; 
} 
  
int main() 
{ 
    int n = 2, k = 10; 
    printf ("nMinimum number of trials in worst case with %d eggs and "
             "%d floors is %d \n", n, k, eggDrop(n, k)); 
    return 0; 
} 

