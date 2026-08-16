#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100);
    requires (1 <= (B) <= 100);
    requires (1 <= (C) <= 100);
    ensures \result == ((A < B && C < A + B) || (A > B && C > A - B));
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= A <= 100;
    //@ assert 1 <= B <= 100;
    //@ assert 1 <= C <= 100;

    result = (A < B && C < A + B) || (A > B && C > A - B);
    return result;
}
