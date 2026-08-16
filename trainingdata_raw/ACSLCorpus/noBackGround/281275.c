#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000);
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b && \result >= a - b && \result >= a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int product;
    int sum;
    int difference;
    int result;
    
    //@ assert -1000 <= a && a <= 1000;
    //@ assert -1000 <= b && b <= 1000;
    
    // Bounds for product to prevent overflow
    //@ assert -1000000 <= a * b && a * b <= 1000000;
    
    product = a * b;
    sum = a + b;
    difference = a - b;
    
    if (product > sum && product > difference) {
        //@ assert product >= sum;
        //@ assert product >= difference;
        result = product;
    } else if (sum > difference) {
        //@ assert sum >= difference;
        result = sum;
    } else {
        //@ assert difference >= sum;
        result = difference;
    }
    
    // Final verification of postconditions
    //@ assert result == a + b || result == a - b || result == a * b;
    //@ assert result >= a + b;
    //@ assert result >= a - b;
    //@ assert result >= a * b;
    
    return result;
}
