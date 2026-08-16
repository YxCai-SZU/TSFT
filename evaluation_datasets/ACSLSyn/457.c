#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/* ========== Original Function 1: Array processing ========== */

/*@ predicate valid_vec(size_t N, int64_t *vec) =
      N >= 1 && N <= 200000 &&
      \valid(vec + (0 .. N-1)) &&
      \forall integer i; 0 <= i < N ==> 1 <= vec[i] && vec[i] <= N;
*/



int64_t func1(size_t N, int64_t *vec) {
    size_t tmp = 0;
    size_t index = 0;

    while (index < N) {
        int64_t i = vec[index];
        //@ assert 1 <= i && i <= N;
        if (i == (int64_t)(tmp + 1)) {
            tmp += 1;
        }
        index += 1;
    }

    if (tmp == 0) {
        return -1;
    } else {
        return (int64_t)(N - tmp);
    }
}

/* ========== Original Function 2: Uniqueness check ========== */

/*@
    predicate all_unique(int *list, integer len) =
        \forall integer a, b; 0 <= a < b < len ==> list[a] != list[b];
*/

bool func2(int *list, size_t len) {
    size_t i = 0;
    size_t j = 0;
    
    for (i = 0; i < len; ++i) {
        for (j = i + 1; j < len; ++j) {
            //@ assert list[i] != list[j];
        }
    }
    
    //@ assert all_unique(list, len);
    return true;
}

/* ========== Original Function 3: Counting divisible indices ========== */

/*@ predicate is_valid_params3(integer n, integer k) =
      1 <= k && k <= n && n <= 50;
*/

/*@ predicate is_valid_array3(int64_t *a, integer n) =
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
*/

/*@ lemma param_bounds3: 
      \forall integer n, integer k; 
      is_valid_params3(n, k) ==> 0 <= n && 0 <= k;
*/

int64_t func3(int64_t n, int64_t k, int64_t *a) {
    int64_t ans = 0;
    int64_t i = 0;
    bool divisible = false;
    int64_t remainder = 0;
    
    //@ assert is_valid_params3(n, k);
    //@ assert is_valid_array3(a, n);
    
    while (i < n) {
        divisible = false;
        remainder = i;
        
        while (remainder >= k) {
            remainder -= k;
        }
        
        if (remainder == 0) {
            divisible = true;
        }
        
        if (divisible) {
            ans += 1;
        }
        
        i += 1;
    }
    
    //@ assert ans >= 0;
    return ans;
}

/* ========== Original Function 4: Grid tiling calculation ========== */

/*@
    predicate is_valid_params4(integer n, integer m) =
        1 <= n && n <= 1000000000 &&
        1 <= m && m <= 1000000000;

    logic integer ans_formula(integer n, integer m) =
        2 * (n / 2 + m / 2) +
        ((n % 2 == 1 && m % 2 == 1) ? 1 : 0) +
        ((n % 2 == 1 || m % 2 == 1) && !(n % 2 == 1 && m % 2 == 1) ? 1 : 0);

    lemma ans_formula_bound:
        \forall integer n, m;
            is_valid_params4(n, m) ==> ans_formula(n, m) <= n + m;
*/

size_t func4(size_t n, size_t m) {
    size_t ans;

    //@ assert 2 * (n / 2 + m / 2) <= n + m;
    //@ assert n + m - (n / 2 + m / 2) <= n + m;

    ans = 2 * (n / 2 + m / 2);
    
    if (n % 2 == 1 && m % 2 == 1) {
        ans += 1;
    } else if (n % 2 == 1 || m % 2 == 1) {
        ans += 1;
    }

    //@ assert ans <= n + m;
    return ans;
}

/* ========== Synthesized Complex Function: Data Integrity Checker ========== */

/*@
    predicate valid_data_set(size_t N, int64_t *vec, int *unique_list, size_t unique_len,
                             int64_t n3, int64_t k3, int64_t *a3,
                             size_t n4, size_t m4) =
        valid_vec(N, vec) &&
        \valid(unique_list + (0 .. unique_len-1)) &&
        all_unique(unique_list, unique_len) &&
        unique_len <= 0x80000000 &&
        is_valid_params3(n3, k3) &&
        is_valid_array3(a3, n3) &&
        is_valid_params4(n4, m4);
*/

bool data_integrity_checker(size_t N, int64_t *vec, int *unique_list, size_t unique_len,
                            int64_t n3, int64_t k3, int64_t *a3,
                            size_t n4, size_t m4) {
    int64_t result1 = func1(N, vec);
    
    bool result2 = func2(unique_list, unique_len);
    
    int64_t result3 = func3(n3, k3, a3);
    
    size_t result4 = func4(n4, m4);
    
    //@ assert (result1 >= -1 && result1 <= (int64_t)N) && result2 == true && result3 >= 0 && result4 <= n4 + m4;
    
    return true;
}
