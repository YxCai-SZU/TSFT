#include <stdbool.h>

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    ensures \result >= 0;
    ensures \result <= B;
    ensures \result == (A > B ? B : A);
*/
int func(int A, int B)
{
    int result;
    //@ assert 1 <= A <= 100;
    //@ assert 1 <= B <= 100;
    result = (A > B) ? B : A;
    return result;
}
