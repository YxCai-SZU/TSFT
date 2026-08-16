#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 1 && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
*/
int func(size_t n, const int *p) {
    int count = 0;
    int m = p[0];
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant count >= 0 && count <= i;
        loop invariant ((n) >= 1 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop invariant m >= 1 && m <= n;
        loop assigns i, m, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n && i >= 0;
        if (m >= p[i]) {
            m = p[i];
            count += 1;
        }
        i += 1;
    }
    return count;
}
