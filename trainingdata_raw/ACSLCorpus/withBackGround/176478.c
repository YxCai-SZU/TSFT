#include <stdbool.h>

/*@ predicate in_range(integer x) = -100 <= x <= 100; */

/*@
  requires \valid_read(v + (0..2));
  requires in_range(v[0]) && in_range(v[1]) && in_range(v[2]);
  ensures \result == (v[2] >= v[0] && v[2] <= v[1]);
  assigns \nothing;
*/
bool func(const int* v) {
    //@ assert in_range(v[0]);
    //@ assert in_range(v[1]);
    //@ assert in_range(v[2]);
    return v[2] >= v[0] && v[2] <= v[1];
}
