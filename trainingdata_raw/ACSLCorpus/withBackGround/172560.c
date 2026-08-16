/*@
    predicate is_divisible(integer i) = (i + 1) % 3 == 0;
    logic integer count_non_divisible(integer n) = n - (n / 3);
    lemma count_bounds: \forall integer n; 1 <= n <= 100 ==> 0 <= count_non_divisible(n) <= n;
*/

/*@
    requires 1 <= n <= 100;
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n) {
    int res = 0;
    int i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= res <= i;
        loop invariant res <= n;
        loop invariant 1 <= n <= 100;
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        int divisible = 0;
        int j = 0;
        /*@
            loop invariant 0 <= j <= 3;
            loop invariant 0 <= res <= i;
            loop invariant res <= n;
            loop invariant 1 <= n <= 100;
            loop assigns j, divisible;
            loop variant 3 - j;
        */
        while (j < 3) {
            if ((i + 1) % 3 == 0) {
                divisible = 1;
            }
            j++;
        }
        if (!divisible) {
            res++;
        }
        i++;
    }
    return res;
}
