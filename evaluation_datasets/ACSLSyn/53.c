#include <stdbool.h>
#include <stdint.h>

/* ACSL specifications for the first group of functions */
/*@
    logic integer abs_val(integer x) = (x < 0) ? -x : x;
    logic integer distance(integer x1, integer y1, integer x2, integer y2) =
        abs_val(x2 - x1) + abs_val(y2 - y1);
*/

int func_square(int r)
{
    int result;
    result = r;
    //@ assert 1 <= r && r <= 100;
    if (r != 0)
    {
        //@ assert r * r <= 10000;
        result = r * r;
    }
    return result;
}

int func_distance(int x1, int y1, int x2, int y2)
{
    int dx;
    int dy;
    int dist;
    dx = (x2 - x1 < 0) ? -(x2 - x1) : (x2 - x1);
    dy = (y2 - y1 < 0) ? -(y2 - y1) : (y2 - y1);
    dist = dx + dy;
    //@ assert dist == distance(x1, y1, x2, y2);
    return dist;
}

/* ACSL specifications for the second function */
/*@
    predicate is_valid_range(integer a) = 1 <= a <= 100;

    logic integer expr1(integer a, integer b, integer c) = (a + b) * c;
    logic integer expr2(integer a, integer b, integer c) = a * b + c;
    logic integer expr3(integer a, integer b, integer c) = a + b + c;

    lemma expr1_bounds: \forall integer a, b, c;
        is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==>
        1 <= expr1(a, b, c) <= 200 * 100;
    lemma expr2_bounds: \forall integer a, b, c;
        is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==>
        1 <= expr2(a, b, c) <= 100 * 100 + 100;
    lemma expr3_bounds: \forall integer a, b, c;
        is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==>
        1 <= expr3(a, b, c) <= 100 + 100 + 100;
*/

int func_min_expr(int a, int b, int c) {
    int answers[3];
    int answers_len = 3;
    int min_val;
    int i;

    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    
    answers[0] = (a + b) * c;
    //@ assert answers[0] == expr1(a, b, c);
    
    answers[1] = a * b + c;
    //@ assert answers[1] == expr2(a, b, c);
    
    answers[2] = a + b + c;
    //@ assert answers[2] == expr3(a, b, c);
    
    min_val = answers[0];
    i = 1;
    
    while (i < answers_len) {
        if (answers[i] < min_val) {
            min_val = answers[i];
        }
        i = i + 1;
    }
    
    //@ assert min_val == expr1(a, b, c) || min_val == expr2(a, b, c) || min_val == expr3(a, b, c);
    return min_val;
}

/* ACSL specifications for the third function */
/*@
    predicate valid_input(long *input) =
        \valid(input) &&
        \valid(input + 1) &&
        \valid(input + 2) &&
        1 <= input[0] <= 100 &&
        1 <= input[1] <= 100 &&
        1 <= input[2] <= 100;

    logic integer sum_two(integer a, integer b) = a + b;

    predicate is_possible_result(integer result, integer a, integer b, integer c) =
        result == sum_two(a, b) ||
        result == sum_two(b, c) ||
        result == sum_two(a, c);
*/

long func_min_sum(long *input) {
    long x;
    long y;
    long z;
    long temp;
    long result;

    x = input[0];
    y = input[1];
    z = input[2];

    //@ assert 1 <= x <= 100 && 1 <= y <= 100 && 1 <= z <= 100;

    if (x > y) {
        temp = x;
        x = y;
        y = temp;
    }
    //@ assert x <= y;

    if (y > z) {
        temp = y;
        y = z;
        z = temp;
    }
    //@ assert y <= z;

    if (x > y) {
        temp = x;
        x = y;
        y = temp;
    }
    //@ assert x <= y && y <= z;

    result = x + y;
    //@ assert result >= 0;
    //@ assert is_possible_result(result, \at(input[0], Pre), \at(input[1], Pre), \at(input[2], Pre));

    return result;
}

/* ACSL specifications for the fourth function */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;
    
    logic integer n_mod_100(integer n) = n % 100;
    
    lemma mod_bound: \forall integer n; is_valid_n(n) ==> 0 <= n_mod_100(n) && n_mod_100(n) <= 99;
    
    lemma mul_bound: \forall integer n; is_valid_n(n) ==> n_mod_100(n) * 21 <= 2079;
*/

uint32_t func_check_condition(uint32_t n)
{
    uint32_t n_mod_100;
    uint32_t ans;
    
    n_mod_100 = n % 100;
    ans = 1;
    
    //@ assert n_mod_100 == n % 100;
    //@ assert n_mod_100 * 21 <= 2079;
    
    if (n_mod_100 * 21 >= n)
    {
        ans = 0;
    }
    
    //@ assert ans == 0 || ans == 1;
    //@ assert ans == 1 ==> n_mod_100 * 21 < n;
    //@ assert ans == 0 ==> n_mod_100 * 21 >= n;
    
    return ans;
}

/* 
 * Real-world scenario: Urban Traffic Grid Analysis System
 * 
 * This function analyzes a small traffic grid (2x2 intersections) to determine
 * if the traffic flow pattern is "balanced". 
 */

int analyze_traffic_grid(int r, int x1, int y1, int x2, int y2, 
                         int a, int b, int c, long *input, uint32_t n)
{
    int square_result;
    int distance_result;
    int min_expr_result;
    long min_sum_result;
    uint32_t condition_result;
    int grid_balanced;
    
    square_result = func_square(r);
    
    distance_result = func_distance(x1, y1, x2, y2);
    
    min_expr_result = func_min_expr(a, b, c);
    
    min_sum_result = func_min_sum(input);
    
    condition_result = func_check_condition(n);
    
    if (square_result >= distance_result && 
        min_expr_result <= (int)min_sum_result && 
        condition_result == 1)
    {
        grid_balanced = 1;
    }
    else
    {
        grid_balanced = 0;
    }
    
    return grid_balanced;
}
