#include <stdbool.h>

/*@
    requires 0 <= a <= 20;
    requires 0 <= b <= 20;
    requires 0 <= c <= 20;
    requires 0 <= d <= 20;
    ensures \result == true;
    assigns \nothing;
*/
bool non_linear_arith(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    bool result;

    // Main verification assertions
    //@ assert 0 <= a * b <= 400;
    //@ assert 0 <= b * c <= 400;
    //@ assert 0 <= c * d <= 400;
    //@ assert 0 <= a * b * c <= 8000;
    //@ assert 0 <= b * c * d <= 8000;
    //@ assert a * b * c <= 8000;
    //@ assert b * c * d <= 8000;
    //@ assert 0 <= a * b * c * d <= 160000;

    result = true;
    return result;
}
