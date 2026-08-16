#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == ((a * b) > (c * d));
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    int product1;
    int product2;
    bool result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    //@ assert a * b <= 10000;
    
    //@ assert (1 <= (c) <= 100) && (1 <= (d) <= 100);
    //@ assert c * d <= 10000;
    
    product1 = a * b;
    product2 = c * d;
    result = product1 > product2;
    
    //@ assert result == ((a * b) > (c * d));
    return result;
}
