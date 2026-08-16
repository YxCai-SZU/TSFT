#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) > 0 && (n) <= 100 &&
        \forall size_t i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000);
    ensures \result == true <==> (\forall size_t i; 0 <= i < (n) && (a)[i] % 2 == 0 ==> 
        (a)[i] % 3 == 0 || (a)[i] % 5 == 0);
    assigns \nothing;
*/
bool func(size_t n, int *a) {
    bool flag = true;
    size_t i = 0;
    
    /*@
        loop invariant (0 <= (i) && (i) <= (n) &&
        (flag) == true <==> 
        (\forall size_t j; 0 <= j < (i) && (a)[j] % 2 == 0 ==> 
         (a)[j] % 3 == 0 || (a)[j] % 5 == 0));
        loop invariant i <= n;
        loop assigns i, flag;
        loop variant n - i;
    */
    while (i < n) {
        int ai = a[i];
        if (ai % 2 == 0) {
            if (!(ai % 3 == 0 || ai % 5 == 0)) {
                flag = false;
            }
        }
        i++;
    }
    return flag;
}
