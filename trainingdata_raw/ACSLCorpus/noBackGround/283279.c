#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000);
    ensures \result == (a * b / 2 >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    unsigned int product;
    unsigned int half;
    bool res;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    
    product = a * b;
    //@ assert product == ((a) * (b));
    
    half = product / 2;
    //@ assert half == ((product) / 2);
    
    res = half >= c;
    //@ assert res == (((((a) * (b))) / 2) >= c);
    
    return res;
}
