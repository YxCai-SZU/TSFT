#include <stdbool.h>

/*@
    predicate is_nine(integer b) = b == 9;
    predicate is_at_least_eight(integer a) = a >= 8;
    predicate is_at_least_nine(integer b) = b >= 9;
    predicate is_in_range(integer n) = 10 <= n && n <= 99;
*/

/*@
    requires is_in_range(n);
    ensures \result == (n % 10 == 9 || n >= 90);
*/
bool func(int n)
{
    int a;
    int b;
    bool result;

    a = n / 10;
    b = n % 10;

    //@ assert a == n / 10 && b == n % 10;

    if (a == 9 || b == 9 || (a >= 8 && b >= 9))
    {
        result = true;
        //@ assert result == true;
    }
    else
    {
        //@ assert a != 9 && b != 9 && !(a >= 8 && b >= 9);
        result = false;
        //@ assert result == false;
    }

    return result;
}
