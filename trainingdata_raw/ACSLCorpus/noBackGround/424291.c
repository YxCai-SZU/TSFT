#include <stdbool.h>

/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (n - 2) * 180;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert (3 <= (n) && (n) <= 100);
    int result;
    //@ assert 1 <= n - 2 && n - 2 <= 98;
    //@ assert (n - 2) * 180 <= 17640;
    result = (n - 2) * 180;
    return result;
}

/*@
    requires (1 <= (n) && (n) <= 100 && 1 <= (m) && (m) <= 100);
    ensures \result == (n == m);
    assigns \nothing;
*/
bool check(int n, int m)
{
    //@ assert (1 <= (n) && (n) <= 100 && 1 <= (m) && (m) <= 100);
    bool result;
    result = (n == m);
    return result;
}
