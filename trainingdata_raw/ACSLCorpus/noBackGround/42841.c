#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == (1000 - n % 1000) % 1000;
*/
int func(int n)
{
    int pay;
    int n_mod;
    int result;

    pay = 1000;
    n_mod = n;

    /*@
        loop invariant (1 <= (n) && (n) <= 10000);
        loop invariant 0 <= n_mod <= n;
        loop invariant ((n_mod) == (n) - (pay) * (((n) - (n_mod)) / (pay)));
        loop assigns n_mod;
        loop variant n_mod;
    */
    while (n_mod >= pay)
    {
        n_mod -= pay;
    }

    /*@
        loop invariant (1 <= (n) && (n) <= 10000);
        loop invariant n_mod < pay;
        loop invariant ((n_mod) == (n) - (pay) * (((n) - (n_mod)) / (pay)));
        loop assigns n_mod;
        loop variant pay - n_mod;
    */
    while (n_mod < 0)
    {
        n_mod += pay;
    }

    if (n_mod == 0)
    {
        result = 0;
    }
    else
    {
        result = pay - n_mod;
    }

    //@ assert result == (1000 - n % 1000) % 1000;

    return result;
}

int main()
{
    return 0;
}
