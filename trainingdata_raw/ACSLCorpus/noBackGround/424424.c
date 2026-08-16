/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == (((a) - (b)) < (c) ? (c) - ((a) - (b)) : 0);
*/
int func(int a, int b, int c)
{
    int remain;
    int ans;

    remain = a - b;
    //@ assert remain == a - b;

    if (remain < c) {
        ans = c - remain;
    } else {
        ans = 0;
    }

    //@ assert ans >= 0;
    //@ assert ans <= c;
    //@ assert ans == (((a) - (b)) < (c) ? (c) - ((a) - (b)) : 0);

    return ans;
}
