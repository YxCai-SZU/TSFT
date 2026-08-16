#include <stdbool.h>
#include <stddef.h>

/* ===== Original Functions with ACSL Specifications ===== */

/* Function 1: Check if a*a <= a*b */
/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer square(integer x) = x * x;
    logic integer product(integer x, integer y) = x * y;

    lemma square_bound: \forall integer a; 1 <= a <= 100 ==> square(a) <= 10000;
    lemma product_bound: \forall integer a, b; 1 <= a <= 100 && 1 <= b <= 100 ==> product(a, b) <= 10000;
*/

bool func1(long a, long b)
{
    bool result = false;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    if (a <= 0 || b <= 0 || a > 100 || b > 100) {
        return false;
    }
    
    //@ assert a * a <= 10000;
    //@ assert a * b <= 10000;
    
    if (a * a <= a * b) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}

/* Function 2: Check divisibility by 4 for three expressions */
/*@
    predicate valid_input(int *v) =
        \valid(v) &&
        v[0] >= 1 && v[0] <= 9 &&
        v[1] >= 1 && v[1] <= 9 &&
        v[2] >= 1 && v[2] <= 9;

    logic integer expr_a(integer v0, integer v1, integer v2) = v0 * 100 + v1 * 10 + v2;
    logic integer expr_b(integer v0, integer v1, integer v2) = v0 * 10 + v1 + v2 * 10;
    logic integer expr_c(integer v0, integer v1, integer v2) = v0 * 10 + v1 + v2;

    lemma a_range: \forall integer v0, v1, v2; v0 >= 1 && v0 <= 9 && v1 >= 1 && v1 <= 9 && v2 >= 1 && v2 <= 9 ==> expr_a(v0, v1, v2) <= 999;
    lemma b_range: \forall integer v0, v1, v2; v0 >= 1 && v0 <= 9 && v1 >= 1 && v1 <= 9 && v2 >= 1 && v2 <= 9 ==> expr_b(v0, v1, v2) <= 189;
    lemma c_range: \forall integer v0, v1, v2; v0 >= 1 && v0 <= 9 && v1 >= 1 && v1 <= 9 && v2 >= 1 && v2 <= 9 ==> expr_c(v0, v1, v2) <= 108;
*/

bool func2(int *v) {
    int a, b, c;
    bool is_divisible_by_4 = false;
    int temp_a, temp_b, temp_c;

    //@ assert v[0] >= 1 && v[0] <= 9;
    a = v[0] * 100 + v[1] * 10 + v[2];
    b = v[0] * 10 + v[1] + v[2] * 10;
    c = v[0] * 10 + v[1] + v[2];

    temp_a = a;
    while (temp_a >= 4) {
        temp_a -= 4;
    }
    if (temp_a == 0) {
        is_divisible_by_4 = true;
    }

    temp_b = b;
    while (temp_b >= 4) {
        temp_b -= 4;
    }
    if (temp_b == 0) {
        is_divisible_by_4 = true;
    }

    temp_c = c;
    while (temp_c >= 4) {
        temp_c -= 4;
    }
    if (temp_c == 0) {
        is_divisible_by_4 = true;
    }

    return is_divisible_by_4;
}

/* Function 3: Check if all points >= 50 in three arrays */
/*@
    predicate valid_points(int *points, integer len) =
        \forall integer i; 0 <= i < len ==> 0 <= points[i] && points[i] <= 100;

    predicate all_ge_50(int *points, integer len) =
        \forall integer i; 0 <= i < len ==> points[i] >= 50;

    predicate no_lt_50(int *points, integer len) =
        \forall integer i; 0 <= i < len ==> !(points[i] < 50);

    lemma two_of_three_pass:
        \forall int *p1, *p2, *p3; \forall integer len1, len2, len3;
        valid_points(p1, len1) && valid_points(p2, len2) && valid_points(p3, len3) &&
        (no_lt_50(p1, len1) || no_lt_50(p2, len2) || no_lt_50(p3, len3))
        ==>
        (all_ge_50(p1, len1) || all_ge_50(p2, len2) || all_ge_50(p3, len3));
*/

bool check_all_ge_50(int *points, size_t len) {
    size_t i;
    bool all_pass = true;
    i = 0;
    
    while (i < len) {
        if (points[i] < 50) {
            all_pass = false;
            break;
        }
        i = i + 1;
    }
    return all_pass;
}

