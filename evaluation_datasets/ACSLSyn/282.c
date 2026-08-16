#include <stddef.h>
#include <stdbool.h>

/*@ predicate is_valid_range(integer r) = 1 <= r && r <= 100; */

/*@ logic integer compute_result(integer r) = 3 * r * r; */

/*@ lemma result_non_negative: 
      \forall integer r; is_valid_range(r) ==> compute_result(r) >= 0; */

/*@ lemma result_bounded: 
      \forall integer r; is_valid_range(r) ==> compute_result(r) <= 30000; */

int compute_area(int r)
{
    int ans;
    
    ans = 3 * r * r;
    
    return ans;
}

/*@ predicate valid_number_value(integer v) =
      v >= 1 && v <= 1000000000;
*/
/*@ predicate valid_array(int *arr, integer N) =
      \forall integer k; 0 <= k < N ==> valid_number_value(arr[k]);
*/

size_t count_non_divisible(size_t N, const int numbers[]) {
    size_t count = 0;
    size_t i = 0;
    
    while (i < N) {
        bool is_divisible = false;
        size_t j = 0;
        
        while (j < N) {
            if (i != j && numbers[i] % numbers[j] == 0) {
                is_divisible = true;
                break;
            }
            j++;
        }
        
        if (!is_divisible) {
            count++;
        }
        i++;
    }
    return count;
}

/*@
    predicate ordered(integer a, integer b, integer c, integer d, integer e) =
        0 <= a && a < b && b < c && c < d && d < e && e <= 123;
*/

bool check_spread(long a, long b, long c, long d, long e, long k)
{
    long max_val = e;
    long min_val = a;
    long diff;

    diff = max_val - min_val;

    if (diff <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

size_t process_grid_cells(int radius, size_t N, const int sensors[],
                          long a, long b, long c, long d, long e, long k)
{
    int area = compute_area(radius);
    
    long adjusted_k = (area % 124);
    bool spread_ok = check_spread(a, b, c, d, e, adjusted_k);
    
    size_t dominant_count = count_non_divisible(N, sensors);
    
    return dominant_count;
}
