#include <stdbool.h>

/*@ predicate sum_less_22(integer a, integer b, integer c) =
    a + b + c < 22;
*/

/*@
    requires \valid_read(A + (0..2));
    requires 1 <= A[0] <= 13;
    requires 1 <= A[1] <= 13;
    requires 1 <= A[2] <= 13;
    ensures \result == true <==> sum_less_22(A[0], A[1], A[2]);
*/
bool func(const long long *A) {
    long long sum;
    bool result;

    sum = A[0] + A[1] + A[2];
    
    if (sum >= 22) {
        result = false;
        //@ assert !sum_less_22(A[0], A[1], A[2]);
    } else {
        //@ assert sum_less_22(A[0], A[1], A[2]);
        result = true;
    }
    
    return result;
}
