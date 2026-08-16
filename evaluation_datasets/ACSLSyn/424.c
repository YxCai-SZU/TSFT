#include <limits.h>
#include <stdbool.h>

/* ========== Original Function 1: func with a,b ========== */

/*@
    predicate a_in_range(integer a) = 1 <= a <= 16;
    predicate b_in_range(integer b) = 1 <= b <= 16;
    predicate sum_in_range(integer a, integer b) = a + b <= 16;
    predicate both_small(integer a, integer b) = a <= 8 && b <= 8;
*/

int func1(unsigned long long a, unsigned long long b)
{
    int result;
    int a_flag;
    int b_flag;

    result = 0;
    a_flag = 0;
    b_flag = 0;

    if (a <= 8)
    {
        a_flag = 1;
    }

    if (b <= 8)
    {
        b_flag = 1;
    }

    if (a_flag && b_flag)
    {
        result = 1;
    }

    //@ assert result == 1 <==> (a <= 8 && b <= 8);

    return result;
}

/* ========== Original Function 2: func with a,b,c ========== */

/*@
    predicate is_in_range(integer x) = 1 <= x && x <= 9;

    logic integer max_of_two(integer x, integer y) = (x > y) ? x : y;

    lemma max_in_range:
        \forall integer x, y;
            is_in_range(x) && is_in_range(y) ==> is_in_range(max_of_two(x, y));
*/

int func2(int a, int b, int c)
{
    int max_ab;
    int max_bc;
    int max_ac;
    int max;
    int max_final;
    int result;

    //@ assert is_in_range(a) && is_in_range(b) && is_in_range(c);

    max_ab = (a > b) ? a : b;
    //@ assert is_in_range(max_ab);

    max_bc = (b > c) ? b : c;
    //@ assert is_in_range(max_bc);

    max_ac = (a > c) ? a : c;
    //@ assert is_in_range(max_ac);

    max = (max_ab > max_bc) ? max_ab : max_bc;
    //@ assert is_in_range(max);

    max_final = (max > max_ac) ? max : max_ac;
    //@ assert is_in_range(max_final);

    result = max_final * 10 + max_final;

    if (max_ab == max && max_ac == max)
    {
        result += max_bc;
    }
    else if (max_ab == max && max_bc == max)
    {
        result += max_ac;
    }
    else
    {
        result += max_ab;
    }

    //@ assert result >= 10 && result <= 999;
    return result;
}

/* ========== Original Function 3: func with k,a,b ========== */

/*@ predicate is_valid_params(integer k, integer a, integer b) =
        1 <= k && k <= 1000 &&
        1 <= a && a <= b && b <= 1000;
*/

/*@ logic integer div_k(integer x, integer k) = x / k; */

/*@ lemma division_bounds:
        \forall integer k, integer a, integer b;
        is_valid_params(k, a, b) ==>
        div_k(a, k) <= 1000 && div_k(b, k) <= 1000;
*/

bool func3(int k, int a, int b) {
    bool result;
    int b_div_k;
    int a_div_k;
    
    //@ assert 1 <= k && k <= 1000;
    //@ assert 1 <= a && a <= b && b <= 1000;
    
    //@ assert b / k <= 1000;
    //@ assert a / k <= 1000;
    
    if (a == b) {
        result = true;
    } else {
        b_div_k = b / k;
        a_div_k = a / k;
        
        //@ assert b_div_k == b / k;
        //@ assert a_div_k == a / k;
        
        if (b_div_k != a_div_k) {
            result = true;
        } else {
            result = false;
        }
    }
    
    return result;
}

/* ========== Original Function 4: func with x ========== */

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer mod_1000(integer x) = x % 1000;
    logic integer result_formula(integer x) = (1000 - mod_1000(x)) % 1000;

    lemma mod_property: \forall integer x; valid_range(x) ==> 0 <= mod_1000(x) < 1000;
    lemma result_property: \forall integer x; valid_range(x) ==> 0 <= result_formula(x) < 1000;
*/

int func4(int x)
{
    int quotient = 0;
    int remainder = x;
    const int divisor = 1000;

    //@ assert valid_range(x);
    //@ assert remainder == x;

    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient = quotient + 1;
        remainder = remainder - divisor;
        //@ assert remainder == x - quotient * 1000;
    }

    //@ assert quotient == x / 1000;
    //@ assert remainder == x % 1000;

    int result;
    if (remainder == 0)
    {
        result = 0;
    }
    else
    {
        result = 1000 - remainder;
    }

    //@ assert result == result_formula(x);
    return result;
}

/* ========== Synthesized Complex Function ========== */

/*@
    predicate valid_input(integer k, integer a, integer b, integer c, integer x) =
        is_valid_params(k, a, b) && is_in_range(c) && valid_range(x) &&
        1 <= a && a <= 16 && 1 <= b && b <= 16 && a + b <= 16 &&
        (a <= 8 && b <= 8);
*/

int complex_chain(int k, int a, int b, int c, int x) {
    int flag = func1(a, b);
    //@ assert flag == 1 <==> (a <= 8 && b <= 8);
    
    int combined = func2(a, b, c);
    //@ assert combined >= 10 && combined <= 999;
    
    bool division_check = func3(k, a, b);
    //@ assert division_check == true <==> (a == b || (b / k != a / k));
    
    int rounding = func4(x);
    //@ assert rounding >= 0 && rounding < 1000;
    
    int result;
    
    if (flag == 1 && division_check == true) {
        result = rounding;
    } else {
        result = (combined + rounding) % 1000;
    }
    
    //@ assert result >= 0 && result < 1000;
    return result;
}
