#include <stdbool.h>
#include <stddef.h>

/*@
    requires n > 0;
    requires \valid(a + (0 .. n-1));
    ensures \result == true <==> (\exists size_t i; 0 <= i < (n) &&
        ((a)[i] % 2 == 0) && ((a)[i] % 3 == 0 || (a)[i] % 5 == 0));
*/
bool func(size_t n, int *a) {
    size_t i = 0;
    int an;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant (\forall size_t k; 0 <= k < (i) ==>
        !(((a)[k] % 2 == 0) && ((a)[k] % 3 == 0 || (a)[k] % 5 == 0)));
        loop assigns i, an;
        loop variant n - i;
    */
    while (i < n) {
        an = a[i];
        //@ assert an == a[i];
        if (an % 2 == 0) {
            if (an % 3 == 0 || an % 5 == 0) {
                //@ assert (\exists size_t i; 0 <= i < (n) &&         ((a)[i] % 2 == 0) && ((a)[i] % 3 == 0 || (a)[i] % 5 == 0));
                return true;
            }
        }
        i += 1;
    }
    //@ assert !(\exists size_t i; 0 <= i < (n) &&         ((a)[i] % 2 == 0) && ((a)[i] % 3 == 0 || (a)[i] % 5 == 0));
    return false;
}
