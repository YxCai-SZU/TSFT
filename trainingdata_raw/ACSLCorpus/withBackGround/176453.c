#include <limits.h>

/*@ predicate in_range(integer a, integer b) = 
      1 <= a && a <= 9 && 1 <= b && b <= 9; */

/*@ predicate out_of_range(integer a, integer b) = 
      !(1 <= a && a <= 9 && 1 <= b && b <= 9); */

/*@ lemma multiplication_bound: 
      \forall integer a, b; 
      in_range(a, b) ==> a * b <= 81; */

/*@ requires 1 <= A <= 20;
    requires 1 <= B <= 20;
    ensures in_range(A, B) ==> \result == A * B;
    ensures out_of_range(A, B) ==> \result == -1;
    assigns \nothing;
*/
int func(int A, int B) {
    int result;
    
    //@ assert 1 <= A && A <= 20;
    //@ assert 1 <= B && B <= 20;
    
    if ((1 <= A && A <= 9) && (1 <= B && B <= 9)) {
        //@ assert in_range(A, B);
        //@ assert A * B <= 81;
        result = A * B;
    } else {
        //@ assert out_of_range(A, B);
        result = -1;
    }
    
    return result;
}
