#include <stdbool.h>

/* Original function 1: condition check */
/*@
    predicate condition_holds(integer n, integer m, integer k) =
        n == k || m > n - k;
 */

bool func1(int n, int m, int k)
{
    bool res;

    //@ assert 1 <= n && n <= 100000;
    //@ assert 1 <= m && m <= 100000;
    //@ assert 0 <= k && k <= n;

    if (n == k)
    {
        //@ assert condition_holds(n, m, k);
        res = true;
    }
    else if (m > n - k)
    {
        //@ assert condition_holds(n, m, k);
        res = true;
    }
    else
    {
        //@ assert !condition_holds(n, m, k);
        res = false;
    }

    //@ assert res == true <==> condition_holds(n, m, k);
    return res;
}

/* Original function 2: compute result based on input */
/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        c <= a - b ? b + c : a;
*/

int func2(int a, int b, int c) {
    int ans = 0;
    
    //@ assert valid_input(a, b, c);
    
    if (c <= a - b) {
        ans = b + c;
        //@ assert ans == b + c;
    } else {
        ans = a;
        //@ assert ans == a;
    }
    
    //@ assert ans == compute_result(a, b, c);
    return ans;
}

/* Original function 3: compute with constraints */
/*@
    predicate nonneg_params(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c && 1 <= k &&
        k <= a + b + c && a + b + c <= 2000000000;

    logic integer compute_ans(integer a, integer b, integer c, integer k) =
        (k < a ? k : a) - ((k - (k < a ? k : a)) - ((k - (k < a ? k : a)) < b ? (k - (k < a ? k : a)) : b));
*/

int func3(int a, int b, int c, int k)
{
    int a_var = a;
    int k_var = k;
    int k2_var = 0;
    int ans = 0;

    if (k_var < a_var) {
        a_var = k_var;
    }
    //@ assert a_var == (k < a ? k : a);

    k_var -= a_var;
    //@ assert k_var == k - (k < a ? k : a);

    if (k_var < b) {
        k2_var = k_var;
    } else {
        k2_var = b;
    }
    //@ assert k2_var == (k_var < b ? k_var : b);

    ans = a_var - (k_var - k2_var);
    //@ assert ans == compute_ans(a, b, c, k);

    return ans;
}

/* Original function 4: simple calculation */
/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer calculate_result(integer r) = 6 * r;
*/

long func4(long r)
{
    long pi = 3;
    long result;

    //@ assert pi == 3;
    result = 2 * r * pi;

    //@ assert result == 6 * r;
    return result;
}

/* Synthesized function: Resource Allocation and Verification System
   Scenario: A system that allocates resources (e.g., memory blocks) to processes.
   Data flow:
     1. Check if allocation condition is met based on available resources (n), requested amount (m), and threshold (k)
     2. If condition holds, compute an allocation size using process priority (a), base allocation (b), and adjustment (c)
     3. Then compute remaining resources after allocation using total (a), used (b), free (c), and original request (k)
     4. Finally, calculate a verification factor based on the remaining resources (r)
   The final assertion verifies that the verification factor is a multiple of 6, ensuring system integrity.
*/

long synthesized_func(int n, int m, int k, int a, int b, int c, int a2, int b2, int c2, int k2, long r)
{
    bool condition = func1(n, m, k);
    int allocation_size;
    int remaining;
    long verification_factor;

    if (condition) {
        allocation_size = func2(a, b, c);
    } else {
        allocation_size = 0;
    }

    remaining = func3(a2, b2, c2, k2);

    verification_factor = func4(r);

    //@ assert verification_factor % 6 == 0;
    return verification_factor;
}
