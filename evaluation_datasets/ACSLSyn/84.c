#include <stdbool.h>
#include <stddef.h>

/*@
    predicate divides(integer x, integer y) =
        y != 0 && x % y == 0;
*/

/*@
    logic integer division(integer x, integer y) =
        x / y;
*/

/*@
    lemma division_property:
        \forall integer x, y;
            divides(x, y) ==> division(x, y) * y == x;
*/

/*@
    predicate is_valid_k(integer k) = 2 <= k <= 100;
    
    logic integer half_k(integer k) = k / 2;
    logic integer half_k_plus_one(integer k) = (k + 1) / 2;
    
    lemma half_k_bounds:
        \forall integer k; is_valid_k(k) ==> 1 <= half_k(k) <= 50;
    
    lemma half_k_plus_one_bounds:
        \forall integer k; is_valid_k(k) ==> 1 <= half_k_plus_one(k) <= 50;
    
    lemma multiplication_bounds:
        \forall integer k; is_valid_k(k) ==> 
            half_k(k) * half_k_plus_one(k) <= 2500;
*/

bool is_divisible(unsigned int x, unsigned int y)
{
    //@ assert y != 0;
    return x % y == 0;
}

unsigned int divide(unsigned int x, unsigned int y)
{
    //@ assert y != 0;
    //@ assert x % y == 0;
    return x / y;
}

size_t func(size_t k)
{
    size_t half;
    size_t half_plus_one;
    size_t result;
    
    //@ assert is_valid_k(k);
    
    //@ assert 1 <= half_k(k);
    //@ assert half_k(k) <= 50;
    
    //@ assert 1 <= half_k_plus_one(k);
    //@ assert half_k_plus_one(k) <= 50;
    
    //@ assert half_k(k) * half_k_plus_one(k) <= 2500;
    
    half = k / 2;
    half_plus_one = (k + 1) / 2;
    result = half * half_plus_one;
    
    //@ assert result == half_k(k) * half_k_plus_one(k);
    
    return result;
}

unsigned int compute_complex_result(unsigned int k, unsigned int y)
{
    unsigned int quotient;
    size_t product;
    
    //@ assert k >= 2 && k <= 100;
    //@ assert y != 0;
    //@ assert k % y == 0;
    
    quotient = divide(k, y);
    //@ assert quotient == k / y;
    
    //@ assert is_valid_k(k);
    product = func(k);
    //@ assert product == half_k(k) * half_k_plus_one(k);
    
    //@ assert quotient * product == (k / y) * (half_k(k) * half_k_plus_one(k));
    return quotient * product;
}
