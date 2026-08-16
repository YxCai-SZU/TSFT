#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_add_range(integer x, integer y) =
        -2147483647 <= x + y <= 2147483647;

    predicate valid_square_range(integer x) =
        -46340 <= x <= 46340;

    logic integer square_val(integer x) = x * x;
    logic integer add_val(integer x, integer y) = x + y;
*/

int32_t add(int32_t x, int32_t y) {
    //@ assert valid_add_range(x, y);
    return x + y;
}

int32_t square(int32_t x) {
    //@ assert valid_square_range(x);
    //@ assert -2147483647 <= x * x <= 2147483647;
    return x * x;
}

/*@
    predicate is_valid_range(integer x) = 0 <= x < 10;

    logic integer product_mod2(integer x, integer y) = (x * y) % 2;

    lemma product_bound: \forall integer x, y; 
        is_valid_range(x) && is_valid_range(y) ==> x * y < 100;
*/

bool func(int x, int y) {
    unsigned long long x_unsigned;
    unsigned long long y_unsigned;
    unsigned long long product;
    long long remainder;
    
    x_unsigned = (unsigned long long)x;
    y_unsigned = (unsigned long long)y;
    
    product = x_unsigned * y_unsigned;
    
    remainder = (long long)product;
    
    while (remainder >= 2) {
        //@ assert remainder >= 2;
        remainder -= 2;
    }
    
    while (remainder < 0) {
        //@ assert remainder < 0;
        remainder += 2;
    }
    
    //@ assert remainder == 0 || remainder == 1;
    return remainder == 0;
}

/*@
    predicate valid_product_parity_pair(integer a, integer b) =
        valid_square_range(a) && 
        valid_add_range(square_val(a), b) &&
        is_valid_range((square_val(a) + b) / 100) &&
        is_valid_range((square_val(a) + b) % 10);
*/

bool compute_square_add_parity(int32_t x, int32_t y) {
    int32_t squared;
    int32_t sum;
    int quotient;
    int remainder;
    bool parity_result;
    
    //@ assert valid_square_range(x);
    squared = square(x);
    //@ assert squared == square_val(x);
    
    //@ assert valid_add_range(squared, y);
    sum = add(squared, y);
    //@ assert sum == add_val(squared, y);
    
    //@ assert 0 <= sum / 100 < 10;
    //@ assert 0 <= sum % 10 < 10;
    quotient = sum / 100;
    remainder = sum % 10;
    
    //@ assert is_valid_range(quotient);
    //@ assert is_valid_range(remainder);
    
    parity_result = func(quotient, remainder);
    
    //@ assert parity_result == (product_mod2(quotient, remainder) == 0);
    
    return parity_result;
}
