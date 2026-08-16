/*@
    predicate is_valid_range(integer n) = 1 <= n && n <= 1000000000;
    predicate half_invariant(integer n, integer temp_n, integer count) =
        0 <= temp_n && temp_n <= n &&
        temp_n == n - 2 * count &&
        0 <= count && count <= n / 2;
    predicate quarter_invariant(integer half_n, integer temp_half_n, integer count) =
        0 <= temp_half_n && temp_half_n <= half_n &&
        temp_half_n == half_n - 2 * count &&
        0 <= count && count <= half_n / 2;
    lemma half_correctness: \forall integer n, half_n; is_valid_range(n) && half_n == n / 2 ==> half_n >= 0 && half_n <= n;
    lemma quarter_correctness: \forall integer n, half_n, quarter_n; is_valid_range(n) && half_n == n / 2 && quarter_n == half_n / 2 ==> quarter_n >= 0 && quarter_n <= half_n;
    lemma result_correctness: \forall integer n, half_n, quarter_n; is_valid_range(n) && half_n == n / 2 && quarter_n == half_n / 2 ==> half_n - quarter_n >= 0 && half_n - quarter_n <= n;
*/

/*@
    requires is_valid_range(n);
    ensures \result >= 0 && \result <= n;
    ensures \result == (n / 2) - (n / 2) / 2;
*/
long func(long n) {
    long half_n;
    long quarter_n;
    long ans;
    
    // Calculate half_n = n / 2
    if (n >= 0) {
        long count = 0;
        long temp_n = n;
        /*@
            loop invariant half_invariant(n, temp_n, count);
            loop assigns temp_n, count;
            loop variant temp_n;
        */
        while (temp_n >= 2) {
            temp_n -= 2;
            count += 1;
        }
        half_n = count;
    } else {
        long count = 0;
        long temp_n = n;
        /*@
            loop invariant n <= temp_n && temp_n <= 0;
            loop invariant temp_n == n - 2 * count;
            loop invariant 0 <= count && count <= n / 2;
            loop assigns temp_n, count;
            loop variant -temp_n;
        */
        while (temp_n <= -2) {
            temp_n += 2;
            count -= 1;
        }
        half_n = count;
    }
    
    //@ assert half_n == n / 2;
    
    // Calculate quarter_n = half_n / 2
    if (half_n >= 0) {
        long count = 0;
        long temp_half_n = half_n;
        /*@
            loop invariant quarter_invariant(half_n, temp_half_n, count);
            loop assigns temp_half_n, count;
            loop variant temp_half_n;
        */
        while (temp_half_n >= 2) {
            temp_half_n -= 2;
            count += 1;
        }
        quarter_n = count;
    } else {
        long count = 0;
        long temp_half_n = half_n;
        /*@
            loop invariant half_n <= temp_half_n && temp_half_n <= 0;
            loop invariant temp_half_n == half_n - 2 * count;
            loop invariant 0 <= count && count <= half_n / 2;
            loop assigns temp_half_n, count;
            loop variant -temp_half_n;
        */
        while (temp_half_n <= -2) {
            temp_half_n += 2;
            count -= 1;
        }
        quarter_n = count;
    }
    
    //@ assert quarter_n == half_n / 2;
    
    ans = half_n - quarter_n;
    //@ assert ans == (n / 2) - (n / 2) / 2;
    return ans;
}

int main() {
    return 0;
}
