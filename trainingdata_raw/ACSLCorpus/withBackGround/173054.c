#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 100; */

/*@ predicate is_sorted(integer a, integer b, integer c) = a < b && b < c; */

/*@
  requires \valid_read(v + (0..2));
  requires is_valid_range(v[0]) && is_valid_range(v[1]) && is_valid_range(v[2]);
  ensures \result == true <==> is_sorted(v[0], v[1], v[2]);
  assigns \nothing;
*/
bool func(const int v[3])
{
    bool result;
    
    //@ assert is_valid_range(v[0]);
    //@ assert is_valid_range(v[1]);
    //@ assert is_valid_range(v[2]);
    
    if (1 <= v[0] && v[0] <= 100) {
        if (1 <= v[1] && v[1] <= 100) {
            if (1 <= v[2] && v[2] <= 100) {
                result = v[0] < v[1] && v[1] < v[2];
            } else {
                result = false;
            }
        } else {
            result = false;
        }
    } else {
        result = false;
    }
    
    //@ assert result == true <==> is_sorted(v[0], v[1], v[2]);
    return result;
}
