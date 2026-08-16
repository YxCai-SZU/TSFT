#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

/* Original functions with their ACSL specifications */

/* Function 1: compute_ans */
/*@
    predicate valid_range_m(integer m) =
        1 <= m && m <= 12;

    logic integer compute_ans(integer m) =
        48 - m;

    lemma ans_non_negative:
        \forall integer m; valid_range_m(m) ==> compute_ans(m) >= 0;
*/

int64_t func1(int64_t m)
{
    int64_t ans;
    //@ assert valid_range_m(m);
    
    ans = (24 - m) + 24;
    
    //@ assert ans == 48 - m;
    //@ assert ans >= 0;
    
    return ans;
}

/* Function 2: in_range check */
/*@ predicate in_range(integer x) = INT_MIN < x < INT_MAX; */

bool func2(int a, int b, int c) {
    int state = 0;
    
    //@ assert state == 0;
    
    if (c > a) {
        state = state + 1;
    }
    //@ assert (c > a) ==> (state == 1);
    //@ assert !(c > a) ==> (state == 0);
    
    if (c < b) {
        state = state + 1;
    }
    //@ assert (c > a && c < b) ==> (state == 2);
    //@ assert !(c > a && c < b) ==> (state < 2);
    
    return state == 2;
}

/* Function 3: array processing */
/*@ predicate valid_array(int64_t *a, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 200000;
*/


/*@ lemma counter_bound_lemma:
      \forall integer i, integer n; 1 <= i <= n && 2 <= n <= 200000 ==>
      10000000000 * (i - 1) + (200000 * (i - 1)) >= 0;
*/

int64_t func3(int64_t n, int64_t *a) {
    int64_t min;
    int64_t counter;
    int64_t i;
    int64_t result;
    
    //@ assert 2 <= n <= 200000;
    //@ assert valid_array(a, n);
    
    min = 10000000000;
    counter = 0;
    i = 1;
    
    while (i < n) {
        //@ assert 1 <= i <= n;
        
        if (a[i] > a[i - 1]) {
            counter += a[i] - a[i - 1];
        } else {
            min = (min < counter) ? min : counter;
            counter = 0;
        }
        i += 1;
        
        //@ assert min >= 0;
        //@ assert counter >= 0;
    }
    
    min = (min < counter) ? min : counter;
    result = min;
    
    //@ assert result >= 0;
    
    return result;
}

/* Function 4: equality check */
/*@
    predicate valid_range_x(integer x) = 1 <= x <= 9;
*/

bool func4(unsigned long a, unsigned long b, unsigned long c)
{
    //@ assert valid_range_x(a);
    //@ assert valid_range_x(b);
    //@ assert valid_range_x(c);
    
    bool result;
    result = (a == b && b != c) || (a == c && a != b) || (b == c && a != c);
    
    return result;
}

/* Synthesized complex function: Data validation and processing pipeline */
int complex_processing(int64_t month, int64_t n, int64_t *data, 
                       int threshold_min, int threshold_max, int check_val,
                       unsigned long id1, unsigned long id2, unsigned long id3)
{
    int64_t adjusted_value;
    bool range_check;
    int64_t min_gap;
    bool id_match;
    int result;
    
    //@ assert valid_range_m(month);
    adjusted_value = func1(month);
    //@ assert adjusted_value == 48 - month;
    //@ assert adjusted_value >= 0;
    
    //@ assert in_range(threshold_min) && in_range(threshold_max) && in_range(check_val);
    range_check = func2(threshold_min, threshold_max, (int)adjusted_value);
    //@ assert range_check == (adjusted_value > threshold_min && adjusted_value < threshold_max);
    
    //@ assert 2 <= n <= 200000;
    //@ assert valid_array(data, n);
    min_gap = func3(n, data);
    //@ assert min_gap >= 0;
    
    //@ assert valid_range_x(id1) && valid_range_x(id2) && valid_range_x(id3);
    id_match = func4(id1, id2, id3);
    //@ assert id_match == (((id1 == id2) && (id2 != id3)) || ((id1 == id3) && (id3 != id2)) || ((id2 == id3) && (id1 != id2)));
    
    if (range_check && min_gap > 0 && id_match) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert (result == 1) ==> (adjusted_value > threshold_min && adjusted_value < threshold_max && min_gap > 0 && ((id1 == id2 && id2 != id3) || (id1 == id3 && id3 != id2) || (id2 == id3 && id1 != id2)));
    
    return result;
}
