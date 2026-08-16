#include <stdbool.h>
#include <stdint.h>

/* ===== Original Function 1: Nearest neighbor check in sorted sequence ===== */
/*@
    predicate is_sorted(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;

    logic integer abs_diff(integer x, integer y) =
        x > y ? x - y : y - x;

    logic integer min4(integer d1, integer d2, integer d3, integer d4) =
        d1 < d2 ?
            (d1 < d3 ?
                (d1 < d4 ? d1 : d4) :
                (d3 < d4 ? d3 : d4)) :
            (d2 < d3 ?
                (d2 < d4 ? d2 : d4) :
                (d3 < d4 ? d3 : d4));

    lemma min_is_one_of:
        \forall integer d1, d2, d3, d4;
            min4(d1, d2, d3, d4) == d1 ||
            min4(d1, d2, d3, d4) == d2 ||
            min4(d1, d2, d3, d4) == d3 ||
            min4(d1, d2, d3, d4) == d4;
*/

bool func1(unsigned int A, unsigned int B, unsigned int C,
          unsigned int D, unsigned int E, unsigned int K)
{
    unsigned int diff1;
    unsigned int diff2;
    unsigned int diff3;
    unsigned int diff4;
    unsigned int min_diff;

    diff1 = (A > B) ? (A - B) : (B - A);
    diff2 = (A > C) ? (A - C) : (C - A);
    diff3 = (A > D) ? (A - D) : (D - A);
    diff4 = (A > E) ? (A - E) : (E - A);

    //@ assert diff1 == abs_diff(A, B);
    //@ assert diff2 == abs_diff(A, C);
    //@ assert diff3 == abs_diff(A, D);
    //@ assert diff4 == abs_diff(A, E);

    if (diff1 < diff2) {
        if (diff1 < diff3) {
            if (diff1 < diff4) {
                min_diff = diff1;
            } else {
                min_diff = diff4;
            }
        } else {
            if (diff3 < diff4) {
                min_diff = diff3;
            } else {
                min_diff = diff4;
            }
        }
    } else {
        if (diff2 < diff3) {
            if (diff2 < diff4) {
                min_diff = diff2;
            } else {
                min_diff = diff4;
            }
        } else {
            if (diff3 < diff4) {
                min_diff = diff3;
            } else {
                min_diff = diff4;
            }
        }
    }

    //@ assert min_diff == min4(diff1, diff2, diff3, diff4);
    //@ assert min_diff == diff1 || min_diff == diff2 || min_diff == diff3 || min_diff == diff4;

    return min_diff <= K;
}

/* ===== Original Function 2: Compute (a*b) - (a+b-1) ===== */
/*@
    predicate a_in_range(integer a) = 2 <= a <= 100;
    predicate b_in_range(integer b) = 2 <= b <= 100;
    predicate both_in_range(integer a, integer b) = a_in_range(a) && b_in_range(b);
    
    logic integer max_val(integer a, integer b) = (a > b) ? a : b;
    logic integer min_val(integer a, integer b) = (a < b) ? a : b;
    
    lemma max_min_bounds:
        \forall integer a, b;
        both_in_range(a, b) ==>
        max_val(a, b) >= 2 && max_val(a, b) <= 100 &&
        min_val(a, b) >= 2 && min_val(a, b) <= 100;
    
    lemma sum_bound:
        \forall integer a, b;
        both_in_range(a, b) ==>
        max_val(a, b) + min_val(a, b) <= 200;
    
    lemma product_bound:
        \forall integer a, b;
        both_in_range(a, b) ==>
        4 <= a * b <= 10000;
    
    lemma product_ge_sum_minus_one:
        \forall integer a, b;
        both_in_range(a, b) ==>
        a * b >= a + b - 1;
    
    lemma result_bound:
        \forall integer a, b;
        both_in_range(a, b) ==>
        0 <= a * b - (a + b - 1) <= 9999;
*/

int32_t func2(uint32_t a, uint32_t b)
{
    uint32_t max;
    uint32_t min;
    
    //@ assert both_in_range(a, b);
    
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    
    if (a < b) {
        min = a;
    } else {
        min = b;
    }
    
    //@ assert max == max_val(a, b);
    //@ assert min == min_val(a, b);
    
    //@ assert max >= 2;
    //@ assert min >= 2;
    //@ assert max <= 100;
    //@ assert min <= 100;
    //@ assert max + min <= 200;
    //@ assert a * b <= 10000;
    //@ assert a * b >= 4;
    //@ assert a * b >= a + b - 1;
    //@ assert a * b - (a + b - 1) <= 9999;
    
    return (int32_t)(a * b - (a + b - 1));
}

/* ===== Original Function 3: Check if two numbers are distinct in range [1,3] ===== */
/*@ predicate valid_range(integer x) = 1 <= x <= 3; */

bool func3(int a, int b)
{
    bool result = false;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    
    if (a == 1) {
        result = (b == 2) || (b == 3);
        //@ assert result == (a == 1 && (b == 2 || b == 3));
    } else if (a == 2) {
        result = (b == 1) || (b == 3);
        //@ assert result == (a == 2 && (b == 1 || b == 3));
    } else if (a == 3) {
        result = (b == 1) || (b == 2);
        //@ assert result == (a == 3 && (b == 1 || b == 2));
    } else {
        //@ assert false;
        result = false;
    }
    
    return result;
}

/* ===== Original Function 4: Check if one number equals sum of other two ===== */
/*@
    predicate is_max(integer a, integer b, integer c, integer m) =
        m == a || m == b || m == c;
*/

/*@
    lemma max_property:
        \forall integer a, b, c, m;
        is_max(a, b, c, m) ==>
        (a + b + c - m == m ==> (a + b == c || a + c == b || b + c == a));
*/

int func4(int a, int b, int c)
{
    int m;
    /*@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100; */
    
    if (a > b)
    {
        m = a;
    }
    else
    {
        m = b;
    }
    
    if (c > m)
    {
        m = c;
    }
    
    /*@ assert is_max(a, b, c, m); */
    /*@ assert a + b + c - m == m ==> (a + b == c || a + c == b || b + c == a); */
    
    return (a + b + c - m == m);
}

/* ===== Synthesized Function: Data packet validation in a sensor network ===== */
/* 
 * Scenario: A sensor node receives 5 sorted readings (A,B,C,D,E) from nearby sensors.
 * It then computes a "reliability score" using func2 on two derived parameters (p,q),
 * checks if the node's own ID (a) and a neighbor ID (b) are distinct using func3,
 * and validates the triangle inequality property of distances (r,s,t) using func4.
 * The final assertion verifies that if the neighbor check fails, the whole validation fails.
 */

int synthesized_func(
    unsigned int A, unsigned int B, unsigned int C,
    unsigned int D, unsigned int E, unsigned int K,
    uint32_t p, uint32_t q,
    int a, int b,
    int r, int s, int t)
{
    bool step1_result;
    int32_t step2_result;
    bool step3_result;
    int step4_result;
    int final_result;

    step1_result = func1(A, B, C, D, E, K);
    
    step2_result = func2(p, q);
    
    step3_result = func3(a, b);
    
    step4_result = func4(r, s, t);
    
    if (step1_result && (step2_result > 0) && step3_result && step4_result) {
        final_result = 1;
    } else {
        final_result = 0;
    }

    /*@ assert (step3_result == 0) ==> (final_result == 0); */
    
    return final_result;
}
