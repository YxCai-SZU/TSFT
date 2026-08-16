#include <stdbool.h>
#include <stdint.h>

/* First function: range check */
/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate x_in_range(integer x) = 1 <= x <= 200;
    
    logic integer sum(integer a, integer b) = a + b;
    
    lemma branch_lemma:
        \forall integer a, b, x;
        a_in_range(a) && b_in_range(b) && x_in_range(x) && a + b >= x ==>
        x - a <= b;
*/

bool func_range(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;
    
    //@ assert a_in_range(a) && b_in_range(b) && x_in_range(x);
    
    if (a > x)
    {
        result = false;
        //@ assert !(a <= x && a + b >= x);
    }
    else if (a + b < x)
    {
        result = false;
        //@ assert !(a <= x && a + b >= x);
    }
    else
    {
        unsigned int y = x - a;
        
        //@ assert y <= b;
        //@ assert a <= x && a + b >= x;
        
        result = (y <= b);
    }
    
    return result;
}

/* Second function: modulo and multiplication check */
/*@
    predicate is_in_range(integer N) = 1 <= N <= 1000000;
    
    logic integer mod_100(integer N) = N % 100;
    logic integer times_21(integer N) = mod_100(N) * 21;
    
    lemma mod_property: \forall integer N; 
        is_in_range(N) ==> 0 <= mod_100(N) < 100;
    lemma times_21_bound: \forall integer N; 
        is_in_range(N) ==> 0 <= times_21(N) <= 2100;
*/

uint32_t func_mod(uint32_t N) {
    uint32_t num;
    uint32_t num2;
    uint32_t quotient = 0;
    uint32_t remainder = N;
    uint32_t divisor = 100;
    uint32_t num3;
    
    num = N % 100;
    num2 = num * 21;
    
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }
    
    num3 = quotient * 100 + num;
    
    if (num2 <= N && num3 >= N) {
        //@ assert num2 <= N;
        //@ assert num3 >= N;
        //@ assert is_in_range(N);
        //@ assert num * 21 <= N;
        return 1;
    } else {
        return 0;
    }
}

/* Synthesized function: resource allocation validation with modulo constraint
   Scenario: In a system managing resource allocations, we have a resource ID (N) that must satisfy
   certain constraints relative to a range check (a, b, x). The function checks if a resource
   allocation request can be satisfied and if the resource ID meets a modulo-multiplication invariant.
   Data flow: First, the range check validates that a request (a, b, x) is feasible. Then, the modulo
   check validates that the resource ID N satisfies a specific property (21 * (N % 100) <= N).
   The final assertion ensures consistency: if both checks pass, the resource ID is valid.
*/
int synthesized_func(unsigned int a, unsigned int b, unsigned int x, uint32_t N) {
    bool range_ok = func_range(a, b, x);
    uint32_t mod_ok = func_mod(N);
    
    //@ assert (range_ok == (a <= x && a + b >= x)) && (mod_ok == 1 ==> times_21(N) <= N);
    
    if (range_ok && mod_ok == 1) {
        //@ assert a <= x && a + b >= x && times_21(N) <= N;
        return 1;
    } else {
        return 0;
    }
}
