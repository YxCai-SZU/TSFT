#include <stdbool.h>

/* First function: check if a value satisfies a certain property */
/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;

    logic integer div_100(integer x) = x / 100;
    logic integer mod_100(integer x) = x % 100;
    logic integer expr_value(integer x) = 
        (div_100(x) * 100 + mod_100(x)) / 100 + (div_100(x) + mod_100(x)) / 100;

    lemma no_overflow_n: 
        \forall integer x; is_valid_range(x) ==> div_100(x) * 100 <= 100000;
    lemma no_overflow_sum: 
        \forall integer x; is_valid_range(x) ==> div_100(x) * 100 + mod_100(x) <= 100000;
    lemma no_overflow_div_sum: 
        \forall integer x; is_valid_range(x) ==> (div_100(x) + mod_100(x)) / 100 <= 100000;
    lemma no_overflow_final: 
        \forall integer x; is_valid_range(x) ==> 
            (div_100(x) * 100 + mod_100(x)) / 100 + (div_100(x) + mod_100(x)) / 100 <= 100000;
*/

bool func(unsigned int x) {
    unsigned int n;
    unsigned int m;
    bool result;

    n = x / 100;
    m = x % 100;

    //@ assert n * 100 <= 100000;
    //@ assert n * 100 + m <= 100000;
    //@ assert (n + m) / 100 <= 100000;
    //@ assert (n * 100 + m) / 100 + (n + m) / 100 <= 100000;

    result = (x >= (n * 100 + m) / 100 + (n + m) / 100);
    return result;
}

/* Second function: compute a result based on two distinct values in a small range */
/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 3 &&
        1 <= b && b <= 3 &&
        a != b;

    logic integer compute_c(integer a, integer b) = 6 - a - b;

    logic integer compute_result(integer c) = c * 2 + 1;

    lemma result_nonnegative:
        \forall integer a, b, c;
        valid_range(a, b) && c == compute_c(a, b) ==>
        compute_result(c) >= 0;
*/

int func2(unsigned int a, unsigned int b)
{
    unsigned int c;
    int result;

    //@ assert valid_range(a, b);
    c = 6 - a - b;
    //@ assert c == compute_c(a, b);
    result = (int)c * 2 + 1;
    //@ assert result == compute_result(c);
    //@ assert result >= 0;
    return result;
}

/* Synthesized function: process a data packet identifier and extract a valid configuration
   Real-world scenario: In a network protocol, a packet identifier (1-100000) is checked for
   validity (e.g., meets minimum size requirement), and then two configuration fields (a, b)
   extracted from the identifier are used to compute a derived configuration parameter c.
   The final assertion verifies that the computed configuration parameter is non-negative. */
int process_packet(unsigned int x)
{
    unsigned int a, b;
    bool valid;
    int config;

    valid = func(x);
    //@ assert valid == (x >= expr_value(x));

    a = x / 10000;
    b = (x / 100) % 100;

    config = func2(a, b);
    //@ assert config >= 0;

    //@ assert config >= 0;
    return config;
}
