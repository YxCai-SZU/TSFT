#include <stddef.h>
#include <stdint.h>
#include <limits.h>

/*@ predicate valid_range(integer m, integer n) = m <= n; */

/*@ predicate count_bounds(integer cnt, integer len) =
      cnt >= 0 && cnt <= len; */

/*@ logic integer element_in_range(int val, integer m, integer n) =
      (val >= m && val <= n) ? 1 : 0; */

/*@ lemma count_non_negative:
      \forall integer cnt, integer len;
      count_bounds(cnt, len) ==> cnt >= 0; */

/*@ lemma count_upper_bound:
      \forall integer cnt, integer len;
      count_bounds(cnt, len) ==> cnt <= len; */

size_t count_element_range(const int* list1, size_t len, int m, int n)
{
    size_t count = 0;
    size_t i = 0;
    
    while (i < len) {
        if (list1[i] >= m && list1[i] <= n) {
            count += 1;
        }
        i += 1;
    }
    
    return count;
}

/*@
    predicate valid_range2(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;

    logic integer compute_result(integer n, integer m) =
        (n + m) * 2 < 50 ? (n + m) * 2 : 50;
*/

int func(int n, int m)
{
    int result;
    int temp;

    temp = (n + m) * 2;

    if (temp < 50)
    {
        result = temp;
    }
    else
    {
        result = 50;
    }

    return result;
}

/*@ predicate buffer_quality(integer count, integer total, integer threshold) =
      count >= 0 && total > 0 && threshold > 0 &&
      (count * 100 / total) >= threshold; */

int analyze_buffer_quality(const int* buffer, size_t len, int m, int n, 
                           int low_bound, int high_bound)
{
    size_t count_in_range = count_element_range(buffer, len, m, n);
    
    int threshold_factor = func(low_bound, high_bound);
    
    int is_good = 0;
    
    if (count_in_range * 100 / len >= (size_t)threshold_factor) {
        is_good = 1;
    }
    
    return is_good;
}
