#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_range(int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 1000;
*/

/*@
    requires n > 0;
    requires \valid_read(v + (0 .. n-1));
    assigns \nothing;
    ensures \result == true <==> valid_range(v, n);
*/
bool func(int n, int *v) {
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant \forall integer i; 0 <= i < index ==> 1 <= v[i] <= 1000;
        loop assigns index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int i = v[index];
        //@ assert 0 <= index < n;
        if (i < 1 || i > 1000) {
            return false;
        }
        index++;
    }
    return true;
}
