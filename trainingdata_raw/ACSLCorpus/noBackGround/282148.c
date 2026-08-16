#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 2 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==>
        ((a)[i] % 2 == 0 ==> ((a)[i] % 3 == 0 || (a)[i] % 5 == 0)));
    assigns \nothing;
*/
bool func(size_t n, int *a) {
    size_t i = 0;
    bool result = true;

    /*@ loop invariant 0 <= i <= n;
        loop invariant \valid(a + (0 .. n-1));
        loop invariant \forall integer j; 0 <= j < i ==> a[j] > 0 && a[j] <= 1000;
        loop invariant \forall integer j; 0 <= j < i ==> 
            (a[j] % 2 == 0 ==> (a[j] % 3 == 0 || a[j] % 5 == 0));
        loop invariant n >= 2 && n <= 100;
        loop invariant i <= n;
        loop invariant result == true;
        loop assigns i, result;
        loop variant n - i;
    */
    while (i < n) {
        int value = a[i];
        if (value % 2 == 0) {
            //@ assert value % 2 == 0;
            if (value % 3 == 0 || value % 5 == 0) {
                i += 1;
                continue;
            } else {
                result = false;
                //@ assert !(value % 3 == 0 || value % 5 == 0);
                return result;
            }
        }
        i += 1;
    }
    //@ assert i == n;
    return result;
}
