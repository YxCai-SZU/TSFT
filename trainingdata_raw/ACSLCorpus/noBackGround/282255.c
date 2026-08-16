#include <stdbool.h>

/*@
    requires (100 <= (n) && (n) <= 999);
    ensures \result == ((n / 100) == 7 || (n / 10 % 10) == 7 || (n % 10) == 7);
*/
bool func(unsigned int n)
{
    unsigned int n_100;
    unsigned int n_10;
    unsigned int n_1;
    bool ans;

    n_100 = n / 100;
    n_10 = n / 10 % 10;
    n_1 = n % 10;
    ans = false;

    if (n_100 == 7)
    {
        ans = true;
    }
    if (n_10 == 7)
    {
        ans = true;
    }
    if (n_1 == 7)
    {
        ans = true;
    }

    //@ assert ans == (n_100 == 7 || n_10 == 7 || n_1 == 7);
    //@ assert n_100 == n / 100;
    //@ assert n_10 == n / 10 % 10;
    //@ assert n_1 == n % 10;
    //@ assert ans == ((n / 100) == 7 || (n / 10 % 10) == 7 || (n % 10) == 7);

    return ans;
}
