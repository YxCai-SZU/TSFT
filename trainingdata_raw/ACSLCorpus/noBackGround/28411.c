#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        \valid((l) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (l)[i] && (l)[i] <= 100);
    ensures \result >= 1 && \result <= n + 1;
    assigns \nothing;
*/
size_t func(size_t n, size_t x, const size_t *l) {
    size_t d = 0;
    size_t count = 1;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant d <= i * 100;
        loop invariant d >= i;
        loop invariant count >= 1;
        loop invariant count <= i + 1;
        loop assigns i, d, count;
        loop variant n - i;
    */
    while (i < n) {
        size_t li = l[i];
        d += li;
        
        //@ assert d >= li;
        
        if (d <= x) {
            count += 1;
        } else {
            break;
        }
        
        //@ assert count <= i + 2;
        i += 1;
    }
    
    //@ assert count >= 1;
    //@ assert count <= n + 1;
    return count;
}
