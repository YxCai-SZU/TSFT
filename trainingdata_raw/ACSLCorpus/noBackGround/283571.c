#include <stdbool.h>
#include <stddef.h>

/*@
    requires 
        (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100 &&
        1 <= (x) && (x) <= (n) - 1 &&
        (len_a) == (m)) &&
        (\forall size_t i; 0 <= i < (len_a) ==> 
            1 <= (a)[i] && (a)[i] <= (n) &&
            (a)[i] != (x));
    ensures 
        \result <= m;
*/
size_t func(size_t n, size_t m, size_t x, int *a, size_t len_a)
{
    size_t l = 0;
    size_t r = 0;
    size_t i = 0;
    
    /*@
        loop invariant (0 <= (i) && (i) <= (len_a) &&
        (l) <= (i) &&
        (r) <= (i) &&
        \forall size_t j; 0 <= j < (i) ==> 
            ((a)[j] > (x) ==> (r) > 0) && 
            ((a)[j] < (x) ==> (l) > 0) &&
            (a)[j] != (x));
        loop assigns i, l, r;
        loop variant len_a - i;
    */
    while (i < len_a) {
        int value = a[i];
        
        //@ assert value != x;
        
        if (value > (int)x) {
            r = r + 1;
            //@ assert r > 0;
        }
        
        if (value < (int)x) {
            l = l + 1;
            //@ assert l > 0;
        }
        
        i = i + 1;
    }
    
    size_t min_val = (r < l) ? r : l;
    
    //@ assert min_val <= r && min_val <= l;
    //@ assert min_val <= m;
    
    return min_val;
}
