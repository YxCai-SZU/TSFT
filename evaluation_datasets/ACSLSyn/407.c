#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/* ====== Original function 1: count gaps less than next value ====== */

/*@ predicate is_sorted(integer n, int64_t *numbers) =
      \forall integer j; 0 <= j < n - 1 ==> numbers[j] < numbers[j + 1];
*/

/*@ predicate in_range(integer n, int64_t *numbers, int64_t k) =
      \forall integer j; 0 <= j < n ==> 0 <= numbers[j] && numbers[j] < k;
*/

/*@ lemma sorted_range_lemma:
      \forall integer n, int64_t *numbers, int64_t k;
        n >= 2 && in_range(n, numbers, k) && is_sorted(n, numbers) ==>
        \forall integer i; 0 <= i < n - 1 ==> numbers[i + 1] - numbers[i] >= 0;
*/

size_t func1(int64_t k, size_t n, int64_t *numbers) {
    size_t count = 0;
    size_t i = 0;
    
    while (i < n - 1) {
        int64_t l = numbers[i + 1] - numbers[i];
        int64_t r;
        if (i == n - 2) {
            r = k;
        } else {
            r = numbers[i + 2];
        }
        
        //@ assert l >= 0;
        if (l < r) {
            count += 1;
        }
        i += 1;
    }
    return count;
}

/* ====== Original function 2: count pairs of odd numbers ====== */

/*@
    predicate is_odd(integer x) = x % 2 == 1;
    predicate is_even(integer x) = x % 2 == 0;
    
    logic integer parity(integer x) = (x % 2 == 1) ? 1 : 0;
    
    lemma answer_range:
        \forall integer a,b,c,d,sa,sb,sc,sd,answer;
        (1 <= a <= 10000 && 1 <= b <= 10000 && 
         1 <= c <= 10000 && 1 <= d <= 10000 &&
         sa == parity(a) && sb == parity(b) &&
         sc == parity(c) && sd == parity(d) &&
         answer == (sa == 1 && sb == 1 ? 1 : 0) + 
                   (sc == 1 && sd == 1 ? 1 : 0)) ==>
        (0 <= answer <= 2);
*/

int func2(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    int sa;
    int sb;
    int sc;
    int sd;
    int answer;
    
    sa = (a % 2 == 0) ? 0 : 1;
    sb = (b % 2 == 0) ? 0 : 1;
    sc = (c % 2 == 0) ? 0 : 1;
    sd = (d % 2 == 0) ? 0 : 1;
    
    answer = 0;
    
    if (sa == 1 && sb == 1)
    {
        answer += 1;
        //@ assert answer == 1;
    }
    
    if (sc == 1 && sd == 1)
    {
        answer += 1;
        //@ assert answer <= 2;
    }
    
    //@ assert answer >= 0 && answer <= 2;
    return answer;
}

/* ====== Original function 3: check if half_plus_one(n) >= k ====== */

/*@
    predicate valid_range(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= 100;

    logic integer half_plus_one(integer n) = n / 2 + 1;

    predicate result_condition(integer n, integer k) =
        half_plus_one(n) >= k;
*/

bool func3(unsigned int n, unsigned int k)
{
    bool result;

    //@ assert 1 <= n <= 100;
    //@ assert 1 <= k <= 100;

    result = (n / 2 + 1) >= k;
    return result;
}

/* ====== Original function 4: count local extrema in permutation ====== */

/*@ predicate distinct(int *p, integer n) =
      \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@ predicate in_range_arr(int *p, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= p[i] && p[i] <= n;
*/

/*@ lemma cnt_bound: \forall integer cnt, i, n;
      cnt <= i - 1 && 1 <= i <= n - 1 ==> cnt <= n - 2;
*/

uint32_t func4(uint32_t n, int *p) {
    uint32_t cnt = 0;
    uint32_t i = 1;

    while (i < n - 1) {
        bool left = p[i - 1] < p[i];
        bool right = p[i] < p[i + 1];
        
        //@ assert 0 <= i - 1 < n && 0 <= i < n && 0 <= i + 1 < n;
        
        if ((left && right) || (!left && !right)) {
            cnt += 1;
        }
        
        i += 1;
    }
    
    //@ assert cnt <= n - 2;
    return cnt;
}

/* ====== Synthesized complex function ====== */

int synthesized_function(
    uint32_t n, int *p,
    unsigned int a, unsigned int b, unsigned int c, unsigned int d,
    unsigned int n2, unsigned int k,
    int64_t k2, size_t n3, int64_t *numbers
) {
    uint32_t extrema_count = func4(n, p);
    
    int odd_pairs = func2(a, b, c, d);
    
    bool threshold_ok = func3(n2, k);
    
    size_t gap_count = func1(k2, n3, numbers);
    
    int result;
    if (threshold_ok && (extrema_count % 2 == 0)) {
        result = odd_pairs;
    } else {
        result = odd_pairs + 1;
        if (result > 2) {
            result = 2;
        }
    }
    
    //@ assert result >= 0 && result <= 2;
    return result;
}
