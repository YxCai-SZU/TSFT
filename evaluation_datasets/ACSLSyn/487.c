#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* ========== Original func1 (water volume calculation) ========== */
/*@
    predicate valid_input(int32_t *input) =
        \valid(input) &&
        input[0] >= 1 && input[0] <= 20 &&
        input[1] >= 1 && input[1] <= 20 &&
        input[2] >= 1 && input[2] <= 20;

    logic integer water_value(integer a, integer b) =
        (a - b) > 0 ? (a - b) : 0;

    logic integer total_water(integer a, integer b, integer c) =
        water_value(b, a) + water_value(c, b);

    logic integer bounded_total(integer a, integer b, integer c) =
        total_water(a, b, c) > 40 ? 40 : total_water(a, b, c);

    lemma water_nonnegative:
        \forall integer a, b, c;
            a >= 1 && a <= 20 && b >= 1 && b <= 20 && c >= 1 && c <= 20 ==>
            water_value(b, a) >= 0 && water_value(c, b) >= 0;

    lemma total_in_range:
        \forall integer a, b, c;
            a >= 1 && a <= 20 && b >= 1 && b <= 20 && c >= 1 && c <= 20 ==>
            bounded_total(a, b, c) >= 0 && bounded_total(a, b, c) <= 40;
*/

int32_t func1(int32_t *input)
{
    int32_t water;
    int32_t water2;
    int32_t ans;

    //@ assert input[0] >= 1 && input[0] <= 20;
    //@ assert input[1] >= 1 && input[1] <= 20;
    //@ assert input[2] >= 1 && input[2] <= 20;

    water = input[1] - input[0];
    if (water < 0)
    {
        water = 0;
    }

    water2 = input[2] - input[1];
    if (water2 < 0)
    {
        water2 = 0;
    }

    ans = water + water2;
    if (ans > 40)
    {
        ans = 40;
    }

    //@ assert ans >= 0;
    //@ assert ans <= 40;
    return ans;
}

/* ========== Original func2 (strictly increasing check) ========== */
/*@
    predicate valid_index_range(int *arr, integer len, integer i, integer j) =
        0 <= i < j < len;
*/

/*@
    lemma index_lemma:
        \forall int *arr, integer len;
        len >= 3 ==> valid_index_range(arr, len, 0, 1) && valid_index_range(arr, len, 1, 2);
*/

bool func2(int *v, size_t len) {
    size_t i;
    bool result;

    //@ assert len >= 3;
    
    //@ assert 0 <= 0 < len && 0 <= 1 < len && 0 <= 2 < len;
    
    i = 0;
    while (i < len - 2) {
        //@ assert 0 <= i < len - 2;
        i++;
    }
    
    result = v[0] < v[1] && v[1] < v[2];
    return result;
}

/* ========== Original func3 (find differing element) ========== */
/*@
    predicate is_valid_range(integer x) = -100 <= x <= 100;

    logic integer element_at{L}(long *arr, integer idx) = arr[idx];

    predicate answer_matches(integer ans, long *arr) =
        ans == element_at(arr, 0) ||
        ans == element_at(arr, 1) ||
        ans == element_at(arr, 2);

    lemma answer_preserved:
        \forall long *arr, integer ans, integer i;
            answer_matches(ans, arr) && 0 <= i < 3 ==>
            (ans == element_at(arr, i) || answer_matches(ans, arr));
*/

long func3(long *input) {
    long answer;
    unsigned int i;
    answer = input[0];
    i = 1;
    while (i < 3) {
        //@ assert answer_matches(answer, input);
        if (input[i] != answer) {
            answer = input[i];
        }
        i += 1;
    }
    //@ assert answer_matches(answer, input);
    return answer;
}

/* ========== Original func4 (even/odd count and answer) ========== */
/*@ predicate is_valid_array(int *arr, integer n) =
      n > 0 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> arr[i] > 0 && arr[i] <= 1000000000;
*/


