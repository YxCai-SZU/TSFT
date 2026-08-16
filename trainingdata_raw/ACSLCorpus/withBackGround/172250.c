#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_arrays(int *a, int *b, integer len) =
        len > 0 &&
        \valid(a + (0 .. len-1)) &&
        \valid(b + (0 .. len-1)) &&
        \forall integer i; 0 <= i < len ==> a[i] > 0;

    predicate all_ge(int *a, int *b, integer len, integer idx) =
        \forall integer j; 0 <= j < idx ==> a[j] >= b[j];
*/

/*@
    requires valid_arrays(a, b, len);
    ensures \result == true <==> \forall integer i; 0 <= i < len ==> a[i] >= b[i];
    assigns \nothing;
*/
bool func(int *a, int *b, size_t len) {
    bool result = true;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant result == true <==> all_ge(a, b, len, i);
        loop invariant valid_arrays(a, b, len);
        loop assigns i, result;
        loop variant len - i;
    */
    while (i < len) {
        if (b[i] > a[i]) {
            result = false;
        }
        i++;
    }
    return result;
}
