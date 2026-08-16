#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) > 0 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> (a)[k] > 0 && (a)[k] <= 1000);
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> 
            (a)[i] % 2 != 0 || (a)[i] % 6 == 0 || (a)[i] % 10 == 0);
    assigns \nothing;
*/
bool func(size_t n, int *a) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ((n) > 0 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> (a)[k] > 0 && (a)[k] <= 1000);
        loop invariant \forall integer j; 0 <= j < i ==> 
            a[j] % 2 != 0 || a[j] % 6 == 0 || a[j] % 10 == 0;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] % 2 == 0 && a[i] % 6 != 0 && a[i] % 10 != 0) {
            //@ assert !(a[i] % 2 != 0 || a[i] % 6 == 0 || a[i] % 10 == 0);
            return false;
        }
        i++;
    }
    //@ assert i == n;
    //@ assert \forall integer j; 0 <= j < n ==> a[j] % 2 != 0 || a[j] % 6 == 0 || a[j] % 10 == 0;
    return true;
}
