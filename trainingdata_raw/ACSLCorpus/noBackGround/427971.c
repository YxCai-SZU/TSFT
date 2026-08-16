#include <stddef.h>
#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        \valid((l) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> 1 <= (l)[j] && (l)[j] <= 100);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
long func(long n, long x, const long *l) {
    long count = 0;
    long d = 0;
    size_t i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
        (d) >= 0 &&
        (d) <= (x) + 100 &&
        (count) >= 0 &&
        (count) <= (i) &&
        (1 <= ((n)) && ((n)) <= 100 &&
        1 <= ((x)) && ((x)) <= 10000 &&
        \valid(((l)) + (0 .. ((n))-1)) &&
        \forall integer j; 0 <= j < ((n)) ==> 1 <= ((l))[j] && ((l))[j] <= 100));
        loop assigns count, d, i;
        loop variant n - i;
    */
    while (d <= x && i < (size_t)n) {
        //@ assert count >= 0 && count <= i;
        count += 1;
        d += l[i];
        i += 1;
        //@ assert count >= 0 && count <= i;
    }
    
    //@ assert count >= 0 && count <= n;
    return count;
}
