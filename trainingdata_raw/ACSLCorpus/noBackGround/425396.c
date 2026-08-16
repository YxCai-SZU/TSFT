#include <stdbool.h>

/*@
    requires a >= 1 && a <= 100;
    requires b >= 1 && b <= 100;
    requires c >= 1 && c <= 100;
    ensures \result == true <==> (a + b == c || a + c == b || b + c == a);
*/
bool func(int a, int b, int c)
{
    bool is_valid;
    int sum1;
    int sum2;
    int sum3;

    is_valid = false;
    sum1 = a + b;
    sum2 = a + c;
    sum3 = b + c;

    if (sum1 == c || sum2 == b || sum3 == a)
    {
        is_valid = true;
    }

    //@ assert is_valid == true <==> (a + b == c || a + c == b || b + c == a);
    return is_valid;
}
