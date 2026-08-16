#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 50 &&
        1 <= (b) && (b) <= 50);
    ensures \result == ((n) * (a)) || \result == b;
    ensures \result <= ((n) * (a));
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int result;
    int product;

    //@ assert (1 <= (n) && (n) <= 20 &&         1 <= (a) && (a) <= 50 &&         1 <= (b) && (b) <= 50);
    
    product = n * a;
    
    //@ assert 1 <= product && product <= 1000;
    
    if (product < b) {
        result = product;
    } else {
        result = b;
    }
    
    //@ assert result == product || result == b;
    //@ assert result <= product;
    //@ assert result <= b;
    
    return result;
}
