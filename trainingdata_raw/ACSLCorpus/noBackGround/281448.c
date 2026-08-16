#include <stdbool.h>
#include <stddef.h>

/*@ requires 2 <= n <= 1000000;
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (((a)[i]) == 1 || ((a)[i]) == 2 || ((a)[i]) == 5));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n;
*/
long func(size_t n, long* a) {
    size_t i = 0;
    long res = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (((a)[i]) == 1 || ((a)[i]) == 2 || ((a)[i]) == 5));
        loop invariant res >= 0;
        loop invariant res <= (long)i;
        loop invariant \forall integer j; 0 <= j < i ==> ((a[j]) == 1 || (a[j]) == 2 || (a[j]) == 5);
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        long x = a[i];
        if (x == 1) {
            res += 1;
        }
        i += 1;
    }
    
    return res;
}
