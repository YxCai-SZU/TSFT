#include <stdbool.h>
#include <stdint.h>

/* First function: checks if k >= v[4] - v[0] for a 5-element vector */
/*@
    predicate valid_vector5(int *v, integer len) =
        len == 5 &&
        \forall integer i; 0 <= i < len ==> 0 <= v[i] && v[i] <= 123;

    logic integer diff(int *v) = v[4] - v[0];
*/

bool func1(int *v, int k)
{
    bool result;
    
    //@ assert valid_vector5(v, 5);
    
    if (k >= (v[4] - v[0])) {
        //@ assert k >= diff(v);
        result = true;
    } else {
        //@ assert !(k >= diff(v));
        result = false;
    }
    
    return result;
}

/* Second function: checks if v[0]*100 + v[1] >= 1000 for a 2-element vector */
/*@
    predicate valid_vector2(int *v, integer len) =
        len == 2 &&
        1 <= v[0] <= 100 &&
        0 <= v[1] <= 4111;

    logic integer compute_value(integer a, integer b) = a * 100 + b;

    predicate result_condition(integer val) = val >= 1000;
*/

bool func2(int *v)
{
    bool result = false;
    int temp = 0;

    //@ assert valid_vector2(v, 2);
    temp = v[0] * 100 + v[1];
    
    if (temp >= 1000)
    {
        result = true;
    }

    //@ assert result == (compute_value(v[0], v[1]) >= 1000);
    return result;
}

/* Third function: computes ceil(N/2) for uint64_t N */
/*@
    predicate is_valid_N(integer N) = 1 <= N && N <= 1000000;

    logic integer func_result(integer N) =
        N % 2 == 0 ? N / 2 : (integer)((uint32_t)N / 2) + 1;

    lemma func_result_bound: \forall integer N; is_valid_N(N) ==> 
        (func_result(N) == N / 2 + 1 || func_result(N) == N / 2);
*/

uint64_t func3(uint64_t N)
{
    uint64_t result;
    uint32_t N_u32;
    uint32_t two_u32;
    uint32_t half_N_u32;

    if (N % 2 == 0)
    {
        //@ assert N / 2 <= 1000000;
        result = N / 2;
    }
    else
    {
        N_u32 = (uint32_t)N;
        two_u32 = 2;
        half_N_u32 = N_u32 / two_u32;
        result = (uint64_t)(half_N_u32 + 1);
    }

    //@ assert result == func_result(N);
    return result;
}

/* Synthesized function: Network packet rate limiter
 * 
 * Real-world scenario: A network traffic management system that processes 
 * packet batches and determines if they should be rate-limited.
 * 
 * Data flow:
 * 1. func3 computes the number of packets to process from a batch size N
 * 2. func1 checks if the packet index difference (v[4]-v[0]) is within a threshold k
 * 3. func2 checks if the computed value from a 2-element vector meets a minimum threshold
 *
 * The synthesized function determines if a packet batch should be allowed 
 * based on these three checks.
 */

bool rate_limit_check(int *v5, int k, int *v2, uint64_t N)
{
    bool check1;
    bool check2;
    uint64_t check3;
    bool result;
    
    check1 = func1(v5, k);
    check2 = func2(v2);
    check3 = func3(N);
    
    result = check1 && check2 && (check3 >= 1);
    
    //@ assert result <==> (k >= diff(v5) && (compute_value(v2[0], v2[1]) >= 1000) && (func_result(N) >= 1));
    return result;
}