void verify_two_of_three(int *p1, size_t len1, int *p2, size_t len2, int *p3, size_t len3) {
    bool r1 = check_all_ge_50(p1, len1);
    bool r2 = check_all_ge_50(p2, len2);
    bool r3 = check_all_ge_50(p3, len3);
    
    //@ assert r1 == true ==> all_ge_50(p1, len1);
    //@ assert r2 == true ==> all_ge_50(p2, len2);
    //@ assert r3 == true ==> all_ge_50(p3, len3);
    
    //@ assert no_lt_50(p1, len1) ==> all_ge_50(p1, len1);
    //@ assert no_lt_50(p2, len2) ==> all_ge_50(p2, len2);
    //@ assert no_lt_50(p3, len3) ==> all_ge_50(p3, len3);
    
    //@ assert all_ge_50(p1, len1) || all_ge_50(p2, len2) || all_ge_50(p3, len3);
}

/* Function 4: Compute (a-1)*(b-1) */
/*@
    predicate valid_input4(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        (a - 1) * (b - 1);

    lemma no_underflow:
        \forall integer a, b; valid_input4(a, b) ==> 1 <= a && 1 <= b;

    lemma bounds_remain:
        \forall integer a, b; valid_input4(a, b) ==> (a - 1) <= 99 && (b - 1) <= 99;

    lemma no_overflow:
        \forall integer a, b; valid_input4(a, b) ==> (a - 1) * (b - 1) <= 99 * 99;
*/

unsigned int func4(unsigned int a, unsigned int b)
{
    //@ assert 1 <= a;
    //@ assert 1 <= b;
    //@ assert (a - 1) <= 99;
    //@ assert (b - 1) <= 99;
    //@ assert (a - 1) * (b - 1) <= 99 * 99;
    
    unsigned int result = (a - 1) * (b - 1);
    return result;
}

/* ===== Synthesized Complex Function ===== */

/*
 * Scenario: Academic Grade Processing System
 * Data Flow:
 * 1. Input: student ID digits (v[0..2]), grade thresholds (a,b), and three exam score arrays
 * 2. Check if student qualifies for scholarship based on:
 *    - Grade comparison: func1(a,b) verifies threshold consistency
 *    - ID property: func2(v) checks if student ID has special divisibility property
 *    - Score verification: verify_two_of_three checks at least one exam array has all scores >= 50
 *    - Compute scholarship amount: func4(a,b) calculates base amount
 * 3. Output: total scholarship amount (0 if not qualified)
 */

/*@
    predicate valid_student_id(int *v) =
        \valid(v) && v[0] >= 1 && v[0] <= 9 && v[1] >= 1 && v[1] <= 9 && v[2] >= 1 && v[2] <= 9;

    predicate valid_thresholds(unsigned int a, unsigned int b) =
        2 <= a && a <= 100 && 2 <= b && b <= 100;

    predicate valid_score_arrays(int *p1, size_t len1, int *p2, size_t len2, int *p3, size_t len3) =
        \valid(p1 + (0 .. len1-1)) && \valid(p2 + (0 .. len2-1)) && \valid(p3 + (0 .. len3-1)) &&
        valid_points(p1, len1) && valid_points(p2, len2) && valid_points(p3, len3);
*/

unsigned int process_scholarship(int *v, unsigned int a, unsigned int b, int *p1, size_t len1, int *p2, size_t len2, int *p3, size_t len3) {
    bool grade_ok;
    bool id_special;
    unsigned int base_amount;
    
    //@ assert valid_range((long)a, (long)b);
    grade_ok = func1((long)a, (long)b);
    
    //@ assert valid_input(v);
    id_special = func2(v);
    
    verify_two_of_three(p1, len1, p2, len2, p3, len3);
    
    if (grade_ok && id_special) {
        //@ assert valid_input4(a, b);
        base_amount = func4(a, b);
    } else {
        base_amount = 0;
    }
    
    //@ assert (base_amount == 0) || (base_amount == compute_result(a, b) && grade_ok && id_special && (all_ge_50(p1, len1) || all_ge_50(p2, len2) || all_ge_50(p3, len3)));
    
    return base_amount;
}
