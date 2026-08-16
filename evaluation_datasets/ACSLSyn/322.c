#include <stdbool.h>
#include <limits.h>

/* 
 * Real-world scenario: Student grade processing system
 * 
 * Data flow:
 * 1. func1 (func_grade_check): Checks if a student's scores in two subjects meet minimum thresholds and combined score threshold
 * 2. func2 (func_trapezoid_area): Calculates area of a trapezoid representing a performance metric
 * 3. func3 (func_max_sum): Finds maximum sum of pairs from three performance indicators
 * 
 * The synthesized function processes student performance data to determine if they qualify for a special program.
 * It takes raw scores, validates them, computes derived metrics, and makes a final qualification decision.
 */

/*@
    predicate a_ge_threshold(integer a, integer threshold) = a >= threshold;
    predicate b_ge_threshold(integer b, integer threshold) = b >= threshold;
    predicate sum_ge_threshold(integer a, integer b, integer threshold) = a + b >= threshold;
*/

bool func_grade_check(unsigned int a, unsigned int b)
{
    unsigned int threshold_a;
    unsigned int threshold_b;
    unsigned int threshold_sum;
    bool a_fine;
    bool b_fine;
    bool sum_fine;
    bool result;

    threshold_a = 30;
    threshold_b = 30;
    threshold_sum = 200;

    a_fine = a >= threshold_a;
    b_fine = b >= threshold_b;
    sum_fine = a + b >= threshold_sum;

    //@ assert a_fine <==> a >= threshold_a;
    //@ assert b_fine <==> b >= threshold_b;
    //@ assert sum_fine <==> a + b >= threshold_sum;

    result = a_fine && b_fine && sum_fine;
    return result;
}

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate h_in_range(integer h) = 1 <= h && h <= 100;
    predicate h_even(integer h) = h % 2 == 0;
    
    logic integer trapezoid_area(integer a, integer b, integer h) = (a + b) * h / 2;
    
    lemma sum_bounds:
        \forall integer a, b;
        a_in_range(a) && b_in_range(b) ==> 2 <= a + b && a + b <= 200;
    
    lemma product_bounds:
        \forall integer a, b, h;
        a_in_range(a) && b_in_range(b) && h_in_range(h) ==> 
        2 <= (a + b) * h && (a + b) * h <= 20000;
*/

unsigned long long func_trapezoid_area(unsigned long long a, unsigned long long b, unsigned long long h)
{
    unsigned long long result;
    
    //@ assert 2 <= a + b && a + b <= 200;
    //@ assert 2 <= (a + b) * h && (a + b) * h <= 20000;
    
    result = (a + b) * h / 2;
    
    //@ assert result == (a + b) * h / 2;
    return result;
}

/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    logic integer sum_ab(integer a, integer b) = a + b;
    logic integer sum_bc(integer b, integer c) = b + c;
    logic integer sum_ca(integer c, integer a) = c + a;

    lemma result_property:
        \forall integer a, b, c, result;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        (result == sum_ab(a,b) || result == sum_bc(b,c) || result == sum_ca(c,a)) ==>
        result >= 0;
*/

int func_max_sum(int a, int b, int c)
{
    int max_val;
    int result;
    int a_val;
    int b_val;
    int c_val;

    max_val = a + b;
    //@ assert max_val == sum_ab(a,b);
    if (b + c > max_val)
    {
        max_val = b + c;
        //@ assert max_val == sum_bc(b,c);
    }
    //@ assert max_val >= sum_ab(a,b) && max_val >= sum_bc(b,c);
    if (c + a > max_val)
    {
        max_val = c + a;
        //@ assert max_val == sum_ca(c,a);
    }
    //@ assert max_val >= sum_ab(a,b) && max_val >= sum_bc(b,c) && max_val >= sum_ca(c,a);

    result = max_val;
    if (a + b == max_val)
    {
        result = a + b;
        //@ assert result == sum_ab(a,b);
    }
    else if (b + c == max_val)
    {
        result = b + c;
        //@ assert result == sum_bc(b,c);
    }
    else
    {
        result = c + a;
        //@ assert result == sum_ca(c,a);
    }
    //@ assert result == sum_ab(a,b) || result == sum_bc(b,c) || result == sum_ca(c,a);

    a_val = (a < 0) ? -a : a;
    b_val = (b < 0) ? -b : b;
    c_val = (c < 0) ? -c : c;
    //@ assert a_val == a && b_val == b && c_val == c;

    if (a_val + b_val > result)
    {
        result = a_val + b_val;
        //@ assert result == sum_ab(a,b);
    }
    //@ assert result >= sum_ab(a,b);
    if (b_val + c_val > result)
    {
        result = b_val + c_val;
        //@ assert result == sum_bc(b,c);
    }
    //@ assert result >= sum_bc(b,c);
    if (c_val + a_val > result)
    {
        result = c_val + a_val;
        //@ assert result == sum_ca(c,a);
    }
    //@ assert result >= sum_ca(c,a);

    //@ assert result == sum_ab(a,b) || result == sum_bc(b,c) || result == sum_ca(c,a);
    return result;
}

int process_student_qualification(
    unsigned int score1, unsigned int score2,
    unsigned long long metric_a, unsigned long long metric_b, unsigned long long metric_h,
    int indicator1, int indicator2, int indicator3)
{
    bool grade_ok;
    unsigned long long area;
    int max_sum;
    int qualification;
    
    grade_ok = func_grade_check(score1, score2);
    
    area = func_trapezoid_area(metric_a, metric_b, metric_h);
    
    max_sum = func_max_sum(indicator1, indicator2, indicator3);
    
    if (grade_ok && area >= 500 && max_sum >= 15)
    {
        qualification = 1;
    }
    else
    {
        qualification = 0;
    }
    
    //@ assert (qualification == 1) <==> (grade_ok && area >= 500 && max_sum >= 15);
    
    return qualification;
}

int main()
{
    unsigned int score1, score2;
    unsigned long long metric_a, metric_b, metric_h;
    int indicator1, indicator2, indicator3;
    int result;
    
    score1 = 80;
    score2 = 75;
    metric_a = 20;
    metric_b = 30;
    metric_h = 10;
    indicator1 = 5;
    indicator2 = 7;
    indicator3 = 8;
    
    result = process_student_qualification(score1, score2, metric_a, metric_b, metric_h, indicator1, indicator2, indicator3);
    
    return 0;
}
