#include <stdbool.h>

/*@ predicate is_valid_index(integer i) = 0 <= i < 4; */

/*@ predicate element_in_range(integer val) = 1 <= val <= 10000; */

/*@ predicate valid_vector(integer v0, integer v1, integer v2, integer v3) =
    element_in_range(v0) && element_in_range(v1) && 
    element_in_range(v2) && element_in_range(v3); */

/*@ predicate possible_result(integer r, integer v0, integer v1, integer v2, integer v3) =
    r == v0 - v2 || r == v1 - v3 || r == v2 - v0 || r == v3 - v1; */

/*@ lemma result_nonnegative: 
    \forall integer v0, v1, v2, v3; 
    valid_vector(v0, v1, v2, v3) ==> 
    (v0 - v2 >= 0 || v1 - v3 >= 0 || v2 - v0 >= 0 || v3 - v1 >= 0); */

/*@ requires valid_vector(v0, v1, v2, v3);
    ensures \result >= 0;
    ensures possible_result(\result, v0, v1, v2, v3);
    assigns \nothing;
 */
int func(int v0, int v1, int v2, int v3) {
    int x[4];
    int max_val;
    int i;
    
    x[0] = v0 - v2;
    x[1] = v1 - v3;
    x[2] = v2 - v0;
    x[3] = v3 - v1;
    
    max_val = x[0];
    i = 1;
    
    /*@ loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_val == x[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= x[j];
        loop invariant \forall integer k; 0 <= k < 4 ==> possible_result(x[k], v0, v1, v2, v3);
        loop invariant valid_vector(v0, v1, v2, v3);
        loop invariant x[0] == v0 - v2 && x[1] == v1 - v3 && 
                      x[2] == v2 - v0 && x[3] == v3 - v1;
        loop invariant possible_result(max_val, v0, v1, v2, v3);
        loop assigns i, max_val;
        loop variant 4 - i;
    */
    while (i < 4) {
        if (x[i] > max_val) {
            max_val = x[i];
        }
        i = i + 1;
    }
    
    //@ assert max_val >= 0;
    //@ assert possible_result(max_val, v0, v1, v2, v3);
    
    return max_val;
}

int main() {
    return 0;
}
