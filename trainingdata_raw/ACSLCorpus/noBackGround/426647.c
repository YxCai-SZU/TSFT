#include <stdbool.h>

/*@ requires \valid_read(A+(0..2));
    requires (1 <= (A[0]) && (A[0]) <= 9) && (1 <= (A[1]) && (A[1]) <= 9) && (1 <= (A[2]) && (A[2]) <= 9);
    ensures \result == true <==> ((A)[0] < (A)[1] && (A)[1] < (A)[2]);
    assigns \nothing;
*/
bool is_increasing(int *A)
{
    //@ assert (1 <= (A[0]) && (A[0]) <= 9);
    //@ assert (1 <= (A[1]) && (A[1]) <= 9);
    //@ assert (1 <= (A[2]) && (A[2]) <= 9);
    return A[0] < A[1] && A[1] < A[2];
}
