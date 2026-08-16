#include <stddef.h>
#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        \valid((l) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> 1 <= (l)[j] && (l)[j] <= 100);
    ensures \result >= 1 && \result <= n + 1;
    assigns \nothing;
*/
size_t func(size_t n, int64_t x, const int64_t *l) {
    int64_t d = 0;
    size_t count = 1;
    size_t i = 0;

    /*@
        loop invariant 0 <= i && i <= n;
        loop invariant d >= 0 && d <= i * 100;
        loop invariant count >= 1 && count <= i + 1;
        loop assigns i, d, count;
        loop variant n - i;
    */
    while (i < n) {
        int64_t next_d = d + l[i];
        
        //@ assert next_d == d + l[i];
        
        if (next_d <= x) {
            count++;
            d = next_d;
        } else {
            break;
        }
        i++;
    }
    
    //@ assert count >= 1 && count <= n + 1;
    return count;
}
