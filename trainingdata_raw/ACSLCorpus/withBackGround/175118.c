#include <stdbool.h>

/*@
    predicate distinct(integer a, integer b) = a != b;
    predicate ordered(integer a, integer b, integer c) = a < b && b < c;
*/

/*@
    requires 0 <= A <= 100;
    requires 0 <= B <= 100;
    requires 0 <= C <= 100;
    requires distinct(A, B);
    ensures \result == true <==> ordered(A, B, C);
*/
bool func(int A, int B, int C)
{
    //@ assert distinct(A, B);
    return A < B && B < C;
}
