#include <stdbool.h>
/*@
    requires ((n) >= 1 && (n) <= 100000 &&
        (k) >= 1 && (k) <= 500 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] && (h)[i] <= 500);
    ensures \result >= 0 && \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result >= 1);
    assigns \nothing;
*/
int func(int n, int k, int *h)
{
    int ans = 0;
    unsigned int index = 0;
    //@ ghost int *ghost_h = h;
    //@ ghost int ghost_n = n;
    //@ ghost int ghost_k = k;

    /*@
        loop invariant (0 <= (index) <= (ghost_n) &&
        (ans) >= 0 &&
        (ans) <= (index) &&
        \forall integer i; 0 <= i < (index) ==> ((ghost_h)[i] >= (ghost_k) ==> (ans) >= 1) &&
        (((ghost_n)) >= 1 && ((ghost_n)) <= 100000 &&
        ((ghost_k)) >= 1 && ((ghost_k)) <= 500 &&
        \valid(((ghost_h)) + (0 .. ((ghost_n))-1)) &&
        \forall integer i; 0 <= i < ((ghost_n)) ==> 1 <= ((ghost_h))[i] && ((ghost_h))[i] <= 500));
        loop assigns ans, index;
        loop variant ghost_n - index;
    */
    while (index < (unsigned int)n)
    {
        //@ assert (0 <= (index) <= (ghost_n) &&         (ans) >= 0 &&         (ans) <= (index) &&         \forall integer i; 0 <= i < (index) ==> ((ghost_h)[i] >= (ghost_k) ==> (ans) >= 1) &&         (((ghost_n)) >= 1 && ((ghost_n)) <= 100000 &&         ((ghost_k)) >= 1 && ((ghost_k)) <= 500 &&         \valid(((ghost_h)) + (0 .. ((ghost_n))-1)) &&         \forall integer i; 0 <= i < ((ghost_n)) ==> 1 <= ((ghost_h))[i] && ((ghost_h))[i] <= 500));
        if (h[index] >= k)
        {
            ans += 1;
        }
        index += 1;
    }
    //@ assert ans >= 0 && ans <= ghost_n;
    //@ assert \forall integer i; 0 <= i < ghost_n ==> (ghost_h[i] >= ghost_k ==> ans >= 1);
    return ans;
}
