#include <stdbool.h>

/*@ predicate is_valid_range(int *v) =
    v[0] >= 0 && v[0] <= 123 &&
    v[1] >= 0 && v[1] <= 123 &&
    v[2] >= 0 && v[2] <= 123 &&
    v[3] >= 0 && v[3] <= 123 &&
    v[4] >= 0 && v[4] <= 123 &&
    v[5] >= 0 && v[5] <= 123;
*/

/*@ predicate is_strictly_increasing(int *v) =
    v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4] && v[4] < v[5];
*/

/*@
    requires \valid(v + (0..5));
    requires is_valid_range(v);
    ensures \result == 1 <==> is_strictly_increasing(v);
    assigns \nothing;
*/
bool func(int v[6]) {
    //@ assert v[0] >= 0 && v[0] <= 123;
    
    return v[0] < v[1] && v[1] < v[2] && v[2] < v[3] && v[3] < v[4] && v[4] < v[5];
}
