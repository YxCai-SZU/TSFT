#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == true <==> (a * b > c * d);
*/
bool func(int a, int b, int c, int d)
{
    int product1;
    int product2;
    bool result;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    //@ assert 0 <= a * b <= 100000000;
    //@ assert 0 <= c * d <= 100000000;
    
    product1 = a * b;
    product2 = c * d;
    
    // Check for overflow in the multiplication
    if (product1 < 0) {
        result = false;
        return result;
    } else if (product2 < 0) {
        result = true;
        return result;
    }
    
    //@ assert product1 == a * b;
    //@ assert product2 == c * d;
    
    result = product1 > product2;
    return result;
}
