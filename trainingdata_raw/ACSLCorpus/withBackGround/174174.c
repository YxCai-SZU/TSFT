#include <stdbool.h>

/*@ predicate is_valid_range(integer a, integer b) = 
      1 <= a && a <= 100 && 0 <= b && b <= 4111; */

/*@ logic integer calculate_s(integer a) = a * 500; */

/*@ lemma s_calculation: 
      \forall integer a; calculate_s(a) == a * 500; */

/*@ requires \valid(v+(0..1));
    requires is_valid_range(v[0], v[1]);
    ensures \result == (v[0] * 500 >= v[1]); */
bool func(int v[2])
{
    int s;
    bool result;
    
    s = v[0] * 500;
    
    //@ assert s == v[0] * 500;
    
    result = (s >= v[1]);
    return result;
}
