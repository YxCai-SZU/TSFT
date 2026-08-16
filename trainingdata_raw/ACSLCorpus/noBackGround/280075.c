/*@
    requires (1 <= (N) <= 100 &&
        0 <= (A) <= (N) * (N));
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(int N, int A) {
    int x;
    int y;
    int z;
    int ans;

    //@ assert N * N <= 10000;
    x = N * N;
    y = A;
    z = 0;
    ans = 0;

    if (x == y) {
        ans = 1;
        return ans;
    } else {
        ans = 0;
    }

    //@ assert x >= y;
    return ans;
}
