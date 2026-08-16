#include <stdbool.h>
#include <stddef.h>

/*@
requires ((n) >= 1 && (n) <= 100000 &&
    (k) >= 1 && (k) <= 500 &&
    \valid((h) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
assigns \nothing;
ensures \result <= n;
*/
unsigned int func(unsigned int n, unsigned int k, unsigned int *h) {
    unsigned int count = 0;
    unsigned int index = 0;
    
    /*@
    loop invariant (0 <= (index) && (index) <= (n) &&
    0 <= (count) && (count) <= (index) &&
    \valid((h) + (0 .. (n)-1)) &&
    \forall integer j; 0 <= j < (index) ==> ((k) <= (h)[j] ? (count) >= 1 : \true));
    loop assigns index, count;
    loop variant n - index;
    */
    while (index < n) {
        //@ assert (0 <= (index) && (index) <= (n) &&     0 <= (count) && (count) <= (index) &&     \valid((h) + (0 .. (n)-1)) &&     \forall integer j; 0 <= j < (index) ==> ((k) <= (h)[j] ? (count) >= 1 : \true));
        
        if (k <= h[index]) {
            count++;
        }
        index++;
        
        //@ assert (0 <= (index) && (index) <= (n) &&     0 <= (count) && (count) <= (index) &&     \valid((h) + (0 .. (n)-1)) &&     \forall integer j; 0 <= j < (index) ==> ((k) <= (h)[j] ? (count) >= 1 : \true));
    }
    
    //@ assert count <= n;
    return count;
}
