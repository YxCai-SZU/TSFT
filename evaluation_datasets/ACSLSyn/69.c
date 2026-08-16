#include <stdbool.h>

/* ACSL predicates and lemmas from original functions */

/* Function 1: Check if three values (1-10) are a specific permutation (5,5,7) */
/*@
    predicate is_valid_range(integer v) = 1 <= v <= 10;

    predicate condition_holds(integer a, integer b, integer c) =
        (a == 5 && b == 5 && c == 7) ||
        (a == 5 && b == 7 && c == 5) ||
        (a == 7 && b == 5 && c == 5);

    lemma max_permutation:
        \forall integer a, b, c;
            is_valid_range(a) && is_valid_range(b) && is_valid_range(c) ==>
            ((\max(\max(a, b), c) == 7) &&
             (\max(\min(a, b), \min(\max(a, b), c)) == 5) &&
             (\min(\min(a, b), c) == 5)) ==>
            condition_holds(a, b, c);
*/

bool func_permutation(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int x = a;
    unsigned int y = b;
    unsigned int z = c;

    unsigned int first_max = x;
    unsigned int second_max = y;
    unsigned int third_max = z;
    unsigned int temp;

    //@ assert is_valid_range(first_max) && is_valid_range(second_max) && is_valid_range(third_max);

    if (second_max > first_max)
    {
        temp = first_max;
        first_max = second_max;
        second_max = temp;
    }
    //@ assert first_max >= second_max;

    if (third_max > first_max)
    {
        temp = first_max;
        first_max = third_max;
        third_max = temp;
    }
    //@ assert first_max >= third_max;

    if (third_max > second_max)
    {
        temp = second_max;
        second_max = third_max;
        third_max = temp;
    }
    //@ assert first_max >= second_max && second_max >= third_max;

    //@ assert first_max == 7 && second_max == 5 && third_max == 5 ==> condition_holds(a, b, c);

    return (first_max == 7 && second_max == 5 && third_max == 5);
}

/* Function 2: Compare integer average with floor division average */
/*@
    predicate avg_definition(integer a, integer b, integer avg) =
        avg == (a + b) / 2;

    predicate avg_no_fp_definition(integer a, integer b, integer avg_no_fp) =
        avg_no_fp == a / 2 + b / 2;

    lemma avg_inequality:
        \forall integer a, b;
        1 <= a <= 100 && 1 <= b <= 100 ==>
        (a + b) / 2 >= a / 2 + b / 2;
*/

bool func_avg_compare(unsigned int a, unsigned int b)
{
    unsigned int avg_a_b;
    unsigned int avg_a_b_no_floating_point;
    bool result;

    avg_a_b = (a + b) / 2;
    avg_a_b_no_floating_point = a / 2 + b / 2;

    //@ assert avg_definition(a, b, avg_a_b);
    //@ assert avg_no_fp_definition(a, b, avg_a_b_no_floating_point);
    //@ assert (a + b) / 2 >= a / 2 + b / 2;

    result = avg_a_b >= avg_a_b_no_floating_point;
    return result;
}

/* Function 3: Check if a number is greater than all elements in an array */
/*@
    predicate is_greater_than_all{L}(int *arr, integer len, int number, integer i) =
        \forall integer j; 0 <= j < i ==> number > arr[j];
*/

bool check_greater(int *arr, int len, int number)
{
    int i = 0;
    bool flag = true;

    while (i < len)
    {
        if (number <= arr[i])
        {
            flag = false;
        }
        i = i + 1;
    }

    //@ assert flag == true ==> is_greater_than_all(arr, len, number, len);
    //@ assert flag == true ==> \forall integer i; 0 <= i < len ==> number > arr[i];
    return flag;
}

/* Synthesized function: Real-world scenario - Data validation for a sensor network
 * 
 * Scenario: A sensor network collects 3 temperature readings (1-10 range) and
 * stores them in a buffer. We need to validate that:
 * 1. The readings form a valid calibration pattern (5,5,7 permutation)
 * 2. The average of two specific readings satisfies a quality metric
 * 3. A threshold value exceeds all readings in the buffer
 *
 * Data flow:
 * - Three sensor readings a, b, c (1-10) are checked for calibration pattern
 * - Two readings (a,b) are used to compute average quality metric
 * - A threshold value is checked against an array of calibration data
 * - The final result indicates whether all validation checks pass
 */

bool validate_sensor_data(unsigned int a, unsigned int b, unsigned int c,
                          int threshold, int *arr, int len)
{
    bool calibration_ok;
    bool avg_quality_ok;
    bool threshold_ok;

    calibration_ok = func_permutation(a, b, c);

    avg_quality_ok = func_avg_compare(a, b);

    threshold_ok = check_greater(arr, len, threshold);

    //@ assert calibration_ok == true ==> condition_holds(a, b, c);
    //@ assert avg_quality_ok == true ==> (a + b) / 2 >= a / 2 + b / 2;
    //@ assert threshold_ok == true ==> \forall integer i; 0 <= i < len ==> threshold > arr[i];

    //@ assert (calibration_ok && avg_quality_ok && threshold_ok) == true ==> (condition_holds(a, b, c) && (a + b) / 2 >= a / 2 + b / 2 && \forall integer i; 0 <= i < len ==> threshold > arr[i]);

    return calibration_ok && avg_quality_ok && threshold_ok;
}
