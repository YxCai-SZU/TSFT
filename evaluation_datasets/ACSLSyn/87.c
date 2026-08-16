#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_even(integer x) = (x & 1) == 0;
    predicate valid_input(integer x) = 1 <= x && x <= 100;
    
    logic integer compute_result(integer x) = 
        (x / 10) * 9 + (x % 10);
*/

bool is_even(int x)
{
    bool ret;
    
    //@ assert (x & 1) == 0 ==> (x & 1) == 0;
    
    ret = (x & 1) == 0;
    return ret;
}

uint32_t func(uint32_t x)
{
    uint32_t t;
    uint32_t n;
    uint32_t result;

    t = x / 10;
    n = x % 10;

    //@ assert t == x / 10;
    //@ assert n == x % 10;

    result = (t * 9) + n;
    return result;
}

int process_number(uint32_t x)
{
    uint32_t transformed;
    bool even_check;
    
    transformed = func(x);
    
    //@ assert transformed == compute_result(x);
    
    even_check = is_even((int)transformed);
    
    //@ assert even_check == ((transformed & 1) == 0);
    
    //@ assert (even_check == 1) <==> is_even(compute_result(x));
    
    return even_check ? 1 : 0;
}
