#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && (a) >= -100 && (b) >= -100);
    ensures \result == true <==> (a * b) % 2 == 0;
    assigns \nothing;
*/
bool func(long a, long b)
{
    // Variable declarations at top of scope
    long product;
    bool is_even;
    long abs_product;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100 && (a) >= -100 && (b) >= -100);
    
    product = a * b;
    is_even = false;
    
    if (product < 0) {
        abs_product = -product;
    } else {
        abs_product = product;
    }
    
    /*@
        loop invariant 0 <= abs_product <= product;
        loop invariant abs_product <= 10000;
        loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100 && (a) >= -100 && (b) >= -100);
        loop invariant abs_product % 2 == product % 2;
        loop invariant -10000 <= product <= 10000;
        loop assigns abs_product;
        loop variant abs_product;
    */
    while (abs_product >= 2) {
        abs_product -= 2;
    }
    
    if (abs_product == 0) {
        is_even = true;
    }
    
    //@ assert is_even == ((a * b) % 2 == 0);
    
    return is_even;
}

int main(void)
{
    return 0;
}
