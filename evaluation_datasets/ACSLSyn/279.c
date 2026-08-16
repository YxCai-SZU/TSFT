#include <stdbool.h>
#include <stddef.h>

/* ==================== Original function 1 (with ACSL) ==================== */

/*@
    predicate valid_array(unsigned long long *a, integer len) =
        len == 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= a[i] && a[i] <= 13;

    logic integer array_sum(unsigned long long *a, integer len) =
        len <= 0 ? 0 : (len == 1 ? a[0] : (len == 2 ? a[0] + a[1] : a[0] + a[1] + a[2]));

    lemma sum_bounds:
        \forall unsigned long long *a, integer len;
        valid_array(a, len) ==> 3 <= array_sum(a, len) && array_sum(a, len) <= 39;
*/

bool func1(unsigned long long *a) {
    unsigned long long res = 0;
    size_t i = 0;

    while (i < 3) {
        //@ assert 0 <= i < 3;
        //@ assert 1 <= a[i] && a[i] <= 13;
        res += a[i];
        i++;
    }

    //@ assert res == array_sum(a, 3);
    return res >= 22;
}

/* ==================== Original function 2 (with ACSL) ==================== */

/*@
    predicate product_leq_100M(integer a, integer b) =
        1 <= a <= 10000 && 1 <= b <= 10000 ==> a * b <= 100000000;

    lemma product_bound_A_B:
        \forall integer A, B;
            1 <= A <= 10000 && 1 <= B <= 10000 ==> A * B <= 100000000;

    lemma product_bound_C_D:
        \forall integer C, D;
            1 <= C <= 10000 && 1 <= D <= 10000 ==> C * D <= 100000000;
*/

bool func2(int A, int B, int C, int D)
{
    bool result;
    long long product_AB;
    long long product_CD;
    
    //@ assert product_leq_100M(A, B);
    //@ assert product_leq_100M(C, D);
    
    product_AB = (long long)A * B;
    product_CD = (long long)C * D;
    
    if (product_AB > product_CD)
    {
        //@ assert product_AB > product_CD;
        result = true;
    }
    else if (product_AB == product_CD)
    {
        if (A <= C && B <= D)
        {
            //@ assert product_AB == product_CD;
            //@ assert A <= C && B <= D;
            result = true;
        }
        else
        {
            //@ assert product_AB == product_CD;
            //@ assert !(A <= C && B <= D);
            result = false;
        }
    }
    else
    {
        //@ assert product_AB < product_CD;
        result = false;
    }
    
    return result;
}

/* ==================== Original function 3 (with ACSL) ==================== */

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10000;
    predicate b_in_range(integer b) = 1 <= b <= 10000;
    predicate c_in_range(integer c) = 1 <= c <= 10000;
    predicate d_in_range(integer d) = 1 <= d <= 10000;
    predicate a_le_b(integer a, integer b) = a <= b;
    predicate c_le_d(integer c, integer d) = c <= d;
    predicate result_condition(integer a, integer b, integer c, integer d, bool result) =
        result == (b < c || a <= d);
*/

bool func3(long a, long b, long c, long d)
{
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert c_in_range(c);
    //@ assert d_in_range(d);
    //@ assert a_le_b(a, b);
    //@ assert c_le_d(c, d);
    return b < c || a <= d;
}

/* ==================== Synthesized function (real-world scenario: card game scoring system) ==================== */

/*@
    predicate is_dominant_hand(unsigned long long *a, int A, int B, int C, int D,
                                long p, long q, long r, long s) =
        (array_sum(a, 3) >= 22) &&
        (A * B > C * D || (A * B == C * D && A <= C && B <= D)) &&
        (q < r || p <= s);
*/

bool synthesized_func(unsigned long long *a, int A, int B, int C, int D,
                      long p, long q, long r, long s)
{
    bool step1 = func1(a);
    bool step2 = func2(A, B, C, D);
    bool step3 = func3(p, q, r, s);

    bool final_result = step1 && step2 && step3;

    //@ assert final_result <==> is_dominant_hand(a, A, B, C, D, p, q, r, s);

    return final_result;
}
