#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == ((a < c && c < b) || (a > c && c > b));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool is_between = false;

    //@ assert 1 <= a <= 100;
    
    if (a < b)
    {
        is_between = (c > a) && (c < b);
    }
    else
    {
        is_between = (c < a) && (c > b);
    }

    //@ assert is_between == ((a < c && c < b) || (a > c && c > b));

    return is_between;
}
