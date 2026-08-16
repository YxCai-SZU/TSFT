#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == ((a < b && c >= b) || (a > b && c <= b));
    assigns \nothing;
*/
bool is_between(int a, int b, int c)
{
    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;
    return (a < b && c >= b) || (a > b && c <= b);
}
