#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* ========== First function (as provided) ========== */

/*@
    predicate in_range(integer x) = 1 <= x <= 100;

    logic integer mod2(integer x) = x % 2;
    logic integer div2(integer x) = x / 2;

    lemma mod2_range: \forall integer x; in_range(x) ==> 0 <= mod2(x) <= 1;
    lemma div2_range: \forall integer x; in_range(x) ==> 0 <= div2(x) <= 50;
    lemma sum_mod2_range: \forall integer a,b,c; in_range(a) && in_range(b) && in_range(c) ==> 0 <= mod2(a)+mod2(b)+mod2(c) <= 3;
    lemma min_div2_bound: \forall integer a,b,c; in_range(a) && in_range(b) && in_range(c) ==> 0 <= ((div2(a) < div2(b) ? div2(a) : div2(b)) < div2(c) ? (div2(a) < div2(b) ? div2(a) : div2(b)) : div2(c)) <= a+b+c;
*/

long func_first(long a, long b, long c) {
    long result;
    long a_mod_2;
    long b_mod_2;
    long c_mod_2;
    long a_div_2;
    long b_div_2;
    long c_div_2;
    long temp_a;
    long temp_b;
    long temp_c;
    long min_val;
    long min_val_tmp;

    result = 0;
    a_mod_2 = a;
    b_mod_2 = b;
    c_mod_2 = c;

    while (a_mod_2 >= 2) {
        //@ assert a_mod_2 >= 2;
        a_mod_2 -= 2;
    }

    while (b_mod_2 >= 2) {
        //@ assert b_mod_2 >= 2;
        b_mod_2 -= 2;
    }

    while (c_mod_2 >= 2) {
        //@ assert c_mod_2 >= 2;
        c_mod_2 -= 2;
    }

    if ((a_mod_2 + b_mod_2 + c_mod_2) >= 3) {
        result += 1;
    } else {
        result += 0;
    }

    a_div_2 = 0;
    b_div_2 = 0;
    c_div_2 = 0;
    temp_a = a;
    temp_b = b;
    temp_c = c;

    while (temp_a >= 2) {
        //@ assert temp_a >= 2;
        temp_a -= 2;
        a_div_2 += 1;
    }

    while (temp_b >= 2) {
        //@ assert temp_b >= 2;
        temp_b -= 2;
        b_div_2 += 1;
    }

    while (temp_c >= 2) {
        //@ assert temp_c >= 2;
        temp_c -= 2;
        c_div_2 += 1;
    }

    min_val_tmp = (a_div_2 < b_div_2) ? a_div_2 : b_div_2;
    min_val = (min_val_tmp < c_div_2) ? min_val_tmp : c_div_2;

    result += min_val;

    //@ assert result >= 0;
    //@ assert result <= a + b + c;

    return result;
}

/* ========== Second function (as provided) ========== */

/*@
    predicate valid_range(integer v) = 1 <= v && v <= 20;
    
    logic integer compute_step(integer v) = 
        (10 * v / 9 < 9) ? (10 * v / 9) : 9;
    
    lemma compute_step_bounds:
        \forall integer v; 1 <= v && v <= 9 ==> 1 <= compute_step(v) && compute_step(v) <= 9;
*/

int32_t func_second(uint32_t A, uint32_t B)
{
    uint32_t x;
    uint32_t y;
    uint32_t i;
    
    //@ assert valid_range(A) && valid_range(B);
    
    if (A > 9 || B > 9)
    {
        //@ assert 0 == 0;
        return 0;
    }
    
    x = 1;
    y = 1;
    i = 1;
    
    while (i < A)
    {
        //@ assert 1 <= x && x <= 9;
        if (10 * x / 9 < 9)
        {
            x = 10 * x / 9;
        }
        else
        {
            x = 9;
        }
        //@ assert 1 <= x && x <= 9;
        i = i + 1;
    }
    
    i = 1;
    
    while (i < B)
    {
        //@ assert 1 <= y && y <= 9;
        if (10 * y / 9 < 9)
        {
            y = 10 * y / 9;
        }
        else
        {
            y = 9;
        }
        //@ assert 1 <= y && y <= 9;
        i = i + 1;
    }
    
    if (x < y)
    {
        //@ assert x < y;
        //@ assert 1 == 1;
        return 1;
    }
    else
    {
        //@ assert x >= y;
        //@ assert 0 == 0;
        return 0;
    }
}

/* ========== Third function (as provided) ========== */

/*@ predicate is_greater(integer a, integer b) = a > b; */

bool func_third(unsigned int v[2]) {
    unsigned int v0;
    unsigned int v1;
    bool result;

    v0 = v[0];
    v1 = v[1];
    if (v0 > v1) {
        result = true;
    } else {
        result = false;
    }
    //@ assert result == true <==> is_greater(v[0], v[1]);
    return result;
}

/* ========== Synthesized complex function ========== */

int synthesized_decision(unsigned int vals[2], long a, long b, long c) {
    long base_score = func_first(a, b, c);
    
    bool greater = func_third(vals);
    
    uint32_t A, B;
    if (greater) {
        A = (uint32_t)(base_score % 20 + 1);
        B = (uint32_t)((a + b + c) % 20 + 1);
    } else {
        A = (uint32_t)((a + b + c) % 20 + 1);
        B = (uint32_t)(base_score % 20 + 1);
    }
    
    //@ assert 1 <= A && A <= 20;
    //@ assert 1 <= B && B <= 20;
    
    int32_t decision = func_second(A, B);
    
    //@ assert (decision == 0 || decision == 1);
    //@ assert (greater == true) ==> (decision == 0 || decision == 1);
    
    return (int)decision;
}
