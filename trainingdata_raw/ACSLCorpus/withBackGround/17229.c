#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 100; */

/*@
  requires \valid_read(v + (0..2));
  requires is_valid_range(v[0]) && is_valid_range(v[1]) && is_valid_range(v[2]);
  ensures \result == ( (v[1] < v[2] && v[2] < v[0]) || (v[0] < v[2] && v[2] < v[1]) );
*/
bool func(unsigned int v[3])
{
    bool result = false;
    
    //@ assert v[0] >= 1 && v[0] <= 100;
    //@ assert v[1] >= 1 && v[1] <= 100;
    //@ assert v[2] >= 1 && v[2] <= 100;
    
    if (v[1] < v[2] && v[2] < v[0]) {
        result = true;
    } else if (v[0] < v[2] && v[2] < v[1]) {
        result = true;
    }
    
    return result;
}
