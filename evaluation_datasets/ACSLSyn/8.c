#include <stdbool.h>
#include <stdint.h>

/*@
    predicate in_range1(integer n) = 1 <= n <= 10000;
    logic integer mod_100(integer n) = n % 100;
    predicate result_condition(integer n) = mod_100(n) >= 50 || mod_100(n) < 5;
*/
bool func1(int n)
{
    int remainder;
    remainder = n % 100;
    return remainder >= 50 || remainder < 5;
}

/*@ predicate in_range2(integer v) = 0 <= v <= 100; */
bool func2(int A, int B, int C)
{
    return A <= C && C <= B;
}

/*@
    predicate valid_range(integer x) = 1 <= x <= 1000000000000000000;
    logic integer max_val(integer a, integer c) = (a > c) ? a : c;
    logic integer min_val(integer b, integer d) = (b < d) ? b : d;
    lemma range_preservation:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==>
            valid_range(max_val(a, c)) && valid_range(min_val(b, d));
*/
bool func3(unsigned long long a, unsigned long long b,
          unsigned long long c, unsigned long long d)
{
    return (c <= b && b <= d && d <= a + b + 1);
}

/*@
    predicate is_valid_option(integer opt, integer default_val, integer result) =
        (opt == 0 && result == default_val) ||
        (opt != 0 && result == opt);
    lemma test_option_lemma:
        \forall integer some_val, no_val, default_val;
            (some_val != 0 ==> is_valid_option(some_val, default_val, some_val)) &&
            (no_val == 0 ==> is_valid_option(no_val, default_val, default_val));
    logic integer bitwise_and(integer a, integer b) = a & b;
*/
bool func4(uint32_t a, uint32_t b)
{
    return (a & b) != 0;
}

/*@
    predicate valid_packet(integer n, integer A, integer B, integer C,
                           unsigned long long a, unsigned long long b,
                           unsigned long long c, unsigned long long d,
                           uint32_t flag_a, uint32_t flag_b) =
        in_range1(n) && in_range2(A) && in_range2(B) && in_range2(C) &&
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) &&
        flag_a > 0 && flag_a <= 0xFFFFFFFF && flag_b > 0 && flag_b <= 0xFFFFFFFF &&
        result_condition(n) &&
        (A <= C && C <= B) &&
        (c <= b && b <= d && d <= a + b + 1) &&
        ((flag_a & flag_b) != 0);
*/

bool validate_packet(int n, int A, int B, int C,
                    unsigned long long a, unsigned long long b,
                    unsigned long long c, unsigned long long d,
                    uint32_t flag_a, uint32_t flag_b)
{
    bool check1, check2, check3, check4;
    bool result;
    
    check1 = func1(n);
    check2 = func2(A, B, C);
    check3 = func3(a, b, c, d);
    check4 = func4(flag_a, flag_b);
    
    result = check1 && check2 && check3 && check4;
    
    return result;
}
