#include <stdbool.h>
#include <stddef.h>

/* ========== Original Functions (adapted for consistency) ========== */

/* predicate for a 5-element vector with values in [0,123] */
/*@
    predicate valid_vector(int *v, integer len) =
        len == 5 &&
        \forall integer i; 0 <= i < len ==> 0 <= v[i] <= 123;
*/

/* predicate for a 5-element strictly increasing sequence */
/*@
    predicate ordered(integer a, integer b, integer c, integer d, integer e) =
      a < b && b < c && c < d && d < e;
*/

/* predicate for a 3-element vector with values in [1,5000] */
/*@
    predicate valid_vec(int *v, integer len) =
        len == 3 &&
        1 <= v[0] && v[0] <= 5000 &&
        1 <= v[1] && v[1] <= 5000 &&
        1 <= v[2] && v[2] <= 5000;
*/

/* predicate for a 3-element vector with values in [1,100] */
/*@
    predicate valid_vec2(int *v, integer len) =
        len == 3 &&
        1 <= v[0] && v[0] <= 100 &&
        1 <= v[1] && v[1] <= 100 &&
        1 <= v[2] && v[2] <= 100;
*/

/* helper predicates */
/*@
    logic integer sum_first_two(int *v) = v[0] + v[1];
    predicate is_triangle(int *v) = v[2] <= sum_first_two(v);
    predicate is_arithmetic(int *v) = v[1] - v[0] == v[2] - v[1];
    predicate is_strictly_increasing(int *v) = v[0] < v[1] && v[1] < v[2];
    predicate is_middle_last(int *v) = v[0] < v[2] && v[2] < v[1];
*/

/* Original func: triangle test */
bool func_triangle(int *v)
{
    int a = v[0];
    int b = v[1];
    int c = v[2];
    //@ assert 1 <= a && a <= 5000;
    //@ assert 1 <= b && b <= 5000;
    //@ assert 1 <= c && c <= 5000;
    return c <= a + b;
}

/* Original func2: arithmetic test */
bool func_arithmetic(int *A)
{
    int a = A[0];
    int b = A[1];
    int c = A[2];
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    return b - a == c - b;
}

/* Original func3: strictly increasing test */
bool func_strictly_increasing(int *v)
{
    int a = v[0];
    int b = v[1];
    int c = v[2];
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    return a < b && b < c;
}

/* Original func4: middle-last test */
bool func_middle_last(int *v)
{
    int a = v[0];
    int b = v[1];
    int c = v[2];
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    return a < c && c < b;
}

/* Original function from snippet 2: count numbers divisible by 2 and (3 or 5) */
/*@
    predicate is_valid_array(int* arr, integer n) =
      n > 0 && n <= 100 &&
      \forall integer i; 0 <= i < n ==> arr[i] > 0 && arr[i] <= 1000;
*/
int func_count_special(int n, int* numbers) {
    int i = 0;
    int count = 0;
    while (i < n) {
        int a = numbers[i];
        //@ assert a > 0 && a <= 1000;
        if (a % 2 == 0 && (a % 3 == 0 || a % 5 == 0)) {
            count++;
        }
        i++;
    }
    return count;
}

/* Original function from snippet 3: compare k with last element of vector */
bool func_compare_last(int *v, int k) {
    int a[5];
    int i = 0;
    while (i < 5) {
        a[i] = v[i];
        i = i + 1;
    }
    //@ assert a[4] == v[4];
    return k >= a[4];
}

/* Original function from snippet 4: check range of ordered sequence */
bool func_ordered_range(long a, long b, long c, long d, long e, long k)
{
    //@ assert a < e;
    bool result = (e - a) <= k;
    //@ assert result == (e - a <= k);
    return result;
}

/* ========== Synthesized Complex Function ========== */

typedef struct {
    bool spread_within_k;
    bool last_ge_k;
    int special_count;
    bool is_triangle;
    bool is_arithmetic;
    bool is_strictly_increasing;
    bool is_middle_last;
    bool all_properties_hold;
} AnalysisResult;

/*@
    predicate valid_analysis_input(int *v, integer len_v, int k,
                                    int *numbers, integer n,
                                    int *sides, int *seq) =
        valid_vector(v, len_v) && len_v == 5 &&
        0 <= k <= 123 &&
        n > 0 && n <= 100 && is_valid_array(numbers, n) &&
        \valid(sides + (0..2)) && valid_vec(sides, 3) &&
        \valid(seq + (0..2)) && valid_vec2(seq, 3) &&
        ordered(v[0], v[1], v[2], v[3], v[4]);
*/

AnalysisResult analyze_data(int *v, int k, int n, int *numbers, int *sides, int *seq)
{
    AnalysisResult res;

    res.spread_within_k = func_ordered_range(v[0], v[1], v[2], v[3], v[4], k);
    
    res.last_ge_k = func_compare_last(v, k);
    
    res.special_count = func_count_special(n, numbers);
    
    res.is_triangle = func_triangle(sides);
    
    res.is_arithmetic = func_arithmetic(seq);
    res.is_strictly_increasing = func_strictly_increasing(seq);
    res.is_middle_last = func_middle_last(seq);
    
    res.all_properties_hold = res.spread_within_k && res.last_ge_k && 
                              res.is_triangle && res.is_strictly_increasing;
    
    return res;
}
