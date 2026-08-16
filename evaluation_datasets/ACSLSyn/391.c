#include <stdbool.h>
#include <stdint.h>

/* ====== Function 1: Check if product of two numbers is even ====== */
/*@ predicate is_even(integer val) = val % 2 == 0; */

bool func1(unsigned int n, unsigned int m)
{
    return (n * m) % 2 == 0;
}

int func2(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int result;
    
    min_ab = a < b ? a : b;
    min_cd = c < d ? c : d;
    result = min_ab + min_cd;
    
    return result;
}

int func3(unsigned int x, unsigned int a)
{
    if (x >= a) {
        return 0;
    } else {
        return 10;
    }
}

/* ====== Function 4: Triangle type classification ====== */
/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer abs_diff(integer x, integer y) =
        x > y ? x - y : y - x;

    logic integer ab(integer a, integer b) = abs_diff(a, b);
    logic integer bc(integer b, integer c) = abs_diff(b, c);
    logic integer ca(integer c, integer a) = abs_diff(c, a);

    lemma result_range:
        \forall integer a, b, c, res;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        (res == 1 || res == 2 || res == 3) ==>
        res >= 1 && res <= 3;
*/

uint32_t func4(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ab;
    uint32_t bc;
    uint32_t ca;
    uint32_t res;

    if (a > b) {
        ab = a - b;
    } else {
        ab = b - a;
    }

    if (b > c) {
        bc = b - c;
    } else {
        bc = c - b;
    }

    if (c > a) {
        ca = c - a;
    } else {
        ca = a - c;
    }

    if ((ab + bc == ca) || (bc + ca == ab) || (ca + ab == bc)) {
        res = 1;
    } else {
        if ((ab == 0) || (bc == 0) || (ca == 0)) {
            res = 2;
        } else {
            res = 3;
        }
    }

    return res;
}

/* ====== Function 5: Circle circumference calculation ====== */
/*@
    predicate valid_radius(integer r) = 1 <= r <= 100;
*/

/*@
    logic integer circumference(integer r) = 2 * r * 3;
*/

/*@
    lemma no_overflow:
        \forall integer r; valid_radius(r) ==> 2 * r * 3 <= 600;
*/

int func5(int r)
{
    int pi = 3;
    int circumference_val;
    
    circumference_val = 2 * r * pi;
    
    return circumference_val;
}

/* ====== Function 6: Condition check on array ====== */
/*@
    predicate valid_input(int *input) =
        \valid(input) && \valid(input+1) && \valid(input+2) &&
        1 <= input[0] && input[0] <= 100 &&
        1 <= input[1] && input[1] <= 100 &&
        1 <= input[2] && input[2] <= 100;

    predicate condition(integer a, integer b, integer c) =
        (a <= c && b <= c) || (c <= a && b <= a);
*/

bool func6(int *input)
{
    int a;
    int b;
    int c;

    a = input[0];
    b = input[1];
    c = input[2];

    if ((a <= c && b <= c) || (c <= a && b <= a)) {
        return true;
    } else {
        return false;
    }
}

/* ====== Synthesized Function: Process triangle data and validate geometric properties ====== */
int synthesized_function(uint32_t a, uint32_t b, uint32_t c, unsigned int x, unsigned int y, int *input)
{
    int result = 0;
    
    uint32_t triangle_type = func4(a, b, c);
    
    int circumference_val = func5((int)triangle_type);
    
    bool condition_met = func6(input);
    
    bool is_even_product = func1(a, b);
    int min_sum = func2((int)a, (int)b, (int)c, circumference_val);
    
    int decision = func3(condition_met ? 1 : 0, is_even_product ? 1 : 0);
    
    if (triangle_type <= 2 && decision == 0) {
        result = 1;
    }
    
    return result;
}
