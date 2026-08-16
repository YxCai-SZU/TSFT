#include <stdbool.h>
#include <stddef.h>

/*@
    requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires ((n) > 0 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 1000);
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (n) && (a)[i] % 2 == 0 ==>
            (a)[i] % 3 == 0 || (a)[i] % 5 == 0);
*/
bool func(size_t n, unsigned int* a) {
    bool flag = true;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant flag == 1 <==> 
            (\forall integer k; 0 <= k < i && a[k] % 2 == 0 ==>
             a[k] % 3 == 0 || a[k] % 5 == 0);
        loop assigns i, flag;
        loop variant n - i;
    */
    while (i < n) {
        unsigned int ai = a[i];
        if (ai % 2 == 0) {
            if (!(ai % 3 == 0 || ai % 5 == 0)) {
                flag = false;
            }
        }
        i++;
    }

    //@ assert flag == 1 <==> (\forall integer i; 0 <= i < (n) && (a)[i] % 2 == 0 ==>             (a)[i] % 3 == 0 || (a)[i] % 5 == 0);
    return flag;
}
