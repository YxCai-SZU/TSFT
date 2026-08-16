#include <stdbool.h>

/*@
    requires 1 <= A && A <= 13;
    requires 1 <= B && B <= 13;
    requires 1 <= C && C <= 13;
    ensures \result == (A + B + C <= 21);
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    // Variable declarations at scope top
    unsigned int sum_ab;
    unsigned int sum_total;
    bool result;

    sum_ab = A + B;
    //@ assert sum_ab <= 26;

    sum_total = sum_ab + C;
    //@ assert sum_total <= 39;

    result = (sum_total <= 21);
    return result;
}
