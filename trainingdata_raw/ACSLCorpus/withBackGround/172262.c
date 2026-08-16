#include <stdbool.h>

/*@ predicate valid_array(int *a, integer len) =
    len == 3 &&
    1 <= a[0] <= 100 &&
    1 <= a[1] <= 100 &&
    1 <= a[2] <= 200;
*/

/*@ logic integer condition_value(int *a) =
    a[0] <= a[2] && a[1] >= a[2] - a[0] ? 1 : 0;
*/

/*@ lemma array_length_lemma: 
    \forall int *a, integer len; valid_array(a, len) ==> len == 3;
*/

/*@ lemma bounds_lemma: 
    \forall int *a, integer len; valid_array(a, len) ==> 
    1 <= a[0] <= 100 && 1 <= a[1] <= 100 && 1 <= a[2] <= 200;
*/

/*@ requires \valid(a + (0..2));
    requires valid_array(a, 3);
    ensures \result == (a[0] <= a[2] && a[1] >= a[2] - a[0]);
    assigns \nothing;
*/
bool func(int *a) {
    //@ assert valid_array(a, 3);
    bool result = a[0] <= a[2] && a[1] >= a[2] - a[0];
    //@ assert result == (a[0] <= a[2] && a[1] >= a[2] - a[0]);
    return result;
}
