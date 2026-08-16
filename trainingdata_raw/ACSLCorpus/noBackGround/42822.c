#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> 0 <= (a)[i] && (a)[i] <= 123);
    requires 0 <= k && k <= 123;
    ensures ((\result) == ((a)[4] - (a)[0] <= (k)));
    assigns \nothing;
*/
bool func(const int *a, int k) {
    int vec[5];
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> vec[j] == a[j];
        loop assigns i, vec[0..4];
        loop variant 5 - i;
    */
    while (i < 5) {
        vec[i] = a[i];
        i = i + 1;
    }

    int first = vec[0];
    int last = vec[4];
    bool result = last - first <= k;
    
    //@ assert first == a[0];
    //@ assert last == a[4];
    //@ assert result == (a[4] - a[0] <= k);
    
    return result;
}
