/*@
    predicate nonneg(integer x) = x >= 0;
    predicate in_range(integer x, integer low, integer high) = low <= x && x <= high;
    predicate is_division(integer a, integer p, integer result) = result == (a * 3 + p) / 2;
*/

/*@
    logic integer compute_k(integer a, integer p) = a * 3 + p;
*/

/*@
    lemma k_nonneg: \forall integer a, p; 0 <= a <= 100 && 0 <= p <= 100 ==> compute_k(a, p) >= 0;
    lemma k_bound: \forall integer a, p; 0 <= a <= 100 && 0 <= p <= 100 ==> compute_k(a, p) <= 400;
    lemma div_bound: \forall integer a, p; 0 <= a <= 100 && 0 <= p <= 100 ==> (a * 3 + p) / 2 <= 200;
*/

/*@
    requires 0 <= a && a <= 100 && 0 <= p && p <= 100;
    ensures \result == (a * 3 + p) / 2;
*/
long func(long a, long p)
{
    long k;
    long result;
    long temp_k;
    int is_negative;
    
    k = a * 3 + p;
    result = 0;
    temp_k = k;
    is_negative = 0;
    
    //@ assert k == compute_k(a, p);
    //@ assert k >= 0;
    
    if (temp_k < 0) {
        is_negative = 1;
        temp_k = -temp_k;
    }
    
    /*@
        loop invariant 0 <= temp_k && temp_k <= k;
        loop invariant result == (k - temp_k) / 2;
        loop invariant temp_k + 2 * result == k;
        loop assigns result, temp_k;
    */
    while (temp_k >= 2) {
        result += 1;
        temp_k -= 2;
    }
    
    if (is_negative) {
        result = -result;
    }
    
    //@ assert result == (a * 3 + p) / 2;
    
    return result;
}
