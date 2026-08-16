#include <stdbool.h>

/* ===== First function: check temperature threshold ===== */
/*@ predicate is_ge_30(integer x) = x >= 30; */

bool func_temp(int x)
{
    bool result;
    int i;
    
    if (x >= 30) {
        result = true;
    } else {
        i = 0;
        while (i < 10) {
            //@ assert !is_ge_30(x);
            if (x >= 30) {
                result = true;
                return result;
            }
            i = i + 1;
        }
        result = false;
    }
    
    return result;
}

/* ===== Second function: check triangle equality condition ===== */
/*@ predicate is_divisible_by_3_or_5(integer n) = 
      n % 3 == 0 || n % 5 == 0; */

/*@ lemma lemma_is_divisible_by_3_or_5:
      \forall integer n; n % 3 == 0 || n % 5 == 0 ==> is_divisible_by_3_or_5(n); */

/*@ predicate all_positive(int *list, integer len) =
      \forall integer i; 0 <= i < len ==> list[i] > 0; */

/*@ predicate has_duplicates(int *list, integer len) =
      \exists integer i, j; 0 <= i < len && 0 <= j < len && i != j && list[i] == list[j]; */

/*@ lemma lemma_all_positive:
      \forall int *list, integer len; 
        all_positive(list, len) ==> 
        \forall integer i; 0 <= i < len ==> list[i] > 0; */

/*@ lemma lemma_has_duplicates:
      \forall int *list, integer len;
        has_duplicates(list, len) ==>
        \exists integer i, j; 
          0 <= i < len && 0 <= j < len && i != j && list[i] == list[j]; */

bool func_triangle(int a, int b, int c) {
    bool result;
    result = (a + b == c) || (b + c == a) || (c + a == b);
    
    //@ assert result == true <==> a + b == c || b + c == a || c + a == b;
    
    return result;
}

/* ===== Third function: compute adjusted value ===== */
/*@
    predicate valid_range(integer a) = 1 <= a && a <= 100;

    logic integer compute_result(integer a, integer b) = a - b * 2;

    lemma positive_result_prop:
        \forall integer a, b;
            valid_range(a) && valid_range(b) && compute_result(a, b) > 0 ==>
            compute_result(a, b) == a - b * 2;

    lemma nonpositive_result_prop:
        \forall integer a, b;
            valid_range(a) && valid_range(b) && compute_result(a, b) <= 0 ==>
            compute_result(a, b) <= 0;
*/

long long func_adjust(long long A, long long B)
{
    long long ans;
    long long res;

    ans = A - B * 2;

    if (ans > 0)
    {
        //@ assert ans == A - B * 2;
        res = ans;
    }
    else
    {
        //@ assert ans <= 0;
        res = 0;
    }

    //@ assert res >= 0;
    //@ assert res == A - B * 2 || res == 0;
    return res;
}

/* ===== Fourth function: classify based on patterns ===== */
/*@
    predicate valid_params(integer n, integer x) =
        0 <= n <= 100 && 0 <= x <= n * 3;

    logic integer triple(integer i) = i * 3;

    lemma triple_positive: \forall integer n; 0 <= n ==> 0 <= triple(n);
*/

int func_classify(int n, int x) {
    int result = -1;
    int sum = 0;
    int i = 0;
    int pattern3 = 0;
    int pattern2 = 0;
    int j = 0;

    //@ assert 0 <= n <= 100 && 0 <= x <= n * 3;

    while (i < n) {
        sum += 3;
        i += 1;
    }

    //@ assert sum == n * 3;

    j = 0;
    while (j < n) {
        pattern3 += 1;
        j += 1;
    }

    //@ assert pattern3 == n;

    j = 0;
    while (j < n) {
        pattern2 += 2;
        j += 1;
    }

    //@ assert pattern2 == n * 2;

    if (x >= sum) {
        result = 0;
    } else if (x < pattern3) {
        result = 1;
    } else if (x < pattern2) {
        result = 2;
    } else {
        result = 3;
    }

    //@ assert result == 0 || result == 1 || result == 2 || result == 3;
    return result;
}

/* ===== Synthesized function: Environmental monitoring data validation =====
   Scenario: An environmental sensor system checks temperature readings,
   validates triangle-consistent sensor triplets, adjusts calibration offsets,
   and classifies the confidence level of the reading.
   Data flow:
   1. Check if temperature reading is >= 30°C (heat alert threshold)
   2. Validate three sensor readings form a valid triangle relationship
   3. Adjust raw sensor value using calibration offset
   4. Classify the confidence level based on pattern analysis
   The final assertion: The output classification is valid (0-3) when
   temperature is >= 30 and triangle condition holds.
*/
int environmental_monitoring(
    int temp,
    int sensor_a, int sensor_b, int sensor_c,
    long long calibration_A, long long calibration_B,
    int n, int x
) {
    bool heat_alert = func_temp(temp);
    
    bool triangle_ok = func_triangle(sensor_a, sensor_b, sensor_c);
    
    long long adjusted = func_adjust(calibration_A, calibration_B);
    
    int confidence = func_classify(n, x);
    
    //@ assert (heat_alert && triangle_ok) ==> (confidence == 0 || confidence == 1 || confidence == 2 || confidence == 3);
    
    return confidence;
}
