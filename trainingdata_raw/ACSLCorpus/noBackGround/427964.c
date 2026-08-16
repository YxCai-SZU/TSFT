#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 2 && (n) <= 100000 &&
    \valid((h) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 1000000000);
  assigns \nothing;
  ensures \result >= 0;
*/
int func(int n, int *h) {
    int dist;
    int max_dist;
    int i;
    int result;
    
    dist = 0;
    max_dist = 0;
    i = 1;
    
    /*@ loop invariant (1 <= (i) <= (n) &&
    (dist) >= 0 && (max_dist) >= 0 &&
    (dist) <= (i) && (max_dist) <= (i) &&
    (((n)) >= 2 && ((n)) <= 100000 &&
    \valid(((h)) + (0 .. ((n))-1)) &&
    \forall integer i; 0 <= i < ((n)) ==> ((h))[i] >= 1 && ((h))[i] <= 1000000000));
        loop assigns dist, max_dist, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert dist >= 0;
        
        if (h[i - 1] >= h[i]) {
            dist = dist + 1;
        } else {
            if (dist > max_dist) {
                max_dist = dist;
            }
            dist = 0;
        }
        
        i = i + 1;
    }
    
    if (dist > max_dist) {
        max_dist = dist;
    }
    
    result = max_dist;
    
    //@ assert result >= 0;
    return result;
}
