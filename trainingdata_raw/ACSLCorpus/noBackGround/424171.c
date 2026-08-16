/*@
    requires (1 <= (a) && (a) <= 500 &&
        1 <= (b) && (b) <= 500 &&
        1 <= (c) && (c) <= 1000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
int func(int a, int b, int c) {
    int ans;

    ans = 0;
    //@ assert ans == 0;

    if (a + b >= c) {
        ans = 1;
        //@ assert ans == 1;
    } else {
        //@ assert ans == 0;
    }

    //@ assert (ans == 1) ==> (a + b >= c);
    //@ assert (ans == 0) ==> (a + b < c);

    return ans == 1;
}
