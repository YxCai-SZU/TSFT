#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
    \valid((hs) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (hs)[i] >= 1 && (hs)[i] <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(size_t n, int *hs) {
    int max = 0;
    size_t index = 0;
    
    //@ ghost int *original_hs = hs;
    //@ ghost size_t original_n = n;
    
    /*@
        loop invariant ((index) <= (original_n) - 1 &&
    (max) >= 0 &&
    (max) <= (index) &&
    (((original_n)) >= 1 && ((original_n)) <= 100000 &&
    \valid(((original_hs)) + (0 .. ((original_n))-1)) &&
    \forall integer i; 0 <= i < ((original_n)) ==> ((original_hs))[i] >= 1 && ((original_hs))[i] <= 100));
        loop invariant index <= original_n - 1;
        loop assigns max, index;
        loop variant original_n - index;
    */
    while (index < n - 1) {
        //@ assert index < n - 1;
        int h1 = hs[index];
        int h2 = hs[index + 1];
        
        //@ assert h1 >= 1 && h1 <= 100;
        //@ assert h2 >= 1 && h2 <= 100;
        
        if (h1 <= h2) {
            max += 1;
        }
        
        index += 1;
    }
    
    //@ assert max >= 0;
    return max;
}
