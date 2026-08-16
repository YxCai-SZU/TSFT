#include <stdbool.h>
#include <stddef.h>

/*@
    requires n > 0 && n <= 100000;
    requires \valid(v + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> v[i] > 0 && v[i] <= 1000000000;
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> (v)[i] % 2 == 0);
*/
bool func(size_t n, const int *v) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < i ==> v[j] % 2 == 0;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        int x = v[i];
        if (x % 2 == 1) {
            return false;
        }
        i++;
    }
    return true;
}
