#include <stdbool.h>
#include <stddef.h>

/*@ requires 2 <= n <= 100000;
    requires \valid(a+(0..n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000000;
    assigns \nothing;
    ensures \result == true <==> \exists integer t; 0 <= t < n && a[t] % 2 == 0;
 */
bool func(size_t n, int *a) {
    size_t count = 0;
    size_t index = 0;
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000000;
        loop invariant index > 0 ==> (count > 0 <==> (\exists integer t; 0 <= t < (index) && (a)[t] % 2 == 0));
        loop assigns count, index;
        loop variant n - index;
     */
    while (index < n) {
        int v = a[index];
        if (v % 2 == 0) {
            count += 1;
        }
        index += 1;
        //@ assert index > 0 ==> (count > 0 <==> (\exists integer t; 0 <= t < (index) && (a)[t] % 2 == 0));
    }
    //@ assert count > 0 <==> (\exists integer t; 0 <= t < ((n)) && (a)[t] % 2 == 0);
    return count > 0;
}
