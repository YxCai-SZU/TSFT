#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000 && 0 <= (a) <= 1000);
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a)
{
    // Variable declarations at top of scope
    unsigned int pay;
    unsigned int remain;
    bool result;

    //@ assert n / 500 <= 20;
    //@ assert (n / 500) * 500 <= 10000;

    pay = (n / 500) * 500;
    remain = n % 500;

    if (remain <= a)
    {
        //@ assert remain <= a;
        result = true;
    }
    else
    {
        //@ assert remain > a;
        result = false;
    }

    return result;
}