/*@ lemma ans_non_negative:
      \forall integer b_even, b_odd, ans;
      b_even >= 0 && b_odd >= 0 &&
      (b_even > b_odd ==> ans == b_odd * 2 + 1) &&
      (b_even == b_odd ==> ans == b_even * 2) &&
      (b_even < b_odd ==> ans == b_even * 2) ==>
      ans >= 0;
*/

/*@ lemma ans_bound:
      \forall integer b_even, b_odd, ans, n;
      b_even >= 0 && b_odd >= 0 && b_even + b_odd == n &&
      (b_even > b_odd ==> ans == b_odd * 2 + 1) &&
      (b_even == b_odd ==> ans == b_even * 2) &&
      (b_even < b_odd ==> ans == b_even * 2) ==>
      ans <= n;
*/

int func4(int n, int *a) {
    int b_even = 0;
    int b_odd = 0;
    int index = 0;
    int i = 0;
    
    while (i < n) {
        index = a[i];
        
        //@ assert index > 0 && index <= 1000000000;
        
        if ((index & 1) == 0) {
            b_even = b_even + 1;
        } else {
            b_odd = b_odd + 1;
        }
        i = i + 1;
    }
    
    int ans = 0;
    
    if (b_even > b_odd) {
        ans = b_odd * 2 + 1;
    } else if (b_even == b_odd) {
        ans = b_even * 2;
    } else {
        ans = b_even * 2;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n;
    
    return ans;
}

/* ========== Synthesized function: water_quality_classifier ========== 
   Scenario: A water quality monitoring system processes sensor data from 
   three consecutive stations. For each station, it records:
   - water levels (input1: three consecutive readings, each 1-20, used by func1)
   - temperature readings (input2: three consecutive values, used by func2 to check increasing trend)
   - pH values (input3: three values in range -100 to 100, used by func3 to find differing pH)
   - pollutant counts (array a of size n, used by func4 to compute even/odd based metric)
   
   Data flow:
   1. func1 computes bounded total water volume from three readings (0-40)
   2. func2 checks if three temperature readings are strictly increasing
   3. func3 finds a pH value that differs from the first reading
   4. func4 computes even/odd based answer from pollutant counts
   
   The synthesized function determines if water quality is "good" based on:
   - total water volume <= 30 (not too high)
   - temperatures are strictly increasing (stable warming pattern)
   - the differing pH value is positive (indicating acceptable pH range)
   - func4 result > n/2 (indicating majority of readings are even)
   
   High-level property: The function correctly classifies water quality
   based on the combined sensor data invariants.
*/

/*@
    predicate water_quality_classifier_pre(int32_t *input1, int *input2, size_t len2, 
                                           long *input3, int n, int *a) =
        valid_input(input1) &&
        \valid_read(input2 + (0 .. 2)) && len2 >= 3 &&
        \valid_read(input3 + (0 .. 2)) &&
        is_valid_range(input3[0]) && is_valid_range(input3[1]) && is_valid_range(input3[2]) &&
        n > 0 && n <= 200000 && \valid(a + (0 .. n-1)) && is_valid_array(a, n);

    predicate water_quality_classifier_post(int result, int32_t *input1, int *input2, 
                                            long *input3, int n, int *a) =
        result == 0 || result == 1;
*/

int water_quality_classifier(int32_t *input1, int *input2, size_t len2, 
                              long *input3, int n, int *a) 
{
    int32_t water_vol;
    bool increasing;
    long diff_ph;
    int pollutant_metric;
    int result;
    
    water_vol = func1(input1);
    //@ assert water_vol >= 0 && water_vol <= 40;
    
    increasing = func2(input2, len2);
    //@ assert increasing == (input2[0] < input2[1] && input2[1] < input2[2]);
    
    diff_ph = func3(input3);
    //@ assert answer_matches(diff_ph, input3);
    
    pollutant_metric = func4(n, a);
    //@ assert pollutant_metric >= 0 && pollutant_metric <= n;
    
    if (water_vol <= 30 && increasing && diff_ph > 0 && pollutant_metric > n / 2) {
        result = 1;  // good
    } else {
        result = 0;  // not good
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
