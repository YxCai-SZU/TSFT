#include <stdbool.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == (x * y % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y) {
    unsigned int product;
    unsigned int original_product;
    
    //@ assert x * y <= 10000;
    
    original_product = x * y;
    product = original_product;
    
    /*@
        loop invariant product <= original_product;
        loop invariant product >= 0;
        loop invariant product % 2 == original_product % 2;
        loop assigns product;
        loop variant product;
    */
    while (product >= 2) {
        //@ assert product % 2 == original_product % 2;
        product -= 2;
    }
    
    /*@
        loop invariant product < 2;
        loop invariant product % 2 == original_product % 2;
        loop assigns product;
        loop variant 2 + product;
    */
    while (product < 0) {
        //@ assert product % 2 == original_product % 2;
        product += 2;
    }
    
    //@ assert product == original_product % 2;
    return product == 0;
}

int main() {
    return 0;
}
