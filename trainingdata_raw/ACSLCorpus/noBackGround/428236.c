#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 100);
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == (k * 500 >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    int value;
    int product;
    
    value = 500;
    
    //@ assert (1 <= (k) && (k) <= 100);
    //@ assert ((k) * 500 <= 100 * 500);
    
    product = k * value;
    
    return product >= x;
}
