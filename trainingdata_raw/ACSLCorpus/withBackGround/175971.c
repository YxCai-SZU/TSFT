#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = 1 <= x <= 10000;
    
    logic integer product(integer a, integer b) = a * b;
    predicate is_even_product(integer a, integer b) = product(a, b) % 2 == 0;
    
    lemma product_bounds: \forall integer a, b; 
        is_in_range(a) && is_in_range(b) ==> 
        1 <= product(a, b) <= 10000 * 10000;
*/

/*@
    requires is_in_range(a) && is_in_range(b);
    ensures \result == (product(a, b) % 2 == 0);
*/
bool func(long long a, long long b) {
    long long product;
    bool is_even;
    long long abs_product;
    long long remainder;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    
    //@ assert 1 <= a * b <= 10000 * 10000;
    product = a * b;
    
    //@ assert product == a * b;
    
    is_even = false;
    abs_product = product;
    
    if (product < 0) {
        abs_product = -product;
    }
    
    //@ assert abs_product >= 0;
    
    remainder = abs_product;
    
    /*@
        loop invariant 0 <= remainder <= abs_product;
        loop invariant remainder % 2 == abs_product % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
    }
    
    if (remainder == 0) {
        is_even = true;
    }
    
    //@ assert is_even == (abs_product % 2 == 0);
    
    return is_even;
}

int main() {
    return 0;
}
