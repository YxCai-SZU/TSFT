#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) > 0 && (n) <= 100000 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> 1 <= (h)[i] <= 1000000000);
    ensures \result >= 0;
*/
int func(size_t n, int *h)
{
    int dist_max = 0;
    int dist = 0;
    int prev = 0;
    size_t i = 0;
    
    //@ ghost int *ghost_h = h;
    //@ ghost size_t ghost_n = n;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= dist <= (int)i;
        loop invariant 0 <= dist_max <= (int)i;
        loop invariant ((ghost_n) > 0 && (ghost_n) <= 100000 &&
        \valid((ghost_h) + (0 .. (ghost_n)-1)) &&
        \forall size_t i; 0 <= i < (ghost_n) ==> 1 <= (ghost_h)[i] <= 1000000000);
        loop invariant \forall size_t k; 0 <= k < ghost_n ==> 1 <= ghost_h[k] <= 1000000000;
        loop assigns i, dist, dist_max, prev;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        
        if (h[i] <= prev) {
            dist = dist + 1;
            //@ assert dist >= 0;
            
            if (i == n - 1) {
                if (dist > dist_max) {
                    dist_max = dist;
                }
                //@ assert dist_max >= 0;
            }
        } else {
            if (dist > dist_max) {
                dist_max = dist;
            }
            //@ assert dist_max >= 0;
            dist = 0;
        }
        
        prev = h[i];
        i = i + 1;
    }
    
    //@ assert dist_max >= 0;
    return dist_max;
}
