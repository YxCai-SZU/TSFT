#include <stdbool.h>
#include <stddef.h>

/*@
    predicate all_even(unsigned long long *v, integer n) =
        \forall integer i; 0 <= i < n ==> v[i] % 2 == 0;

    predicate valid_range(unsigned long long *v, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= v[i] <= 1000000000;
*/

/*@
    requires 1 <= n <= 200000;
    requires \valid(v + (0..n-1));
    requires valid_range(v, n);
    ensures \result == true <==> all_even(v, n);
    assigns \nothing;
*/
bool func(size_t n, unsigned long long *v) {
    bool result = true;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant result == true ==> \forall integer i; 0 <= i < index ==> v[i] % 2 == 0;
        loop invariant result == false ==> \exists integer i; 0 <= i < index && v[i] % 2 != 0;
        loop assigns index, result;
        loop variant n - index;
    */
    while (index < n) {
        unsigned long long value = v[index];
        if (value % 2 != 0) {
            result = false;
            break;
        }
        index++;
    }

    //@ assert result == true <==> all_even(v, n);
    return result;
}
