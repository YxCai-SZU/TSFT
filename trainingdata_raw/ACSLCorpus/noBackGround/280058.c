#include <stdbool.h>

/*@
    requires a > -2147483648 && a < 2147483647;
    requires b > -2147483648 && b < 2147483647;
    requires c > -2147483648 && c < 2147483647;
    ensures \result == true <==> (a < b && b < c);
*/
bool func(int a, int b, int c)
{
    int a_is_less_than_b;
    int b_is_less_than_c;
    int sum;
    bool result;

    //@ assert a > -2147483648 && a < 2147483647;
    //@ assert b > -2147483648 && b < 2147483647;
    //@ assert c > -2147483648 && c < 2147483647;

    a_is_less_than_b = (a < b) ? 1 : 0;
    b_is_less_than_c = (b < c) ? 1 : 0;

    //@ assert a_is_less_than_b == 1 <==> a < b;
    //@ assert b_is_less_than_c == 1 <==> b < c;

    sum = a_is_less_than_b + b_is_less_than_c;

    if (sum == 2)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> (a < b && b < c);
    return result;
}
