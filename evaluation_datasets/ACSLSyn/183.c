#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    logic integer product(integer a, integer b) = a * b;
    lemma product_bound: \forall integer a, b; 1 <= a <= 10000 && 1 <= b <= 10000 ==> product(a, b) <= 100000000;
    
    predicate is_divisible_by_200(integer n) = n % 200 == 0;
    predicate should_return_true(integer n) = n >= 2000 || is_divisible_by_200(n);
    
    lemma division_property:
        \forall integer n, q, r;
            n >= 0 && r == n - q * 200 && r >= 0 && r < 200 ==>
            q == n / 200 && r == n % 200;
*/

bool func1(int a, int b) {
    unsigned int a_unsigned;
    unsigned int b_unsigned;
    unsigned int product_val;
    bool result;

    a_unsigned = (unsigned int)a;
    b_unsigned = (unsigned int)b;

    //@ assert a_unsigned <= 10000;
    //@ assert b_unsigned <= 10000;
    //@ assert a_unsigned * b_unsigned <= 100000000;

    product_val = a_unsigned * b_unsigned;
    result = (product_val % 2) == 0;
    return result;
}

bool func2(unsigned long long N)
{
    unsigned long long quotient;
    unsigned long long remainder;

    if (N >= 2000)
    {
        //@ assert N >= 2000;
        return true;
    }

    quotient = 0;
    remainder = N;

    while (remainder >= 200)
    {
        //@ assert remainder >= 200;
        quotient += 1;
        remainder -= 200;
        //@ assert remainder == N - quotient * 200;
    }

    //@ assert remainder == N % 200;
    if (remainder == 0)
    {
        //@ assert is_divisible_by_200(N);
        return true;
    }
    else
    {
        //@ assert !is_divisible_by_200(N);
        return false;
    }
}

bool process_product_condition(int a, int b) {
    unsigned int a_unsigned = (unsigned int)a;
    unsigned int b_unsigned = (unsigned int)b;
    unsigned int product_val;
    bool is_even_result;
    bool is_divisible_or_large_result;
    bool final_result;

    //@ assert a_unsigned <= 10000 && b_unsigned <= 10000;
    //@ assert a_unsigned * b_unsigned <= 100000000;

    product_val = a_unsigned * b_unsigned;

    //@ assert product_val == product(a, b);
    //@ assert product_val <= 100000000;

    is_even_result = func1(a, b);
    //@ assert is_even_result == (product_val % 2 == 0);

    is_divisible_or_large_result = func2((unsigned long long)product_val);
    //@ assert is_divisible_or_large_result == (product_val >= 2000 || product_val % 200 == 0);

    final_result = is_even_result && is_divisible_or_large_result;
    //@ assert final_result == ((product_val % 2 == 0) && (product_val >= 2000 || product_val % 200 == 0));

    return final_result;
}
