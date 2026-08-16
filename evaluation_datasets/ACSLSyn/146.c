#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

/*@
    predicate bounds(integer x, integer low, integer high) =
        low <= x <= high;

    logic integer min(integer a, integer b) =
        a < b ? a : b;

    lemma square_bound:
        \forall integer d; 0 <= d <= 204 ==> d * d <= 204 * 204;

    lemma sum_square_bound:
        \forall integer dx, dy;
            0 <= dx <= 204 && 0 <= dy <= 204 ==>
            dx * dx + dy * dy <= 2 * 204 * 204;
*/

/*@ predicate is_valid_array(unsigned int *arr, size_t len, size_t n) =
      n > 0 && n <= 100 && len == n &&
      \forall size_t i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 1000;
*/

/*@ lemma array_bounds_preserved:
      \forall unsigned int *arr, size_t len, size_t n;
      is_valid_array(arr, len, n) ==>
      \forall size_t k; 0 <= k < len ==> arr[k] >= 1 && arr[k] <= 1000;
*/

int func(int x, int y)
{
    int ans = 1000000;
    int i = 1;

    while (i < 205)
    {
        int j = 1;

        while (j < 205)
        {
            int diff_x = (i > x) ? (i - x) : (x - i);
            int diff_y = (j > y) ? (j - y) : (y - j);

            //@ assert bounds(diff_x, 0, 204);
            //@ assert bounds(diff_y, 0, 204);
            //@ assert diff_x * diff_x <= 204 * 204;
            //@ assert diff_y * diff_y <= 204 * 204;
            //@ assert diff_x * diff_x + diff_y * diff_y <= 2 * 204 * 204;

            int dist_squared = diff_x * diff_x + diff_y * diff_y;
            ans = (ans < dist_squared) ? ans : dist_squared;
            j++;
        }
        i++;
    }
    return ans;
}

unsigned int myfun(unsigned int n, unsigned int *p) {
    unsigned int min = 1000;
    unsigned int cnt = 0;
    size_t index = 0;
    
    //@ assert is_valid_array(p, n, n);
    
    while (index < n) {
        unsigned int pp = p[index];
        //@ assert pp >= 1 && pp <= 1000;
        
        if (pp < min) {
            min = pp;
            cnt = cnt + 1;
            //@ assert cnt <= index + 1;
        }
        index = index + 1;
    }
    
    //@ assert cnt <= n;
    return cnt;
}

int process_grid_and_array(int x, int y, unsigned int n, unsigned int *p)
{
    int min_dist_sq = func(x, y);
    
    unsigned int change_count = myfun(n, p);
    
    int result;
    if (change_count > n / 2) {
        //@ assert change_count > n / 2;
        result = min_dist_sq;
    } else {
        result = min_dist_sq / 2;
    }
    
    //@ assert result >= 0 && result <= 1000000;
    return result;
}
