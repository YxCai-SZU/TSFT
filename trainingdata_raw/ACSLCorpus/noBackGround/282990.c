#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a * b % 2 == 0);
    assigns \nothing;
*/
bool func(int a, int b) {
    unsigned int a_unsigned;
    unsigned int b_unsigned;
    unsigned int product;
    bool result;
    unsigned int temp;
    
    a_unsigned = (unsigned int)a;
    b_unsigned = (unsigned int)b;
    
    //@ assert a_unsigned <= 10000 && b_unsigned <= 10000;
    
    //@ assert a_unsigned * b_unsigned <= 10000 * 10000;
    
    product = a_unsigned * b_unsigned;
    result = false;
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
    
    if (temp == 0) {
        result = true;
    }
    
    //@ assert result == (product % 2 == 0);
    
    return result;
}
