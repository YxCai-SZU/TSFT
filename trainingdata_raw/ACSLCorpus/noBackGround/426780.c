#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == true <==> ((((a) * (b)) / 2) + 1 >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    unsigned int product;
    unsigned int half;
    bool result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    //@ assert a * b <= 10000;
    product = a * b;
    
    //@ assert product / 2 <= 5000;
    half = product / 2;
    
    result = (half + 1 >= c);
    //@ assert result == ((((a) * (b)) / 2) + 1 >= c);
    return result;
}
