#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ((a * b) % 2 != 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    int a_abs;
    int b_abs;
    int product;
    bool is_odd = false;
    int temp;
    
    a_abs = a;
    b_abs = b;
    
    // Implement abs manually
    if (a < 0) {
        a_abs = -a;
    }
    if (b < 0) {
        b_abs = -b;
    }
    
    // Add assertions to prevent overflow
    //@ assert 1 <= a_abs <= 10000;
    //@ assert 1 <= b_abs <= 10000;
    //@ assert a_abs * b_abs <= 100000000;
    
    product = a_abs * b_abs;
    
    temp = product;
    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2) {
        temp -= 2;
    }
    
    if (temp == 1) {
        is_odd = true;
    }
    
    // Final verification of postcondition
    //@ assert is_odd == ((a * b) % 2 != 0);
    
    return is_odd;
}
