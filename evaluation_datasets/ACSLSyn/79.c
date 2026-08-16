#include <limits.h>

/*@
    predicate is_nine(integer a) = a == 9;
    predicate is_three(integer a) = a == 3;
    predicate is_four(integer b) = b == 4;
    predicate is_twelve(integer a) = a == 12;
    predicate is_seventeen(integer a) = a == 17;
    predicate is_five(integer b) = b == 5;

    lemma calc_example_nine_plus_nine:
        \forall integer a; is_nine(a) ==> a + a == 18;
    lemma calc_example_a_times_b:
        \forall integer a, integer b; is_three(a) && is_four(b) ==> a * b == 12;
    lemma calc_example_a_div_b:
        \forall integer a, integer b; is_twelve(a) && b == 3 ==> a / b == 4;
    lemma calc_example_a_mod_b:
        \forall integer a, integer b; is_seventeen(a) && is_five(b) ==> a % b == 2;

    predicate is_valid_n(integer n) = 1 <= n && n <= 1000000000000;
    predicate is_valid_m(integer m) = 1 <= m && m <= 1000000000000;
    
    logic integer abs_val(integer x) = x < 0 ? -x : x;
    
    lemma abs_positive: \forall integer x; abs_val(x) >= 0;
    lemma abs_sum_bound: \forall integer n, m; 
        is_valid_n(n) && is_valid_m(m) ==> 
        abs_val(n) + abs_val(m) <= 2000000000000;
*/

long long func(long long n, long long m) {
    long long ans = 0;
    long long n_abs = 0;
    long long m_abs = 0;
    long long min_val = 0;
    long long n_abs_remaining = 0;
    long long m_abs_remaining = 0;
    long long n_div_4 = 0;
    long long m_div_4 = 0;
    long long temp = 0;
    
    n_abs = n < 0 ? -n : n;
    m_abs = m < 0 ? -m : m;
    
    //@ assert n_abs == abs_val(n);
    //@ assert m_abs == abs_val(m);
    
    min_val = n_abs;
    if (m_abs < min_val) {
        min_val = m_abs;
    }
    ans += min_val;
    
    //@ assert ans >= 0;
    //@ assert ans <= n_abs + m_abs;
    
    n_abs_remaining = n_abs - min_val;
    m_abs_remaining = m_abs - min_val;
    
    //@ assert n_abs_remaining >= 0;
    //@ assert m_abs_remaining >= 0;
    
    n_div_4 = 0;
    temp = n_abs_remaining;
    while (temp >= 4) {
        temp -= 4;
        n_div_4 += 1;
    }
    
    //@ assert n_abs_remaining == temp + 4 * n_div_4;
    
    m_div_4 = 0;
    temp = m_abs_remaining;
    while (temp >= 4) {
        temp -= 4;
        m_div_4 += 1;
    }
    
    //@ assert m_abs_remaining == temp + 4 * m_div_4;
    
    if (n_div_4 < m_div_4) {
        ans += n_div_4;
    } else {
        ans += m_div_4;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n_abs + m_abs;
    
    return ans;
}

/*@
    predicate is_valid_config(integer a, integer b) = 
        (a == 9 && b == 9) || (a == 3 && b == 4) || (a == 12 && b == 3) || (a == 17 && b == 5);
    
    predicate result_property(integer result, integer a, integer b) =
        (a == 9 && b == 9 && result == 18) ||
        (a == 3 && b == 4 && result == 12) ||
        (a == 12 && b == 3 && result == 4) ||
        (a == 17 && b == 5 && result == 2);
*/

int compute_arithmetic(int a, int b) {
    int result;
    
    if (a == 9 && b == 9) {
        //@ assert is_nine(a);
        result = a + a;
        //@ assert result == 18;
    } else if (a == 3 && b == 4) {
        //@ assert is_three(a);
        //@ assert is_four(b);
        result = a * b;
        //@ assert result == 12;
    } else if (a == 12 && b == 3) {
        //@ assert is_twelve(a);
        result = a / b;
        //@ assert result == 4;
    } else if (a == 17 && b == 5) {
        //@ assert is_seventeen(a);
        //@ assert is_five(b);
        result = a % b;
        //@ assert result == 2;
    } else {
        result = 0;
    }
    
    return result;
}

/*@
    predicate is_valid_arithmetic_result(integer r, integer a, integer b) =
        (a == 9 && b == 9 && r == 18) ||
        (a == 3 && b == 4 && r == 12) ||
        (a == 12 && b == 3 && r == 4) ||
        (a == 17 && b == 5 && r == 2);
    
    predicate is_valid_func_input(integer n, integer m) =
        is_valid_n(n) && is_valid_m(m);
    
    predicate final_property(integer r1, integer r2, integer a, integer b, integer n, integer m) =
        (is_valid_arithmetic_result(r1, a, b) ==> r1 >= 0) &&
        (is_valid_func_input(n, m) ==> r2 >= 0);
*/

long long complex_processing(int a, int b, long long n, long long m) {
    int arith_result = compute_arithmetic(a, b);
    //@ assert is_valid_arithmetic_result(arith_result, a, b);
    
    long long func_result = func(n, m);
    //@ assert func_result >= 0;
    
    long long final_result = (long long)arith_result + func_result;
    
    //@ assert final_result >= 0;
    
    return final_result;
}
