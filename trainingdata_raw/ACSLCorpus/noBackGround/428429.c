#include <stdbool.h>

/*@
    requires (1 <= (a) <= 123) && (1 <= (b) <= 123) && (1 <= (c) <= 123) && (1 <= (d) <= 123) && (1 <= (e) <= 123);
    ensures \result == (a + b + c + d + e >= 5);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e)
{
    int total;
    //@ assert 1 <= a <= 123 && 1 <= b <= 123 && 1 <= c <= 123 && 1 <= d <= 123 && 1 <= e <= 123;
    //@ assert a + b + c + d + e <= 615;
    total = a + b + c + d + e;
    if (total < 5)
    {
        return false;
    }
    else
    {
        return true;
    }
}
