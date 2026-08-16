#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000) && (0 <= (a) && (a) <= 1000);
    ensures \result == (((n) % 500) <= a);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a)
{
    unsigned int pay;
    unsigned int remain;
    
    //@ assert 0 <= n % 500 && n % 500 <= 500;
    pay = n / 500 * 500;
    remain = n % 500;
    
    return remain <= a;
}
