#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    ensures \result == (((a * b) % 2) == 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    // Variable declarations at top of scope
    int product;
    bool is_even;
    int abs_product;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    
    //@ assert (1 <= (a * b) <= 10000 * 10000);
    product = a * b;
    
    is_even = true;
    
    if (product < 0) {
        abs_product = -product;
    } else {
        abs_product = product;
    }
    
    /*@
        loop invariant 0 <= abs_product <= product;
        loop invariant abs_product <= 10000 * 10000;
        loop invariant (abs_product % 2 == 0) ==> is_even;
        loop invariant (1 <= (a) <= 10000);
        loop invariant (1 <= (b) <= 10000);
        loop invariant (1 <= (product) <= 10000 * 10000);
        loop invariant abs_product % 2 == product % 2;
        loop assigns abs_product, is_even;
        loop variant abs_product;
    */
    while (abs_product > 0)
    {
        if (abs_product == 1) {
            is_even = false;
            break;
        }
        abs_product -= 2;
    }
    
    //@ assert is_even == (product % 2 == 0);
    return is_even;
}

int main() {
    return 0;
}
