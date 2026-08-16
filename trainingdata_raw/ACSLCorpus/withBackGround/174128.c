#include <stdbool.h>
/*@
    predicate valid_vec(int *v, integer len) =
        len == 3 &&
        1 <= v[0] <= 20 &&
        1 <= v[1] <= 20 &&
        1 <= v[2] <= 20;

    logic integer sum_pair(integer a, integer b) = a + b;

    lemma sum_bounds:
        \forall integer a, b; 1 <= a <= 20 && 1 <= b <= 20 ==> 2 <= sum_pair(a, b) <= 40;
*/

/*@
    requires \valid(v + (0..2));
    requires valid_vec(v, 3);
    ensures \result >= 0;
    ensures \result == sum_pair(v[0], v[1]) ||
             \result == sum_pair(v[1], v[2]) ||
             \result == sum_pair(v[2], v[0]);
    assigns \nothing;
*/
int func(int *v)
{
    int max_val;
    int temp_val;
    
    //@ assert 1 <= v[0] && v[0] <= 20;
    //@ assert 1 <= v[1] && v[1] <= 20;
    //@ assert 1 <= v[2] && v[2] <= 20;
    //@ assert sum_pair(v[0], v[1]) <= 40;
    //@ assert sum_pair(v[1], v[2]) <= 40;
    //@ assert sum_pair(v[2], v[0]) <= 40;
    
    max_val = v[0] + v[1];
    temp_val = v[1] + v[2];
    
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    temp_val = v[2] + v[0];
    
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    return max_val;
}
