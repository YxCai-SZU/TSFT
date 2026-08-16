#include <stdbool.h>

/*@ predicate is_valid_vector(int *v, integer len) =
      len == 2 &&
      1 <= v[0] <= 100 &&
      1 <= v[1] <= 100000;
*/

/*@ logic integer scaled_value(integer a) = a * 500; */

/*@ lemma scaled_value_bounds: 
      \forall integer a; 1 <= a <= 100 ==> scaled_value(a) <= 50000;
*/

/*@ requires \valid(v+(0..1));
    requires is_valid_vector(v, 2);
    ensures \result == (scaled_value(v[0]) >= v[1]);
*/
bool func(int *v) {
    // Variable declarations at scope top
    int sum;
    bool result;
    
    //@ assert 1 <= v[0] && v[0] <= 100;
    //@ assert 1 <= v[1] && v[1] <= 100000;
    //@ assert scaled_value(v[0]) <= 50000;
    
    sum = v[0] * 500;
    result = sum >= v[1];
    return result;
}
