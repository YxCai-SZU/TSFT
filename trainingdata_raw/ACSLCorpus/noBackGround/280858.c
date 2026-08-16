#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 1000000000);
    requires n >= 1;
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
size_t func(size_t n, size_t k, const int *a) {
    size_t t = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= t <= index;
        loop invariant ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 1000000000);
        loop invariant (\forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
        loop assigns t, index;
        loop variant n - index;
    */
    while (index < n) {
        int i = a[index];
        if ((size_t)i < k) {
            t += 1;
        }
        index += 1;
    }
    
    //@ assert 0 <= t <= n;
    return t;
}
