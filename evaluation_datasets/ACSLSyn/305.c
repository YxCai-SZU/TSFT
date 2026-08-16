#include <stdint.h>
#include <stddef.h>

/* ====== Function 1 (as provided) ====== */

/*@
    predicate valid_array1(int64_t *arr, integer n) =
        n > 0 && n <= 200000 &&
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 1000000000;

    logic integer max_upper_bound(integer idx) = idx * 1000000000;

    lemma mx_bound: \forall integer idx, int64_t mx;
        idx >= 0 && mx >= 0 && mx <= max_upper_bound(idx) ==> 
        mx <= max_upper_bound(idx + 1);

    lemma sum_bound: \forall integer idx, int64_t sum;
        idx >= 0 && sum >= 0 && sum <= max_upper_bound(idx) ==> 
        sum <= max_upper_bound(idx + 1);
*/

int64_t func1(uint32_t n, const int64_t v[])
{
    int64_t mx = 0;
    int64_t sum = 0;
    uint32_t index = 0;

    while (index < n)
    {
        int64_t a = v[index];

        if (a - sum > 0)
        {
            mx += a - sum;
        }
        else
        {
            sum += a;
        }

        //@ assert mx >= 0;
        //@ assert sum >= 0;
        //@ assert mx <= max_upper_bound(index + 1);
        //@ assert sum <= max_upper_bound(index + 1);

        index++;
    }

    return mx;
}

/* ====== Function 2 (as provided) ====== */

/*@
    predicate valid_array2(int64_t *a, size_t n) =
        n >= 2 && n <= 200000 &&
        \valid(a + (0 .. n-1)) &&
        \forall size_t i; 0 <= i < n ==> 0 <= a[i] <= 1000000000;

    logic integer array_product{L}(int64_t *a, integer i, integer j) = a[i] * a[j];

    lemma product_bounds:
        \forall int64_t *a, integer i, integer j;
        (0 <= a[i] <= 1000000000 && 0 <= a[j] <= 1000000000) ==>
        array_product(a, i, j) >= 0 &&
        array_product(a, i, j) <= 1000000000000000000;
*/

int64_t func2(size_t n, const int64_t *a) {
    int64_t sum = 0;
    const int64_t mod_value = 1000000007;
    size_t b = 0;
    
    while (b < n) {
        size_t c = b + 1;
        
        while (c < n) {
            //@ assert 0 <= a[b] <= 1000000000;
            //@ assert 0 <= a[c] <= 1000000000;
            //@ assert a[b] * a[c] >= 0 && a[b] * a[c] <= 1000000000000000000;
            
            int64_t product = a[b] * a[c];
            sum = sum + product;
            
            while (sum >= mod_value) {
                sum = sum - mod_value;
            }
            
            c += 1;
        }
        b += 1;
    }
    
    //@ assert 0 <= sum < mod_value;
    return sum;
}

/* ====== Function 3 (as provided) ====== */

/*@ predicate valid_params(size_t n, size_t a, size_t b) =
      3 <= n && n <= 100 &&
      1 <= a && a < b && b <= n;
*/

/*@ predicate valid_array3(size_t n, size_t *ps) =
      \forall integer i; 0 <= i < n ==> (1 <= ps[i] && ps[i] <= n);
*/

/*@ predicate excluded_values(size_t n, size_t a, size_t b, size_t *ps) =
      \forall integer i; 0 <= i < n ==> (ps[i] != a && ps[i] != b);
*/

/*@ lemma result_bounds:
      \forall size_t n, size_t a, size_t b, size_t *ps;
      valid_params(n, a, b) && valid_array3(n, ps) && excluded_values(n, a, b, ps) ==>
      (\forall integer ac, integer bc, integer ans;
      0 <= ac <= (integer)n && 0 <= bc <= (integer)n && ans == (ac < bc ? ac : bc) ==> 0 <= ans <= (integer)n);
*/

size_t func3(size_t n, size_t a, size_t b, size_t *ps) {
    size_t ac = 0;
    size_t bc = 0;
    size_t ans = 0;
    size_t i = 0;
    
    while (i < n) {
        //@ assert 0 <= i < n;
        if (ps[i] < a) {
            ac = ac + 1;
        } else if (ps[i] < b) {
            bc = bc + 1;
        }
        i = i + 1;
    }
    
    //@ assert 0 <= ac <= n && 0 <= bc <= n;
    ans = (ac < bc) ? ac : bc;
    //@ assert 0 <= ans <= n;
    return ans;
}

/* ====== Synthesized Function: ProcessArrayStats ====== */

int64_t process_array_stats(
    uint32_t n, const int64_t v[],
    size_t n2, const int64_t *a,
    size_t n3, size_t pa, size_t pb, size_t *ps)
{
    int64_t result1 = func1(n, v);
    int64_t result2 = func2(n2, a);
    size_t result3 = func3(n3, pa, pb, ps);
    
    int64_t combined = result1 + result2 + (int64_t)result3;
    
    //@ assert combined >= 0;
    return combined;
}
