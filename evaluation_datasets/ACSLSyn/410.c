#include <stdbool.h>
#include <stddef.h>

/* ===== First function: count_elements_above_threshold ===== */
/*@ predicate valid_params(integer n, integer k) =
      n >= 1 && n <= 100000 &&
      k >= 1 && k <= 500;

   predicate valid_array_int(integer n, int *h) =
      \valid(h + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

int count_elements_above_threshold(int n, int k, int *h) {
    int num = 0;
    int index = 0;
    
    while (index < n) {
        //@ assert 0 <= index < n;
        if (h[index] >= k) {
            num += 1;
        }
        index += 1;
    }
    return num;
}

/* ===== Second function: compute_penalty ===== */
/*@
    predicate x_in_range(integer x) = 1 <= x && x <= 100;
    predicate y_in_range(integer y) = 1 <= y && y <= 100;
    predicate y_even(integer y) = y % 2 == 0;
*/

long compute_penalty(long x, long y) {
    long ans = 0;
    
    if (x <= 3 * y) {
        ans += (x - y) * 2;
        
        if (3 * y - x > 0) {
            ans += 3 * y - x;
        } else {
            ans += 0;
        }
    } else {
        ans += y * 2 + 1;
    }
    
    if (ans > 200) {
        ans = 200;
    }
    
    return ans;
}

/* ===== Third function: is_unique_minimum ===== */
/*@
    predicate valid_array_size_t(integer N, size_t *A) =
        2 <= N <= 1000000 &&
        \valid(A + (0 .. N-1)) &&
        \forall integer j; 0 <= j < N ==> A[j] > 0 && A[j] <= 1000000000;
*/

int is_unique_minimum(size_t N, const size_t *A) {
    size_t m = 1000000;
    size_t i = 0;
    size_t c = 0;
    int result;
    
    while (i < N) {
        //@ assert 0 <= i < N;
        if (A[i] < m) {
            m = A[i];
        }
        i += 1;
    }
    
    i = 0;
    while (i < N) {
        //@ assert 0 <= i < N;
        if (A[i] == m) {
            c += 1;
        }
        i += 1;
    }
    
    if (c == 1) {
        result = 1;
    } else {
        result = 0;
    }
    
    return result;
}

/* ===== Fourth function: can_distribute ===== */
/*@ predicate can_distribute_condition(integer a, integer b, integer c) =
      (a + b + c) % 2 == 0;
*/

/*@ predicate cannot_distribute_condition(integer a, integer b, integer c) =
      (a + b + c) % 2 != 0 ||
      (a % 2 != b % 2 || a % 2 != c % 2 || b % 2 != c % 2);
*/

bool can_distribute(unsigned long a, unsigned long b, unsigned long c)
{
    unsigned long sum;
    bool can_distribute_flag;

    sum = a + b + c;
    can_distribute_flag = (sum % 2 == 0);

    return can_distribute_flag;
}

/* ===== Synthesized function: resource_allocator ===== */
int resource_allocator(int n, int k, int *h, 
                       long x, long y,
                       size_t N, const size_t *A,
                       unsigned long a, unsigned long b, unsigned long c)
{
    int count_servers;
    long penalty;
    int unique_min;
    bool power_ok;
    int allocation_feasible;
    
    count_servers = count_elements_above_threshold(n, k, h);
    
    penalty = compute_penalty(x, y);
    
    unique_min = is_unique_minimum(N, A);
    
    power_ok = can_distribute(a, b, c);
    
    if (count_servers > 0 && penalty <= 100 && unique_min == 1 && power_ok == true) {
        allocation_feasible = 1;
    } else {
        allocation_feasible = 0;
    }
    
    return allocation_feasible;
}
