#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_monotonic(size_t *a, integer len) =
        len >= 3 &&
        ( (a[0] < a[1] && a[1] < a[2]) ||
          (a[0] > a[1] && a[1] > a[2]) );
*/

/*@
    requires \valid_read(a + (0 .. 2));
    requires len >= 3;
    assigns \nothing;
    ensures \result == true <==> is_monotonic(a, len);
*/
bool func(const size_t *a, size_t len) {
    bool result;

    //@ assert len >= 3;
    
    if ((a[0] < a[1] && a[1] < a[2]) || (a[0] > a[1] && a[1] > a[2])) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result == true <==> is_monotonic(a, len);
    return result;
}
