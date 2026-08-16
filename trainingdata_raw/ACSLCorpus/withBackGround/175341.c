/*@
    predicate bounds(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;
*/

/*@
    requires \valid(result);
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    assigns *result;
    ensures *result == (n == m);
*/
void func(int n, int m, int *result) {
    int start;
    int i;
    int ans;

    start = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= 2000;
        loop invariant start == 0;
        loop assigns i;
        loop variant 2000 - i;
    */
    while (i < 2000) {
        i = i + 1;
    }

    //@ assert bounds(n, m);

    if (n == m) {
        ans = 1;
    } else {
        ans = 0;
    }

    //@ assert (ans == 1) ==> (n == m);
    //@ assert (ans == 0) ==> (n != m);

    *result = (ans == 1);
}
