#include <stdbool.h>
#include <stddef.h>

/*@ requires 2 <= n <= 200000;
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000000);
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> (a)[i] % 2 == 0);
*/
bool func(size_t n, const int *a) {
    size_t i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000000);
        loop invariant \forall integer j; 0 <= j < i ==> a[j] % 2 == 0;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        int value = a[i];
        //@ assert 1 <= value <= 1000000000;
        if (value % 2 != 0) {
            //@ assert !(\forall integer i; 0 <= i < (n) ==> (a)[i] % 2 == 0);
            return false;
        }
        i++;
    }
    //@ assert (\forall integer i; 0 <= i < (n) ==> (a)[i] % 2 == 0);
    return true;
}
