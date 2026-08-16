#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* Predicates from first snippet */
/*@
    predicate valid_range(integer v) = 0 <= v <= 9;
*/

int64_t func(int64_t x, int64_t a)
{
    //@ assert valid_range(x) && valid_range(a);
    return (x < a) ? 0 : 10;
}

int64_t func_or(int64_t x, int64_t a)
{
    //@ assert valid_range(x) && valid_range(a);
    if (x >= a) {
        //@ assert x >= a;
        return 10;
    } else {
        //@ assert x < a;
        return 0;
    }
}

int64_t func_and(int64_t x, int64_t a)
{
    //@ assert valid_range(x) && valid_range(a);
    if (x < a) {
        //@ assert x < a;
        return 0;
    } else {
        //@ assert x >= a;
        return 10;
    }
}

int64_t func_or_else(int64_t x, int64_t a)
{
    //@ assert valid_range(x) && valid_range(a);
    if (x < a) {
        //@ assert x < a;
        return 0;
    } else {
        //@ assert x >= a;
        return 10;
    }
}

/* Predicates from second snippet */
/*@ predicate is_even(integer x) = x % 2 == 0; */
/*@ predicate at_least_one_even(integer a, integer b) = 
        is_even(a) || is_even(b); */

bool func_even(unsigned int a, unsigned int b)
{
    bool is_even = false;
    //@ assert a % 2 == 0 || b % 2 == 0 ==> at_least_one_even(a, b);
    if (a % 2 == 0 || b % 2 == 0)
    {
        is_even = true;
    }
    //@ assert is_even == (a % 2 == 0 || b % 2 == 0);
    return is_even;
}

/*@ predicate valid_seq(unsigned int* arr, integer len) = 
        len >= 0 && \valid(arr + (0..len-1)); */
/*@ predicate all_even(unsigned int* arr, integer len) = 
        \forall integer i; 0 <= i < len ==> arr[i] % 2 == 0; */

void test_vec1(unsigned int* v)
{
    v[0] = 0;
    v[1] = 10;
    v[2] = 20;
    v[3] = 30;
    v[4] = 40;
    
    //@ assert valid_seq(v, 5);
    //@ assert v[0] == 0;
    //@ assert v[1] == 10;
    //@ assert v[2] == 20;
    //@ assert v[3] == 30;
    //@ assert v[4] == 40;
    
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        //@ assert v[i] % 2 == 0;
    }
    //@ assert all_even(v, 5);
}

/* Predicate from third snippet */
/*@ predicate is_possible(integer a, integer b, integer x) =
      x <= a || (a < x && x <= a + b);
*/

bool is_possible_x_cats(int a, int b, int x)
{
    bool result;
    //@ assert is_possible(a, b, x) <==> (x <= a || (a < x && x <= a + b));
    result = (x <= a) || ((a < x) && (x <= a + b));
    return result;
}

/* Predicates from fourth snippet */
/*@ predicate valid_array(int *arr, size_t n) =
      n > 0 && n <= 20 &&
      \forall size_t i; 0 <= i < n ==> 1 <= arr[i] <= 100;
*/

/*@ predicate max_in_range(int max_h) =
      max_h >= 0 && max_h <= 100;
*/

/*@ predicate sum_in_range(int sum, size_t i) =
      sum >= 0 && sum <= (int)i;
*/

int func_height(size_t n, int *h) {
    int max_h = 0;
    size_t i = 0;
    int sum = 0;
    
    while (i < n) {
        int h_i = h[i];
        if (h_i >= max_h) {
            max_h = h_i;
        }
        i++;
    }
    
    i = 0;
    while (i < n) {
        int h_i = h[i];
        size_t next_i = (i + 1 < n) ? i + 1 : i;
        int next_h = h[next_i];
        if (h_i >= max_h && next_h < h_i) {
            sum += 1;
        }
        i++;
    }
    
    //@ assert sum >= 0;
    return sum;
}

/* ================================================================
   Synthesized Complex Function: "Score computation in a game level"
   ================================================================ */

int compute_score(size_t n, int *h, int64_t x, int64_t a, int64_t b_val,
                  int threshold_a, int threshold_b, int x_val,
                  unsigned int count_a, unsigned int count_b)
{
    int64_t base_val = func(x, a);
    //@ assert base_val == 0 || base_val == 10;
    
    bool both_even = func_even(count_a, count_b);
    //@ assert both_even == (count_a % 2 == 0 || count_b % 2 == 0);
    
    bool bonus_possible = is_possible_x_cats(threshold_a, threshold_b, x_val);
    //@ assert bonus_possible <==> is_possible(threshold_a, threshold_b, x_val);
    
    int peak_count = func_height(n, h);
    //@ assert peak_count >= 0;
    
    int final_score = (int)base_val;
    if (both_even) {
        final_score += 5;
    }
    if (bonus_possible) {
        final_score += peak_count;
    }
    
    //@ assert final_score >= 0;
    return final_score;
}
