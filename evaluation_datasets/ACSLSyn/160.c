#include <stdint.h>

/* ACSL specifications for first function (product computation) */
/*@
    predicate in_range(integer v) = 1 <= v <= 10;

    logic integer product(integer a, integer b, integer c) = a * b * c;

    lemma product_bound:
        \forall integer a, b, c;
            in_range(a) && in_range(b) && in_range(c) ==> product(a,b,c) <= 1000;
*/

int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t product_val;
    int32_t result;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert a * b <= 100;
    //@ assert a * b * c <= 1000;

    product_val = a * b * c;
    
    if (product_val <= 1000) {
        result = (int32_t)product_val;
    } else {
        result = -1;
    }
    
    return result;
}

/* ACSL specifications for second function (search for value 2 in cyclic counter) */
/*@
    predicate valid_range(integer n) = 1 <= n && n <= 100000;
    
    logic integer decrement(integer n, integer i) = n - i;
*/

int func2(unsigned int n)
{
    int a;
    unsigned int i;
    int result;
    
    a = 1;
    i = 0;
    result = 0;
    
    while (i < n)
    {
        //@ assert 1 <= a <= 10;
        if (a == 2)
        {
            result = 1;
            //@ assert result == 1;
            return result;
        }
        
        a += 1;
        
        //@ assert a <= 11;
        if (a > 10)
        {
            a -= 10;
        }
        
        //@ assert 1 <= a <= 10;
        i += 1;
    }
    
    //@ assert result == 0;
    return result;
}

/* 
 * Synthesized function: Digital product validator for cyclic counter
 * Real-world scenario: A system that processes 3-digit codes where each digit 
 * (1-10) comes from a cyclic counter, and validates that their product doesn't 
 * exceed system limits. The function first checks if a cyclic counter reaches 
 * the value 2 (indicating a special processing mode), then computes and validates 
 * the product of three consecutive counter states.
 */
int32_t synthesized_func(unsigned int n)
{
    uint32_t a, b, c;
    int32_t prod_result;
    int search_result;
    
    a = 1;
    b = 2;
    c = 3;
    
    search_result = func2(n);
    
    //@ assert search_result == 0 || search_result == 1;
    
    if (search_result == 1)
    {
        //@ assert in_range(a) && in_range(b) && in_range(c);
        prod_result = func(a, b, c);
        
        //@ assert prod_result == product(a,b,c) || prod_result == -1;
    }
    else
    {
        prod_result = -1;
    }
    
    //@ assert prod_result == -1 || (prod_result >= 1 && prod_result <= 1000);
    
    return prod_result;
}

int main()
{
    return 0;
}
