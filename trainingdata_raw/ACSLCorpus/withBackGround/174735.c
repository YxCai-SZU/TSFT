#include <stdbool.h>

/*@ predicate is_valid_index(integer i) = 0 <= i < 3; */
/*@ predicate is_valid_value(integer v) = 0 <= v <= 100; */
/*@ predicate contains_one(integer a, integer b, integer c) = 
      a == 1 || b == 1 || c == 1; */

/*@ lemma loop_terminates: 
      \forall integer i; 0 <= i <= 3 ==> 3 - i >= 0; */

/*@ requires \valid(a + (0..2));
    requires contains_one(a[0], a[1], a[2]);
    requires \forall integer i; 0 <= i < 3 ==> is_valid_value(a[i]);
    ensures 1 <= \result <= 3;
    ensures a[\result - 1] == 1;
    assigns \nothing;
 */
int func(int a[3]) {
    int i = 0;
    
    /*@ loop invariant 0 <= i <= 3;
        loop invariant contains_one(a[0], a[1], a[2]);
        loop invariant \forall integer j; 0 <= j < 3 ==> is_valid_value(a[j]);
        loop invariant \forall integer k; 0 <= k < i ==> a[k] != 1;
        loop assigns i;
        loop variant 3 - i;
     */
    while (i < 3) {
        //@ assert is_valid_index(i);
        if (a[i] == 1) {
            //@ assert a[i] == 1;
            return i + 1;
        }
        i = i + 1;
    }
    
    // This line is unreachable given the preconditions
    return -1;
}
