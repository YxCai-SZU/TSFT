#include <stdbool.h>
#include <stddef.h>

/*@
    predicate greater_than_ten{L}(unsigned int *s, size_t len) =
        \forall size_t i; 0 <= i < len ==> s[i] > 10;
*/

/*@
    requires \forall size_t i; 0 <= i < len ==> arr[i] > 10;
    ensures \result == true;
    assigns \nothing;
*/
bool is_greater_than_ten(unsigned int *arr, size_t len) {
    //@ assert greater_than_ten(arr, len);
    return true;
}
