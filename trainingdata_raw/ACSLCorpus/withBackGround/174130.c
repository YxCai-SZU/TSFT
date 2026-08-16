#include <stdbool.h>

/*@ predicate is_valid_range(integer a) = 1 <= a && a <= 100; */

/*@
  requires \valid(v+(0..2));
  requires is_valid_range(v[0]) && is_valid_range(v[1]) && is_valid_range(v[2]);
  ensures \result == (v[1] - v[0] == v[2] - v[1]);
  assigns \nothing;
*/
bool func(int v[3]) {
    int v0, v1, v2;
    bool result;
    
    v0 = v[0];
    v1 = v[1];
    v2 = v[2];
    
    //@ assert v1 - v0 >= -99 && v1 - v0 <= 99;
    //@ assert v2 - v1 >= -99 && v2 - v1 <= 99;
    
    result = (v1 - v0 == v2 - v1);
    return result;
}
