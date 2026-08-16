#include <limits.h>

/*@
    requires (1 <= (n) <= 100);
    ensures (1 <= (\result) <= 100);
    ensures \result == n;
    assigns \nothing;
*/
int func(int n)
{
    int ans;
    //@ assert (1 <= (n) <= 100);
    ans = n;
    //@ assert (1 <= (ans) <= 100);
    //@ assert ans == n;
    return ans;
}

/*@
    requires (1 <= (n) <= 100);
    ensures (1 <= (\result) <= 100);
    ensures \result == n;
    assigns \nothing;
*/
int func2(int n)
{
    int ans;
    //@ assert (1 <= (n) <= 100);
    ans = n;
    //@ assert (1 <= (ans) <= 100);
    //@ assert ans == n;
    return ans;
}

/*@
    requires (1 <= (n) <= 100);
    ensures (1 <= (\result) <= 100);
    ensures \result == n;
    assigns \nothing;
*/
int func3(int n)
{
    int ans;
    //@ assert (1 <= (n) <= 100);
    ans = n;
    //@ assert (1 <= (ans) <= 100);
    //@ assert ans == n;
    return ans;
}
