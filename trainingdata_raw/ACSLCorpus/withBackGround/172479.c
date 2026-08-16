#include <stdbool.h>

/*@
    predicate is_odd(integer x) = x % 2 != 0;
    logic integer product(integer a, integer b) = a * b * 2;
*/

/*@
    requires 1 <= A <= 3;
    requires 1 <= B <= 3;
    ensures \result == (A * B * 2 % 2 != 0);
*/
bool func(int A, int B)
{
    bool A_is_odd;
    bool B_is_odd;
    int product;
    bool is_odd;
    int abs_product;
    
    //@ assert 1 <= A * B * 2 <= 18;
    product = A * B * 2;
    is_odd = false;
    abs_product = product;
    
    if (product < 0) {
        abs_product = -product;
    }
    
    /*@
        loop invariant 0 <= abs_product <= product;
        loop invariant abs_product % 2 == product % 2;
        loop invariant (product % 2 == 0) ==> !is_odd;
        loop assigns abs_product;
    */
    while (abs_product >= 2) {
        abs_product -= 2;
    }
    
    if (abs_product == 1) {
        is_odd = true;
    }
    
    //@ assert is_odd == (A * B * 2 % 2 != 0);
    return is_odd;
}
