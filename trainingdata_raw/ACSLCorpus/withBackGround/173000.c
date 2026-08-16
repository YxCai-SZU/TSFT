#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    logic integer product(integer a, integer b) = a * b;
    logic integer abs_val(integer x) = x < 0 ? -x : x;
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (product(a, b) % 2 == 0);
*/
bool func(int a, int b)
{
    int product;
    int abs_product;
    int remainder;

    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert 1 <= product(a, b) <= 10000 * 10000;
    
    product = a * b;
    
    //@ assert product == product(a, b);
    
    if (product < 0) {
        abs_product = -product;
    } else {
        abs_product = product;
    }
    
    //@ assert abs_product == abs_val(product);
    
    remainder = abs_product;
    
    /*@
        loop invariant 0 <= remainder <= abs_product;
        loop invariant remainder % 2 == abs_product % 2;
        loop invariant 1 <= a <= 10000;
        loop invariant 1 <= b <= 10000;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
    }
    
    //@ assert remainder == 0 ==> is_even(abs_product);
    //@ assert remainder != 0 ==> !is_even(abs_product);
    
    return remainder == 0;
}

int main() {
    return 0;
}
