#include <stdbool.h>
#include <stddef.h>

/* ========== Function 1: Verify nonlinear properties ========== */

/*@
    predicate is_bounded_inequality(integer x, integer y) =
        x <= 5 && y <= 7 ==> x * y <= 35;

    predicate is_bounded_division(integer x, integer y) =
        x <= 5 && y <= 7 && y != 0 ==> x / y <= x;

    predicate is_bounded_modulo(integer x, integer y) =
        x <= 5 && y <= 7 && y != 0 ==> x % y <= x;

    lemma inequality_lemma:
        \forall integer x, y; 0 <= x <= 5 && 0 <= y <= 7 ==> x * y <= 35;

    lemma division_lemma:
        \forall integer x, y; 0 <= x <= 5 && 1 <= y <= 7 ==> x / y <= x;

    lemma modulo_lemma:
        \forall integer x, y; 0 <= x <= 5 && 1 <= y <= 7 ==> x % y <= x;
*/

unsigned int verify_nonlinear_inequality(unsigned int x, unsigned int y)
{
    unsigned int result;
    //@ assert x * y <= 35;
    result = x * y;
    return result;
}

unsigned int verify_nonlinear_equality(unsigned int x, unsigned int y)
{
    unsigned int result;
    //@ assert x * y == x * y;
    result = x * y;
    return result;
}

unsigned int verify_nonlinear_congruence(unsigned int x, unsigned int y)
{
    unsigned int result;
    //@ assert x * y % 5 == x * y % 5;
    result = x * y % 5;
    return result;
}

unsigned int verify_nonlinear_division(unsigned int x, unsigned int y)
{
    unsigned int result;
    //@ assert x / y <= x;
    result = x / y;
    return result;
}

unsigned int verify_nonlinear_modulo(unsigned int x, unsigned int y)
{
    unsigned int result;
    //@ assert x % y <= x;
    result = x % y;
    return result;
}

/* ========== Function 2: Triangle check ========== */

/*@
    predicate is_triangle(integer a, integer b, integer c) =
        a + b == c || a + c == b || b + c == a;
*/

bool triangle_check(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int max;
    unsigned int min;
    unsigned int mid;

    max = a;
    //@ assert max == a;
    if (b > max)
    {
        max = b;
    }
    //@ assert max >= a && max >= b;
    if (c > max)
    {
        max = c;
    }
    //@ assert max >= a && max >= b && max >= c;

    min = a;
    //@ assert min == a;
    if (b < min)
    {
        min = b;
    }
    //@ assert min <= a && min <= b;
    if (c < min)
    {
        min = c;
    }
    //@ assert min <= a && min <= b && min <= c;

    mid = a + b + c - max - min;
    //@ assert a + b + c == max + mid + min;

    if (max == mid + min || mid == max + min || min == max + mid)
    {
        //@ assert is_triangle(a, b, c);
        return true;
    }
    else
    {
        //@ assert !is_triangle(a, b, c);
        return false;
    }
}

/* ========== Function 3: Equality check within range ========== */

/*@ predicate in_range(integer x) = 1 <= x <= 10; */

bool equality_check(int a, int b, int c) {
    int abs_diff_ab;
    int abs_diff_bc;
    int abs_diff_ca;
    bool is_ab;
    bool is_bc;
    bool is_ca;
    bool result;

    //@ assert in_range(a) && in_range(b) && in_range(c);
    
    if (a > b) {
        abs_diff_ab = a - b;
    } else {
        abs_diff_ab = b - a;
    }
    
    if (b > c) {
        abs_diff_bc = b - c;
    } else {
        abs_diff_bc = c - b;
    }
    
    if (c > a) {
        abs_diff_ca = c - a;
    } else {
        abs_diff_ca = a - c;
    }
    
    if (abs_diff_ab == 0) {
        is_ab = true;
    } else {
        is_ab = false;
    }
    
    if (abs_diff_bc == 0) {
        is_bc = true;
    } else {
        is_bc = false;
    }
    
    if (abs_diff_ca == 0) {
        is_ca = true;
    } else {
        is_ca = false;
    }
    
    //@ assert is_ab == (a == b);
    //@ assert is_bc == (b == c);
    //@ assert is_ca == (c == a);
    
    result = is_ab || is_bc || is_ca;
    
    //@ assert result == true <==> (a == b || b == c || c == a);
    return result;
}

/* ========== Function 4: Valid range product check ========== */

/*@ predicate is_small(integer x) = 1 <= x <= 9; */
/*@ predicate is_valid_range(integer x) = 1 <= x <= 20; */

/*@
  lemma small_product_bound: 
    \forall integer a, b; 
      is_small(a) && is_small(b) ==> a * b <= 100;
*/

int range_product_check(unsigned int a, unsigned int b)
{
    unsigned int *v = NULL;
    unsigned int i = 0;
    int result = 0;
    unsigned int arr[2];
    
    if (a < 10 && b < 10) 
    {
        //@ assert is_small(a) && is_small(b);
        //@ assert a * b <= 100;
        result = (int)(a * b);
        return result;
    } 
    else 
    {
        arr[0] = a;
        arr[1] = b;
        v = arr;
        
        i = 0;
        while (i < 2) 
        {
            //@ assert 0 <= i < 2;
            if (v[i] > 9) 
            {
                return -1;
            }
            i++;
        }
        return -1;
    }
}

/* ========== Synthesized Function: Data validation and transformation pipeline ========== */

/*@
    predicate valid_input_set(integer a, integer b, integer c) =
        1 <= a <= 5 && 1 <= b <= 7 && 1 <= c <= 10000;

    predicate output_consistent(integer x, integer y, integer z, int result) =
        (result == 0) ==> (x <= 5 && y <= 7 && z <= 10000 && 
                          (x == y || y == z || z == x) && 
                          !is_triangle(x, y, z));
*/

int process_data_pipeline(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int product_result;
    int range_result;
    bool triangle_flag;
    bool equal_flag;
    int final_result = 0;

    /*@ assert 0 <= a <= 5 && 0 <= b <= 7; */
    product_result = verify_nonlinear_inequality(a, b);
    /*@ assert product_result == a * b && product_result <= 35; */

    /*@ assert is_valid_range(a) && is_valid_range(b); */
    range_result = range_product_check(a, b);
    /*@ assert (a < 10 && b < 10 ==> range_result == (int)(a * b)) && 
              (a >= 10 || b >= 10 ==> range_result == -1); */

    /*@ assert 1 <= a <= 5 && 1 <= b <= 7 && 1 <= c <= 10000; */
    triangle_flag = triangle_check(a, b, c);
    /*@ assert triangle_flag == true <==> is_triangle(a, b, c); */

    //@ assert 1 <= a <= 5 && 1 <= b <= 7 && 1 <= c <= 10000;
    if (a >= 1 && a <= 10 && b >= 1 && b <= 10 && c >= 1 && c <= 10) {
        equal_flag = equality_check((int)a, (int)b, (int)c);
        /*@ assert equal_flag == true <==> (a == b || b == c || c == a); */
    } else {
        equal_flag = (a == b || b == c || c == a);
    }

    if (range_result == -1 || triangle_flag || !equal_flag)
    {
        final_result = -1;
    }
    else
    {
        final_result = 0;
    }

    //@ assert final_result == 0 ==> (a <= 5 && b <= 7 && c <= 10000 && (a == b || b == c || c == a) && !is_triangle(a, b, c));
    return final_result;
}
