#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures ((((n)) % 100) < 13) ==> \result == 0;
    ensures ((((n)) % 100) >= 13 && (((n)) % 100) < 30) ==> \result == 1;
    ensures ((((n)) % 100) >= 30 && (((n)) % 100) < 100) ==> \result == 2;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t ans;
    size_t mod;

    //@ assert (1 <= (n) && (n) <= 10000);
    mod = n % 100;
    //@ assert 0 <= mod && mod <= 99;

    if (mod <= 12)
    {
        ans = 0;
        //@ assert ((((n)) % 100) < 13);
    }
    else if (mod <= 29)
    {
        ans = 1;
        //@ assert ((((n)) % 100) >= 13 && (((n)) % 100) < 30);
    }
    else
    {
        ans = 2;
        //@ assert ((((n)) % 100) >= 30 && (((n)) % 100) < 100);
    }

    return ans;
}
