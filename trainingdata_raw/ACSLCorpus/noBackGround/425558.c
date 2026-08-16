#include <stdbool.h>

/*@
    requires (1 <= (h) <= 10000 && 1 <= (n) <= 10000);
    ensures \result == (h % 500 <= n);
    assigns \nothing;
*/
bool func(unsigned int h, unsigned int n)
{
    unsigned int pay;
    bool res;

    //@ assert (1 <= (h) <= 10000 && 1 <= (n) <= 10000);
    
    pay = (h / 500) * 500;
    res = (h % 500) <= n;
    
    //@ assert res == (h % 500 <= n);
    
    return res;
}
