#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_even(integer a) = (a % 2) == 0;
    predicate is_odd(integer a) = (a % 2) == 1;
    
    logic integer half(integer a) = a / 2;
    
    lemma half_property: \forall integer a; 1 <= a <= 1000000 ==> 
        (is_even(a) ==> half(a) == half(a)) && 
        (is_odd(a) ==> half(a) - 1 == half(a) - 1);
*/

long func1(long a) {
    long result;
    long temp_a;
    long count;
    bool is_even;
    
    result = 0;
    temp_a = a;
    count = 0;
    is_even = true;
    
    while (temp_a >= 2) {
        temp_a -= 2;
        count += 1;
    }
    
    if (temp_a == 1 || temp_a == 0) {
        is_even = true;
    } else {
        is_even = false;
    }
    
    if (is_even) {
        result = count;
    } else {
        result = count - 1;
    }
    
    //@ assert result == (a / 2) - 1 || result == (a / 2);
    
    return result;
}

/*@
    predicate is_valid_n(integer n) =
        n >= 1 && n <= 1000000000;

    logic integer func_result(integer n) =
        n % 2 == 0 ? 0 :
        (n / 2) / 3 * 2 + (
            (n / 2) % 3 == 0 ? 0 :
            (n / 2) % 3 == 1 ? 1 : 2
        );

    lemma result_non_negative:
        \forall integer n; is_valid_n(n) ==> func_result(n) >= 0;

    lemma result_leq_n:
        \forall integer n; is_valid_n(n) ==> func_result(n) <= n;

    lemma half_n_bound:
        \forall integer n; is_valid_n(n) && n % 2 != 0 ==> n / 2 <= 500000000;
*/

uint64_t func2(uint64_t n)
{
    uint64_t half_n;
    uint64_t result;

    if (n % 2 == 0) {
        //@ assert n % 2 == 0 ==> func_result(n) == 0;
        return 0;
    } else {
        //@ assert n >= 1 && n <= 1000000000;
        //@ assert n / 2 <= 500000000;
        
        half_n = n / 2;
        
        //@ assert half_n >= 0 && half_n <= 500000000;
        
        if (half_n % 3 == 0) {
            result = (half_n / 3) * 2 + 0;
        } else if (half_n % 3 == 1) {
            result = (half_n / 3) * 2 + 1;
        } else {
            result = (half_n / 3) * 2 + 2;
        }
        
        //@ assert result == func_result(n);
        //@ assert result >= 0;
        //@ assert result <= n;
        
        return result;
    }
}

/*@
    predicate valid_input(integer a, integer b) =
        a >= 1 && a <= 1000000 && b >= 1 && b <= 1000000000 && b % 2 != 0;

    predicate combined_property(integer a, integer b, integer r1, integer r2) =
        (r1 == (a / 2) - 1 || r1 == (a / 2)) &&
        (r2 >= 0 && r2 <= b) &&
        (r1 + r2 <= a + b);
*/

struct pair_result {
    long first;
    uint64_t second;
} synthesize_func(long a, uint64_t b) {
    struct pair_result res;
    
    long r1 = func1(a);
    
    uint64_t r2 = func2(b);
    
    res.first = r1;
    res.second = r2;
    
    //@ assert r1 + r2 <= a + b;
    
    return res;
}
