#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int ab;
    int bc;
    int abc;
    bool result;

    ab = (a < b) ? 1 : 0;
    bc = (b < c) ? 1 : 0;
    abc = ab * bc;

    //@ assert abc == 1 ==> (a < b && b < c);

    result = (abc == 1);
    return result;
}
