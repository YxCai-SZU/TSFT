/* ============================================================
   Scenario: 2D Shape Analysis for a Geometric Constraint Solver
   
   Description: In a geometric constraint solver, we often need 
   to check whether a triangle area (computed from base and height) 
   is consistent with some additional constraints. Here we combine 
   the triangle area calculation with a "minimum deviation" 
   computation to produce a "deviation score" that indicates how 
   far the triangle's dimensions deviate from a balanced shape.
   
   Data flow:
   - Input: base, height, and three parameters a, b, c (for deviation)
   - Step 1: Compute the triangle area from base and height (bounded version)
   - Step 2: Compute the minimum deviation among a, b, c
   - Step 3: Combine area and deviation to produce a final score
   
   The final assertion verifies that the output score is nonnegative,
   which is a high-level property of the combined computation.
   ============================================================ */

/* --- Original functions (unchanged) --- */

/*@
    predicate nonnegative(integer base, integer height) =
        base >= 0 && height >= 0;

    predicate within_bounds(integer base, integer height) =
        base >= 0 && height >= 0 && base <= 10000 && height <= 10000;

    logic integer triangle_area(integer base, integer height) =
        base <= 0 || height <= 0 ? 0 : (base * height) / 2;

    lemma triangle_area_bounds:
        \forall integer base, height;
            nonnegative(base, height) ==> triangle_area(base, height) >= 0;

    lemma triangle_area_growth:
        \forall integer base, height;
            within_bounds(base, height) ==> triangle_area(base, height) <= base * height;
*/

int calculate_triangle_area(int base, int height) {
    int result;
    
    //@ assert nonnegative(base, height);
    
    if (base <= 0 || height <= 0) {
        result = 0;
    } else {
        //@ assert base > 0 && height > 0;
        //@ assert base * height >= 0;
        result = (base * height) / 2;
    }
    
    //@ assert result >= 0;
    //@ assert result == triangle_area(base, height);
    return result;
}

int calculate_triangle_area_bounded(int base, int height) {
    int result;
    
    //@ assert within_bounds(base, height);
    
    if (base <= 0 || height <= 0) {
        result = 0;
    } else {
        //@ assert base > 0 && height > 0;
        //@ assert base * height <= base * height;
        result = (base * height) / 2;
    }
    
    //@ assert result <= base * height;
    //@ assert result == triangle_area(base, height);
    return result;
}

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer min_val(integer a, integer b, integer c) =
        (a < b ? (a < c ? a : c) : (b < c ? b : c));

    logic integer compute_ans(integer a, integer b, integer c, integer min) =
        a == min ? b + c - 2 * min :
        b == min ? a + c - 2 * min :
        a + b - 2 * min;

    lemma ans_nonnegative:
        \forall integer a, b, c, min;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        min == min_val(a, b, c) ==>
        compute_ans(a, b, c, min) >= 0;
*/

long func(long a, long b, long c) {
    long min_val;
    long ans;

    min_val = a < b ? a : b;
    min_val = min_val < c ? min_val : c;

    ans = 0;
    if (a == min_val) {
        ans = b + c - 2 * min_val;
    } else if (b == min_val) {
        ans = a + c - 2 * min_val;
    } else {
        ans = a + b - 2 * min_val;
    }

    //@ assert ans >= 0;
    return ans;
}

/* --- Synthesized function --- */

long compute_deviation_score(int base, int height, long a, long b, long c) {
    int area;
    long deviation;
    long score;

    area = calculate_triangle_area_bounded(base, height);
    //@ assert area >= 0;
    //@ assert area == triangle_area(base, height);

    deviation = func(a, b, c);
    //@ assert deviation >= 0;

    score = (long)area + deviation;

    //@ assert score >= 0;  // Core high-level property: output is nonnegative
    return score;
}
