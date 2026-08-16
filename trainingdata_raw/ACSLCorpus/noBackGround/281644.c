#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) > 0 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] && (a)[i] <= 1000);
    ensures ((\result) == true <==>
        (\forall integer i; 0 <= i < (n) && (a)[i] % 2 == 0 ==> 
            (a)[i] % 3 == 0 || (a)[i] % 5 == 0));
    assigns \nothing;
*/
bool func(size_t n, unsigned int *a) {
    bool ans = true;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \valid(a + (0 .. n-1));
        loop invariant ans == true <==> 
            (\forall integer j; 0 <= j < i && a[j] % 2 == 0 ==> 
                a[j] % 3 == 0 || a[j] % 5 == 0);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        unsigned int ai = a[i];
        if (ai % 2 == 0) {
            if (!(ai % 3 == 0 || ai % 5 == 0)) {
                ans = false;
            }
        }
        i++;
    }
    return ans;
}
