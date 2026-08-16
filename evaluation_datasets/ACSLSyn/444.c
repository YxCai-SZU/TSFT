/* ============================================================
   Scenario: Network Packet Validation and Processing
   Data Flow:
   - Given a packet index i and total N packets, compute a 
     position j = N-i+1 (used in reordering).
   - Compute the absolute value of j (for offset calculation).
   - Check if the absolute value satisfies a modulo condition 
     (packet validity condition).
   - Finally, verify that the packet is even-numbered when 
     certain conditions hold (high-level property).
   ============================================================ */

#include <stdint.h>
#include <stdbool.h>

/* ---------- Original func1 (packet position computation) ---------- */
/*@
    predicate valid_params(integer N, integer i) =
        1 <= N <= 100 && 1 <= i <= N;
    
    logic integer compute_j(integer N, integer i) = N - i + 1;
    
    lemma j_bounds: \forall integer N, i; 
        valid_params(N, i) ==> 1 <= compute_j(N, i) <= N;
*/

int func1(int N, int i) {
    int ans;
    int k;
    int l;
    
    //@ assert valid_params(N, i);
    ans = N - i + 1;
    
    //@ assert 1 <= ans <= N;
    
    k = 0;
    while (k < N) {
        k = k + 1;
        //@ assert k <= N;
        if (k == ans) {
            break;
        }
    }
    
    //@ assert k == ans || k == N;
    
    l = 0;
    while (l < N) {
        l = l + 1;
        //@ assert l <= N;
        if (l == ans) {
            //@ assert l == compute_j(N, i);
            return ans;
        }
    }
    
    //@ assert l == N;
    //@ assert ans == compute_j(N, i);
    return ans;
}

/* ---------- Original func2 (absolute value) ---------- */
/*@
    predicate is_abs(integer x, integer r) =
        r >= 0 && (r == x || r == -x);
 */

int64_t func2(int64_t x)
{
    int64_t result;
    result = x;
    //@ assert result == x;
    if (x < 0)
    {
        result = -x;
        //@ assert result == -x;
    }
    //@ assert is_abs(x, result);
    return result;
}

/* ---------- Original func3 (modulo condition check) ---------- */
/*@
    predicate is_valid_params(integer n, integer k) =
        1 <= n && n <= 100 && 1 <= k && k <= 100;

    logic integer mod3(integer n) = n % 3;

    predicate condition_holds(integer n, integer k) =
        mod3(n) == 0 || mod3(n) + k >= 3;

    lemma mod3_range: \forall integer n; 1 <= n <= 100 ==> 0 <= mod3(n) <= 2;
    lemma condition_lemma: \forall integer n, k; 
        is_valid_params(n, k) ==> (condition_holds(n, k) <==> (mod3(n) == 0 || mod3(n) + k >= 3));
*/

bool func3(unsigned int n, unsigned int k) {
    unsigned int mod_val;
    bool result;
    
    mod_val = n % 3;
    //@ assert mod_val == mod3(n);
    
    //@ assert 0 <= mod_val <= 2;
    
    result = (mod_val == 0) || (mod_val + k >= 3);
    //@ assert result <==> condition_holds(n, k);
    
    return result;
}

/* ---------- Original func4 (even/odd check) ---------- */
/*@ predicate is_even_spec(integer x) = x % 2 == 0; */
/*@ predicate is_odd_spec(integer x) = x % 2 != 0; */

bool is_even(unsigned int x) {
    unsigned int temp = x;
    
    while (temp >= 2) {
        temp -= 2;
    }
    
    //@ assert temp == 0 || temp == 1;
    return temp == 0;
}

bool is_odd(unsigned int x) {
    unsigned int temp = x;
    
    while (temp >= 2) {
        temp -= 2;
    }
    
    //@ assert temp == 0 || temp == 1;
    return temp != 0;
}

bool higher_order_fn(unsigned int x) {
    //@ assert 0 <= x < 1000000000;
    return is_even(x);
}

/* ---------- Synthesized Complex Function ---------- */
int complex_packet_validation(int N, int i) {
    int j = func1(N, i);
    //@ assert j == N - i + 1;
    
    int64_t j_abs = func2((int64_t)j);
    //@ assert j_abs >= 0 && (j_abs == j || j_abs == -j);
    
    bool cond = func3((unsigned int)j_abs, (unsigned int)i);
    //@ assert cond <==> ((j_abs % 3 == 0) || ((j_abs % 3) + i >= 3));
    
    bool result;
    if (cond) {
        result = is_even((unsigned int)j);
        //@ assert result == (j % 2 == 0);
    } else {
        result = is_odd((unsigned int)j);
        //@ assert result == (j % 2 != 0);
    }
    
    //@ assert \let jj = N - i + 1; \let abs_jj = (jj >= 0 ? jj : -jj); \let condd = ((abs_jj % 3 == 0) || (abs_jj % 3 + (unsigned int)i >= 3)); (result == 1) <==> (condd ? (jj % 2 == 0) : (jj % 2 != 0));
    
    return result ? 1 : 0;
}
