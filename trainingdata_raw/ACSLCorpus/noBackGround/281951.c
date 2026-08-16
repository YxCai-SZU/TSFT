#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 20 &&
        1 <= (c) && (c) <= 2000);
    ensures \result >= 0;
    ensures \result <= ((a) * (b));
    ensures \result == ((a) * (b)) || \result == c;
    ensures \result == c ==> c <= ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int product;
    int result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 20;
    //@ assert ((a) * (b)) <= 2000;

    product = a * b;
    
    if (product < c) {
        result = product;
    } else {
        result = c;
    }

    //@ assert result >= 0;
    //@ assert result <= ((a) * (b));
    
    return result;
}
