/*@ requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 3);
    ensures \result == 1 || \result == 2 || \result == 3;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans;
    int i;

    if (a >= b && a >= c) {
        ans = 1;
    } else if (b >= a && b >= c) {
        ans = 2;
    } else {
        ans = 3;
    }

    //@ assert ((ans) == 1 || (ans) == 2 || (ans) == 3);

    i = 0;
    /*@ loop invariant 0 <= i <= k;
        loop invariant ((ans) == 1 || (ans) == 2 || (ans) == 3);
        loop assigns i, ans;
    */
    while (i < k) {
        if (ans == 1) {
            if (b >= a) {
                ans = 2;
            }
        } else if (ans == 2) {
            if (a >= b) {
                ans = 1;
            } else if (c >= b) {
                ans = 3;
            }
        } else {
            if (a >= c) {
                ans = 1;
            } else if (b >= c) {
                ans = 2;
            }
        }
        //@ assert ((ans) == 1 || (ans) == 2 || (ans) == 3);
        i += 1;
    }

    return ans;
}
