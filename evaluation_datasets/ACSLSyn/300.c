#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

/* ========== First function (func) ========== */
/*@
    predicate is_in_range(integer x) = 3 <= x && x <= 20;

    logic integer max(integer a, integer b) = a > b ? a : b;
    logic integer min(integer a, integer b) = a < b ? a : b;

    lemma diff_one_implies_sum:
        \forall integer a, b;
            is_in_range(a) && is_in_range(b) && max(a,b) - min(a,b) == 1 ==>
            max(a,b) + min(a,b) == a + b;

    lemma diff_not_one_implies_double_max_minus_one:
        \forall integer a, b;
            is_in_range(a) && is_in_range(b) && max(a,b) - min(a,b) != 1 ==>
            2 * max(a,b) - 1 == 2 * a - 1 || 2 * max(a,b) - 1 == 2 * b - 1;
*/

int func(int a, int b)
{
    int max_value;
    int min_value;
    int result;

    if (a > b)
    {
        max_value = a;
        min_value = b;
    }
    else
    {
        max_value = b;
        min_value = a;
    }

    //@ assert max_value == max(a, b);
    //@ assert min_value == min(a, b);

    if (max_value - min_value == 1)
    {
        //@ assert max_value - min_value == 1;
        result = max_value + min_value;
        //@ assert result == a + b;
    }
    else
    {
        //@ assert max_value - min_value != 1;
        result = 2 * max_value - 1;
        //@ assert result == 2 * a - 1 || result == 2 * b - 1;
    }

    return result;
}

/* ========== Second function (func2) ========== */
/*@ predicate is_valid_array(long N, long *p) =
      N >= 1 && N <= 200000 &&
      \valid(p + (0 .. N-1)) &&
      \forall integer i; 0 <= i < N ==> p[i] >= 1 && p[i] <= N &&
      \forall integer i, j; 0 <= i < j < N ==> p[i] != p[j];
*/

/*@ lemma distinct_elements_lemma:
      \forall long N, long *p;
      is_valid_array(N, p) ==>
      \forall integer i, j; 0 <= i < j < N ==> p[i] != p[j];
*/

/*@ lemma bounds_lemma:
      \forall long N, long *p;
      is_valid_array(N, p) ==>
      \forall integer i; 0 <= i < N ==> p[i] >= 1 && p[i] <= N;
*/

long func2(long N, long *p)
{
    long res;
    long i;
    long min_bound;
    
    res = 1;
    i = 1;
    min_bound = p[0];
    
    //@ assert is_valid_array(N, p);
    
    while (i < N) {
        long p_i;
        
        p_i = p[i];
        
        //@ assert p_i >= 1 && p_i <= N;
        
        if (p_i <= min_bound) {
            min_bound = p_i;
            res += 1;
        }
        
        i += 1;
    }
    
    //@ assert res >= 1 && res <= N;
    return res;
}

/* ========== Third function (func3) ========== */
/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer mod_result(integer n) = (1000 - n % 1000) % 1000;

    lemma mod_result_bounds:
        \forall integer n; is_valid_n(n) ==> 0 <= mod_result(n) && mod_result(n) < 1000;

    lemma unsigned_conversion_lemma:
        \forall integer n; is_valid_n(n) ==> (unsigned int)(n >= 0 ? n : -n) == (unsigned int)(n >= 0 ? n : -n);
*/

int func3(int n)
{
    unsigned int n_unsigned;
    unsigned int result_unsigned;
    int result;

    n_unsigned = (n >= 0) ? (unsigned int)n : (unsigned int)(-n);
    result_unsigned = (1000 - n_unsigned % 1000) % 1000;
    //@ assert result_unsigned == (1000 - n_unsigned % 1000) % 1000;

    result = (int)result_unsigned;
    return result;
}

/* ========== Synthesized function: process_packet ========== */
/* Scenario: Network packet processing.
   Data flow:
   1. Extract two header fields (a,b) from a packet, each in [3,20], compute a combined value v1 using func.
   2. Use v1 as size to query a routing table (array p of length N, with valid permutation property), get a count v2 using func2.
   3. Use v2 as a modulo index to compute a final checksum offset v3 using func3.
   The final assertion ensures the output is a valid modulo index in [0,999].
*/

int process_packet(int a, int b, long N, long *p)
{
    int v1, v2, v3;

    v1 = func(a, b);
    //@ assert v1 == a + b || v1 == 2 * a - 1 || v1 == 2 * b - 1;

    v2 = (int)func2(N, p);
    //@ assert 1 <= v2 && v2 <= N;

    v3 = func3(v2);
    //@ assert v3 >= 0 && v3 < 1000;

    //@ assert 0 <= v3 && v3 < 1000;

    return v3;
}
