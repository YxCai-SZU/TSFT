#include <stdbool.h>

/* ACSL predicates from first function */
/*@
    predicate valid_range_val(integer x) = 1 <= x <= 100;
    predicate valid_range_tri(integer val) = 1 <= val <= 13;

    logic integer abs_diff(integer x, integer y) = 
        x > y ? x - y : y - x;

    logic integer min_sum(integer ab, integer bc, integer ca) =
        (ab + bc) < (bc + ca) ? 
            ((ab + bc) < (ab + ca) ? (ab + bc) : (ab + ca)) :
            ((bc + ca) < (ab + ca) ? (bc + ca) : (ab + ca));

    lemma min_sum_nonnegative:
        \forall integer ab, bc, ca;
            ab >= 0 && bc >= 0 && ca >= 0 ==> min_sum(ab, bc, ca) >= 0;

    lemma min_sum_bound:
        \forall integer ab, bc, ca;
            ab <= 100 && bc <= 100 && ca <= 100 ==> min_sum(ab, bc, ca) <= 200;
*/

/* First function: compute minimum pairwise absolute difference sum */
int func1(int a, int b, int c)
{
    int ab;
    int bc;
    int ca;
    int min_ab_bc;
    int min_bc_ca;
    int min_ab_ca;
    int min1;
    int min2;

    //@ assert valid_range_val(a) && valid_range_val(b) && valid_range_val(c);
    
    ab = a > b ? a - b : b - a;
    //@ assert ab == abs_diff(a, b);
    //@ assert ab >= 0 && ab <= 99;
    
    bc = b > c ? b - c : c - b;
    //@ assert bc == abs_diff(b, c);
    //@ assert bc >= 0 && bc <= 99;
    
    ca = c > a ? c - a : a - c;
    //@ assert ca == abs_diff(c, a);
    //@ assert ca >= 0 && ca <= 99;
    
    min_ab_bc = ab + bc;
    //@ assert min_ab_bc >= 0 && min_ab_bc <= 198;
    
    min_bc_ca = bc + ca;
    //@ assert min_bc_ca >= 0 && min_bc_ca <= 198;
    
    min_ab_ca = ab + ca;
    //@ assert min_ab_ca >= 0 && min_ab_ca <= 198;
    
    min1 = min_ab_bc < min_bc_ca ? min_ab_bc : min_bc_ca;
    //@ assert min1 >= 0 && min1 <= 198;
    
    min2 = min1 < min_ab_ca ? min1 : min_ab_ca;
    //@ assert min2 == min_sum(ab, bc, ca);
    //@ assert min2 >= 0;
    //@ assert min2 <= 200;
    
    return min2;
}

/* Second function: triangle inequality check */
bool func2(int numbers[3]) {
    int a;
    int b;
    int c;
    
    a = numbers[0];
    b = numbers[1];
    c = numbers[2];
    
    //@ assert valid_range_tri(a);
    //@ assert valid_range_tri(b);
    //@ assert valid_range_tri(c);
    
    return (b + c > a && a + b > c && b + c > a);
}

/* Synthesized function: Triangle stability analysis
 * 
 * Real-world scenario: In a structural engineering context, we analyze triangular
 * truss elements. Given three side lengths (1-13), we first verify they form
 * a valid triangle (triangle inequality), then compute the minimum pairwise
 * absolute difference sum as a measure of how "balanced" the triangle is.
 * A balanced triangle (small min difference sum) indicates uniform load distribution.
 */
int triangle_stability_analysis(int arr[3]) {
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    
    //@ assert valid_range_val(a) && valid_range_val(b) && valid_range_val(c);
    
    bool is_valid_triangle = func2(arr);
    
    //@ assert is_valid_triangle == (b + c > a && a + b > c && b + c > a);
    
    int result;
    
    if (is_valid_triangle) {
        result = func1(a, b, c);
        //@ assert result >= 0 && result <= 200;
    } else {
        result = 200;
    }
    
    //@ assert result >= 0 && result <= 200;
    
    return result;
}
