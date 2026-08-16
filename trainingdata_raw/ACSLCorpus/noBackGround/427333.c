#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100 &&
      (x) >= 1 && (x) <= 10000);
    requires \valid(l + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (l)[i] >= 1 && (l)[i] <= 100);
    ensures \result >= 0;
*/
long func(long n, long x, const long *l) {
    long count = 0;
    long d = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= d <= x;
        loop invariant 0 <= count <= (long)index;
        loop assigns count, d, index;
        loop variant n - index;
    */
    while (index < (size_t)n && d + l[index] <= x) {
        //@ assert d + l[index] <= x;
        count += 1;
        d += l[index];
        index += 1;
    }
    
    //@ assert count >= 0;
    return count;
}
