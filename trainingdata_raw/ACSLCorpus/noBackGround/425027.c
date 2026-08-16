/*@
    requires (0 <= (n) && (n) <= 1);
    ensures \result == ((n) == 1 ? 0 : 1);
    ensures (n == 1 ==> \result == 0) && (n == 0 ==> \result == 1);
*/
int func(int n)
{
    int ans;
    int i;

    //@ assert (0 <= (n) && (n) <= 1);

    if (n == 1) {
        ans = 0;
    } else {
        ans = 1;
    }

    //@ assert (n == 1 ==> ans == 0) && (n == 0 ==> ans == 1);

    i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop assigns i;
        loop variant 10 - i;
    */
    while (i < 10) {
        // Do something in the loop
        i = i + 1;
    }

    //@ assert ans == ((n) == 1 ? 0 : 1);
    return ans;
}

int main(void)
{
    return 0;
}
