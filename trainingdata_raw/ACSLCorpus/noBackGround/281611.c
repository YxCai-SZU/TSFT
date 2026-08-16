#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 1000000);
    ensures ((\result) >= 0 && (\result) <= (n) &&
        \forall integer i; 0 <= i < (n) && i % 2 == 0 && ((a)[i] & 1) == 1 ==> (\result) > 0);
    assigns \nothing;
*/
size_t func(size_t n, int *a) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i && j % 2 == 0 && (a[j] & 1) == 1 ==> count > 0;
        loop invariant ((n) >= 1 && (n) <= 200000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 1000000);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        if (i % 2 == 0) {
            int x = a[i];
            if (x & 1) {
                //@ assert count >= 0;
                count += 1;
            }
        }
        i += 1;
    }
    return count;
}
