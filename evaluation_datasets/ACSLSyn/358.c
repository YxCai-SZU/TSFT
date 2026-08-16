#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

/* ====== First function: map range to value ====== */

/*@ predicate in_range_400_599(integer x) = 400 <= x <= 599;
    predicate in_range_600_799(integer x) = 600 <= x <= 799;
    predicate in_range_800_999(integer x) = 800 <= x <= 999;
    predicate in_range_1000_1199(integer x) = 1000 <= x <= 1199;
    predicate in_range_1200_1399(integer x) = 1200 <= x <= 1399;
    predicate in_range_1400_1599(integer x) = 1400 <= x <= 1599;
    predicate in_range_1600_1799(integer x) = 1600 <= x <= 1799;
    predicate in_range_1800_1999(integer x) = 1800 <= x <= 1999;
 */

int map_range(int X)
{
    int result;

    //@ assert 400 <= X <= 1999;

    if (400 <= X && X <= 599)
    {
        //@ assert 400 <= X <= 599;
        result = 8;
        return result;
    }
    else if (600 <= X && X <= 799)
    {
        //@ assert 600 <= X <= 799;
        result = 7;
        return result;
    }
    else if (800 <= X && X <= 999)
    {
        //@ assert 800 <= X <= 999;
        result = 6;
        return result;
    }
    else if (1000 <= X && X <= 1199)
    {
        //@ assert 1000 <= X <= 1199;
        result = 5;
        return result;
    }
    else if (1200 <= X && X <= 1399)
    {
        //@ assert 1200 <= X <= 1399;
        result = 4;
        return result;
    }
    else if (1400 <= X && X <= 1599)
    {
        //@ assert 1400 <= X <= 1599;
        result = 3;
        return result;
    }
    else if (1600 <= X && X <= 1799)
    {
        //@ assert 1600 <= X <= 1799;
        result = 2;
        return result;
    }
    else if (1800 <= X && X <= 1999)
    {
        //@ assert 1800 <= X <= 1999;
        result = 1;
        return result;
    }

    result = -1;
    return result;
}

/* ====== Second function: count local extrema in permutation ====== */

/*@ predicate is_valid_index(integer i, integer n) =
      0 <= i && i < n;
*/

/*@ predicate is_valid_value(integer v, integer n) =
      v >= 1 && v <= n;
*/

/*@ predicate all_distinct(int *p, integer n) =
      \forall integer i, j;
        0 <= i < j < n ==> p[i] != p[j];
*/


/*@ lemma answer_bounds:
      \forall integer n, ans;
        n >= 1 && ans >= 0 && ans <= n ==> ans >= 0 && ans <= n;
*/

int count_extrema(int n, int *p) {
    int answer = 0;
    int index = 0;
    int left = 0;
    int right = 0;
    int i = 0;

    while (index < n) {
        i = p[index];
        left = 0;
        right = 0;

        if (index > 0) {
            left = p[index - 1];
        }

        if (index < n - 1) {
            right = p[index + 1];
        }

        //@ assert left == 0 || (index > 0 && left == p[index - 1]);
        //@ assert right == 0 || (index < n - 1 && right == p[index + 1]);

        if ((i < left && i < right) || (i > left && i > right)) {
            answer += 1;
        }

        //@ assert answer >= 0;
        //@ assert answer <= index + 1;

        index += 1;
    }

    //@ assert answer >= 0;
    //@ assert answer <= n;
    return answer;
}

/* ====== Third function: count ascending pairs in array segment ====== */

/*@ predicate is_valid_array(int *a, size_t n) =
      n >= 1 && n <= 100000 &&
      \forall size_t i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000000 &&
      \forall size_t i, j; 0 <= i < j < n ==> a[i] != a[j];
*/


/*@ lemma loop_decreases: \forall size_t m, i; i <= m ==> m - i >= 0; */

int count_asc_pairs(size_t n, size_t m, int *a) {
    int count;
    size_t l;
    size_t r;
    size_t i;
    int result;

    //@ assert 1 <= n && n <= 100000;
    //@ assert 1 <= m && m <= n;
    //@ assert is_valid_array(a, n);

    count = 0;
    l = 0;
    r = 0;
    i = 0;

    while (i < m) {
        l = r;
        //@ assert 0 <= l && l < n;
        
        if (i + 1 < n) {
            r = i + 1;
        } else {
            r = 0;
        }
        //@ assert 0 <= r && r < n;

        if (a[l] < a[r]) {
            //@ assert count >= 0;
            count = count + 1;
            //@ assert count <= (int)(i + 1);
        }

        i = i + 1;
        //@ assert count <= (int)i;
    }

    //@ assert i == m;
    //@ assert count >= 0 && count <= (int)m;

    if (count >= 2) {
        result = -1;
    } else {
        result = (int)n - count;
    }

    //@ assert result >= -1;
    //@ assert result <= (int)n;

    return result;
}

/* ====== Fourth function: multiply two bounded integers ====== */

/*@ predicate is_valid_range(integer a) = 1 <= a <= 100; */

/*@ predicate valid_inputs(integer a, integer b) = 
        is_valid_range(a) && is_valid_range(b); */

/*@ lemma multiplication_bound: 
        \forall integer a, b; 
        valid_inputs(a, b) ==> a * b <= 100 * 100; */

int multiply_bounded(int a, int b) {
    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert a * b <= 100 * 100;
    return a * b;
}

/* ====== Main synthesized function: Image Resolution Analyzer ====== 
 * Real-world scenario: Analyze a digital image file header to determine 
 * if the resolution is valid. The image has width (400-1999) and height 
 * (400-1999). We extract quality tiers from the width, count extrema 
 * in a permutation representing pixel values, check ascending pairs 
 * in a segment, and multiply bounded coefficients to compute a score.
 * The final output is a boolean indicating if the image passes all checks.
 */

int analyze_image_resolution(int width, int height, int n, int *p, 
                              size_t arr_n, size_t m, int *a, 
                              int coeff_a, int coeff_b) {
    
    int tier = map_range(width);
    int extrema_count = count_extrema(n, p);
    int asc_pairs_result = count_asc_pairs(arr_n, m, a);
    int product = multiply_bounded(coeff_a, coeff_b);
    
    int result;
    
    if (tier >= 1 && tier <= 8 &&
        extrema_count >= 0 && extrema_count <= n &&
        asc_pairs_result >= -1 && asc_pairs_result <= (int)arr_n &&
        product >= 1 && product <= 10000) {
        
        if (tier >= 5 && extrema_count > n/2 && asc_pairs_result != -1) {
            result = 1;
        } else {
            result = 0;
        }
    } else {
        result = 0;
    }
    
    //@ assert (result == 1) ==> (tier >= 5 && extrema_count > n/2 && asc_pairs_result != -1);
    
    return result;
}
