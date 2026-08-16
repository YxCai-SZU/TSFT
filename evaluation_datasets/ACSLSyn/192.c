#include <stdint.h>
#include <stdbool.h>

/* First function: compute a transformed value from an integer in [1,10] */
/*@
    predicate a_in_range(integer a) = 1 <= a <= 10;
    
    logic integer func_spec(integer a) = 100 * a - 10 * (a / 10);
*/

int64_t func(uint64_t a)
{
    uint64_t result;
    int64_t result_i64;
    
    //@ assert 100 * a <= 100 * 10;
    //@ assert 10 * (a / 10) <= 10 * 10;
    
    result = 100 * a - 10 * (a / 10);
    result_i64 = (int64_t)result;
    
    //@ assert result_i64 == 100 * (int64_t)a - 10 * ((int64_t)a / 10);
    
    return result_i64;
}

/* Second function: check a validity condition on a range [a,e] with parameter k */
/*@
    predicate is_valid_range(integer a, integer b, integer c, integer d, integer e) =
        0 <= a && a < b && b < c && c < d && d < e && e <= 123;

    predicate is_valid_k(integer k) = 0 <= k && k <= 123;

    logic integer condition_holds(integer a, integer b, integer c, integer d, integer e, integer k) =
        (k >= b - a - 1 || k >= c - b - 1 || k >= d - c - 1 || k >= e - d - 1) ? 1 : 0;

    lemma condition_true_lemma:
        \forall integer a, b, c, d, e, k;
            is_valid_range(a, b, c, d, e) && is_valid_k(k) && condition_holds(a, b, c, d, e, k) == 1 ==>
            condition_holds(a, b, c, d, e, k) == 1;

    lemma condition_false_lemma:
        \forall integer a, b, c, d, e, k;
            is_valid_range(a, b, c, d, e) && is_valid_k(k) && condition_holds(a, b, c, d, e, k) == 0 ==>
            condition_holds(a, b, c, d, e, k) == 0;
*/

bool func2(int a, int b, int c, int d, int e, int k)
{
    bool result;

    //@ assert is_valid_range(a, b, c, d, e);
    //@ assert is_valid_k(k);

    if (k >= b - a - 1 || k >= c - b - 1 || k >= d - c - 1 || k >= e - d - 1)
    {
        //@ assert condition_holds(a, b, c, d, e, k) == 1;
        result = true;
    }
    else
    {
        //@ assert condition_holds(a, b, c, d, e, k) == 0;
        result = false;
    }

    //@ assert result == (condition_holds(a, b, c, d, e, k) == 1);
    return result;
}

/* Synthesized function: "Data Packet Interval Validator"
   Scenario: In a telemetry system, we receive a data packet with a header code 'a' (1-10)
   and five timestamps (a,b,c,d,e) forming a strictly increasing range [0,123].
   Parameter k is a tolerance threshold. The function validates that the transformed
   header code (via func) is non-negative and that the interval condition holds.
   High-level property: The output status correctly reflects that the packet is valid
   (transformed code non-negative AND interval condition satisfied).
*/
bool validate_packet(uint64_t a, int t0, int t1, int t2, int t3, int t4, int k)
{
    int64_t transformed;
    bool interval_ok;
    bool status;

    transformed = func(a);
    //@ assert transformed == func_spec(a);

    interval_ok = func2(t0, t1, t2, t3, t4, k);
    //@ assert interval_ok == (condition_holds(t0, t1, t2, t3, t4, k) == 1);

    if (transformed >= 0 && interval_ok)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    //@ assert status == (func_spec(a) >= 0 && condition_holds(t0, t1, t2, t3, t4, k) == 1);
    return status;
}
