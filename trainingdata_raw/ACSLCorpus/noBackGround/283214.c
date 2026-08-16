#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == true <==> (a * b) % 2 != 0;
*/
bool func(long a, long b) {
    long product;
    bool is_odd = false;
    long abs_product;
    long remainder;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    //@ assert 1 <= a * b <= 10000;
    product = a * b;
    
    abs_product = product;
    if (product < 0) {
        abs_product = -product;
    }
    
    //@ assert abs_product >= 0;
    //@ assert abs_product <= 10000;
    
    remainder = abs_product;
    
    /*@
        loop invariant 0 <= remainder <= abs_product;
        loop invariant remainder % 2 == abs_product % 2;
        loop assigns remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
    }
    
    if (remainder == 1) {
        is_odd = true;
    }
    
    //@ assert is_odd == true <==> (a * b) % 2 != 0;
    return is_odd;
}
