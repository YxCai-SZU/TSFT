#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/* ============================================================
   Function 1: Check if any two sides sum to the third
   (triangle property for valid ranges 1-100)
   ============================================================ */
/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;
*/

bool func_triangle_check(unsigned int a, unsigned int b, unsigned int c) {
    if (a + b == c || a + c == b || b + c == a) {
        return true;
    } else {
        return false;
    }
}

/* ============================================================
   Function 2: Compute trapezoid area with manual division
   (valid params: a,b in [1,100], h even in [1,100])
   ============================================================ */
/*@
    predicate valid_params(integer a, integer b, integer h) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= h && h <= 100 &&
        h % 2 == 0;

    logic integer trapezoid_area(integer a, integer b, integer h) =
        (a + b) * h / 2;

    lemma product_bounds:
        \forall integer a, b, h;
        valid_params(a, b, h) ==>
        1 <= (a + b) * h && (a + b) * h <= 200 * 100;
*/

int func_trapezoid_area(int a, int b, int h)
{
    int sum;
    int product;
    int ans;
    int count;
    int temp;

    sum = a + b;
    //@ assert sum == a + b;

    //@ assert 1 <= sum && sum <= 200;
    product = sum * h;
    //@ assert product == sum * h;

    ans = 0;
    count = 0;
    temp = product;

    while (temp >= 2)
    {
        temp -= 2;
        count += 1;
    }
    ans = count;

    //@ assert ans == trapezoid_area(a, b, h);
    return ans;
}

/* ============================================================
   Function 3: Check triangle property on binary inputs (0/1)
   ============================================================ */
/*@ predicate is_valid_input(int *input, integer len) =
    len == 3 &&
    \forall integer i; 0 <= i < len ==> (input[i] == 0 || input[i] == 1);
*/

bool func_binary_triangle(int *input)
{
    int a;
    int b;
    int c;
    int sum1;
    int sum2;
    int sum3;
    int result1;
    int result2;
    int result3;
    int result;
    bool ret_val;

    a = input[0];
    b = input[1];
    c = input[2];

    //@ assert a == 0 || a == 1;
    //@ assert b == 0 || b == 1;
    //@ assert c == 0 || c == 1;

    sum1 = a + b;
    sum2 = b + c;
    sum3 = c + a;

    result1 = (sum1 == c) ? 1 : 0;
    result2 = (sum2 == a) ? 1 : 0;
    result3 = (sum3 == b) ? 1 : 0;

    result = result1 + result2 + result3;

    ret_val = (result > 0);
    return ret_val;
}

/* ============================================================
   Function 4: Compute expression a + a^2 + a^3 for a in [1,10]
   ============================================================ */
/*@
    predicate is_valid_range_10(integer a) = 1 <= a <= 10;
    
    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer expression(integer a) = a + square(a) + cube(a);
    
    lemma square_bound: \forall integer a; is_valid_range_10(a) ==> square(a) <= 100;
    lemma cube_bound: \forall integer a; is_valid_range_10(a) ==> cube(a) <= 1000;
    lemma expression_bound: \forall integer a; is_valid_range_10(a) ==> expression(a) <= 1110;
*/

int32_t func_expression(uint32_t a)
{
    uint32_t a_usize;
    uint32_t result;
    
    a_usize = a;
    
    //@ assert is_valid_range_10(a);
    //@ assert square(a) <= 100;
    //@ assert cube(a) <= 1000;
    //@ assert expression(a) <= 1110;
    
    result = a_usize + a_usize * a_usize + a_usize * a_usize * a_usize;
    
    //@ assert result == expression(a);
    return (int32_t)result;
}

/* ============================================================
   Synthesized function: 
   "Shape property validator for a compound geometric object"
   
   Real-world scenario:
   We have a geometric object defined by 6 parameters:
     - side1, side2: two sides of a trapezoid (1-100)
     - height: height of trapezoid (even, 1-100)
     - a, b, c: three binary flags indicating additional shape features
     - expr_val: a scaling factor (1-10)
   
   The function validates that:
     1. The trapezoid area computed from side1, side2, height is consistent
        with the triangle property of the three sides (a,b,c transformed).
     2. The expression value (expr_val + expr_val^2 + expr_val^3) 
        is used to scale the result.
   
   Control flow:
     - Compute trapezoid area (func_trapezoid_area)
     - Check triangle property on scaled parameters (func_triangle_check)
     - Check binary triangle property (func_binary_triangle)
     - Compute expression value (func_expression)
     - Combine results with a consistency check
   ============================================================ */

int shape_property_validator(
    int side1, int side2, int height,
    int *input,
    uint32_t expr_val)
{
    int area;
    bool triangle_ok;
    bool binary_triangle_ok;
    int32_t expr_result;
    int result;
    
    area = func_trapezoid_area(side1, side2, height);
    //@ assert area == trapezoid_area(side1, side2, height);
    
    triangle_ok = func_triangle_check((unsigned int)side1, 
                                       (unsigned int)side2, 
                                       (unsigned int)height);
    //@ assert triangle_ok == (side1 + side2 == height || side1 + height == side2 || side2 + height == side1);
    
    binary_triangle_ok = func_binary_triangle(input);
    //@ assert binary_triangle_ok == (input[0] + input[1] == input[2] || input[1] + input[2] == input[0] || input[2] + input[0] == input[1]);
    
    expr_result = func_expression(expr_val);
    //@ assert expr_result == expression(expr_val);
    
    if (area >= 1 && triangle_ok == true && binary_triangle_ok == true && expr_result >= 1) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert (result == 1) <==> (area >= 1 && triangle_ok == true && binary_triangle_ok == true && expr_result >= 1);
    
    return result;
}

int main() {
    return 0;
}
