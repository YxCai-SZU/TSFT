#include <stdbool.h>

/*@ predicate is_increasing(integer a, integer b, integer c) =
      a < b && b < c;
*/

/*@
    requires \valid_read(A + (0..2));
    requires 1 <= A[0] && A[0] <= 100;
    requires 1 <= A[1] && A[1] <= 100;
    requires 1 <= A[2] && A[2] <= 100;
    ensures \result <==> is_increasing(A[0], A[1], A[2]);
*/
bool is_increasing(int A[3]) {
    int a;
    int b;
    int c;
    bool result;

    a = A[0];
    b = A[1];
    c = A[2];

    //@ assert a == A[0];
    //@ assert b == A[1];
    //@ assert c == A[2];

    result = a < b && b < c;
    return result;
}
