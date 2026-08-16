#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int diff1;
    int diff2;
    bool result;

    diff1 = b - a;
    diff2 = c - b;

    //@ assert diff1 >= -2147483648 && diff1 <= 2147483647;
    //@ assert diff2 >= -2147483648 && diff2 <= 2147483647;
    //@ assert diff1 == diff2 ==> (diff1 >= -2147483648 && diff1 <= 2147483647);

    //@ assert diff1 == diff2 || diff1 != diff2;

    result = (diff1 == diff2);
    return result;
}
