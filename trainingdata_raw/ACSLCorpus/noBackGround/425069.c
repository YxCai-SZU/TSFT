#include <stddef.h>
#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        \valid((l) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (l)[i] && (l)[i] <= 100);
    ensures 0 <= \result && \result <= n;
*/
size_t func(size_t n, int64_t x, const int64_t *l)
{
    int64_t d = 0;
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
        (d) >= 0 &&
        (d) <= (i) * 100 &&
        (count) <= (i) &&
        \forall integer j; 0 <= j < (i) ==> 1 <= (l)[j] && (l)[j] <= 100 &&
        0 <= (count) && (count) <= (n));
        loop assigns i, d, count;
        loop variant n - i;
    */
    while (i < n && d <= x)
    {
        //@ assert 0 <= count && count <= n;
        count += 1;
        d += l[i];
        i += 1;
    }
    
    //@ assert 0 <= count && count <= n;
    return count;
}
