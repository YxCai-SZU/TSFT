#include <stdint.h>

/* ============================================================
   Scenario: Image Sub-rectangle Parity Analysis
   Description: In image processing, we often need to analyze 
   sub-rectangles of a grid. This function computes the parity 
   of the area difference between the full rectangle and a 
   sub-rectangle, which is useful for checkboard pattern detection.
   ============================================================ */

/* --- Underlying function 1: Check if product of two numbers is odd --- */

/*@
    predicate is_valid_range(integer a) =
        1 <= a && a <= 3;

    logic integer multiply_mod2(integer a, integer b) =
        (a * b) % 2;

    lemma multiplication_range: \forall integer a, b;
        is_valid_range(a) && is_valid_range(b) ==> 1 <= a * b && a * b <= 9;
*/

void check_odd_product(unsigned long a, unsigned long b, int *result) {
    unsigned long temp_result;
    int is_odd;

    temp_result = a * b;
    is_odd = 0;

    //@ assert 1 <= temp_result && temp_result <= 9;

    while (temp_result >= 2) {
        temp_result -= 2;
    }

    //@ assert temp_result == 0 || temp_result == 1;
    //@ assert temp_result % 2 == (a * b) % 2;

    if (temp_result == 1) {
        is_odd = 1;
    }

    *result = is_odd;
}

/* --- Underlying function 2: Compute area difference of rectangles --- */

/*@
    predicate bounds(integer H, integer W, integer h, integer w) =
        1 <= H <= 20 && 1 <= W <= 20 && 1 <= h <= H && 1 <= w <= W;

    logic integer formula(integer H, integer W, integer h, integer w) =
        H * W + h * w - h * W - w * H;

    lemma product_bounds_400:
        \forall integer H, W, h, w;
            bounds(H, W, h, w) ==>
            H * W <= 400 && h * w <= 400 && h * W <= 400 && w * H <= 400;

    lemma product_bounds_uint32:
        \forall integer H, W, h, w;
            bounds(H, W, h, w) ==>
            H * W <= 0xFFFFFFFF && h * w <= 0xFFFFFFFF &&
            h * W <= 0xFFFFFFFF && w * H <= 0xFFFFFFFF;

    lemma formula_nonnegative:
        \forall integer H, W, h, w;
            bounds(H, W, h, w) ==> formula(H, W, h, w) >= 0;
*/

int compute_area_diff(unsigned int H, unsigned int W, unsigned int h, unsigned int w) {
    unsigned int H_local;
    unsigned int W_local;
    unsigned int h_local;
    unsigned int w_local;
    unsigned long long product_HW;
    unsigned long long product_hw;
    unsigned long long product_hW;
    unsigned long long product_wH;
    unsigned long long sum;
    unsigned long long diff;
    int result;

    H_local = H;
    W_local = W;
    h_local = h;
    w_local = w;

    //@ assert bounds(H_local, W_local, h_local, w_local);
    //@ assert H_local * W_local <= 400;
    //@ assert h_local * w_local <= 400;
    //@ assert h_local * W_local <= 400;
    //@ assert w_local * H_local <= 400;
    //@ assert H_local * W_local <= 0xFFFFFFFF;
    //@ assert h_local * w_local <= 0xFFFFFFFF;
    //@ assert h_local * W_local <= 0xFFFFFFFF;
    //@ assert w_local * H_local <= 0xFFFFFFFF;
    //@ assert formula(H_local, W_local, h_local, w_local) >= 0;

    product_HW = (unsigned long long)H_local * (unsigned long long)W_local;
    product_hw = (unsigned long long)h_local * (unsigned long long)w_local;
    product_hW = (unsigned long long)h_local * (unsigned long long)W_local;
    product_wH = (unsigned long long)w_local * (unsigned long long)H_local;

    sum = product_HW + product_hw;
    diff = sum - product_hW;
    diff = diff - product_wH;

    result = (int)diff;
    //@ assert result == (int)formula(H_local, W_local, h_local, w_local);
    return result;
}

/* --- Synthesized function: Image sub-rectangle parity analysis --- */

void subrect_parity_analysis(
    unsigned int H, unsigned int W, 
    unsigned int h, unsigned int w,
    int *result_parity)
{
    int area_diff;
    unsigned long a, b;
    int parity;

    area_diff = compute_area_diff(H, W, h, w);
    
    parity = (area_diff % 2 != 0) ? 1 : 0;
    
    *result_parity = parity;
    
    //@ assert *result_parity == ((H * W + h * w - h * W - w * H) % 2 != 0);
}
