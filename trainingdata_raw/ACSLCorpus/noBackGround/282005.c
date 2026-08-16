#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 2 && n <= 100000;
    requires n % 2 == 0;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000;
    assigns \nothing;
    ensures \result == true <==> (\exists integer i; 0 <= i < (n) && (a)[i] % 2 == 1);
*/
bool func(size_t n, unsigned int *a) {
    unsigned int sum = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant sum >= 0;
        loop invariant sum <= i * 1000;
        loop invariant (\forall integer k; (0) <= k < (i) ==> (a)[k] % 2 == 0);
        loop assigns sum, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] % 2 == 1) {
            //@ assert (\exists integer i; 0 <= i < (n) && (a)[i] % 2 == 1);
            return true;
        }
        sum += a[i];
        i++;
    }
    
    //@ assert (\forall integer k; (0) <= k < (n) ==> (a)[k] % 2 == 0);
    //@ assert !(\exists integer i; 0 <= i < (n) && (a)[i] % 2 == 1);
    return false;
}
