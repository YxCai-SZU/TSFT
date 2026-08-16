#include <stdbool.h>
#include <limits.h>

/*@
  requires \valid(a + (0..n-1));
  requires ((n) > 0 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= (n));
  assigns \nothing;
  ensures \result >= 0;
*/
int func(int n, int *a) {
    int mindif = INT_MAX;
    int matches = 0;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= matches <= i;
      loop invariant ((n) > 0 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= (n));
      loop assigns i, mindif, matches;
      loop variant n - i;
    */
    while (i < n) {
        int ai = a[i];
        
        //@ assert ai >= 1 && ai <= n;
        
        if (ai > i + 1) {
            matches = matches + 1;
        } else if (mindif == INT_MAX) {
            mindif = ai - 1;
        }
        
        i = i + 1;
    }
    
    //@ assert 0 <= matches <= n;
    
    if (matches > 1 || (matches == 1 && mindif == 0)) {
        return 1;
    } else {
        return 0;
    }
}
