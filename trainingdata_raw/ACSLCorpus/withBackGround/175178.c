#include <stdbool.h>

/*@ predicate is_valid_index(int i, integer len) =
      0 <= i && i < len;
*/

/*@ predicate is_valid_value(integer x) =
      1 <= x && x <= 16;
*/

/*@ predicate vector_valid(int *v, integer len) =
      len == 2 &&
      \forall integer i; 0 <= i < len ==> 
        is_valid_value(v[i]) && v[i] == v[i];
*/

/*@ requires \valid(v + (0 .. 1));
    requires vector_valid(v, 2);
    ensures \result == (v[0] + v[1] >= 8);
*/
bool func(int *v) {
    int a;
    int b;
    
    a = v[0];
    b = v[1];
    
    //@ assert is_valid_value(a);
    //@ assert is_valid_value(b);
    
    if (a + b >= 8) {
        //@ assert a + b >= 8;
        return true;
    } else {
        //@ assert a + b < 8;
        return false;
    }
}
