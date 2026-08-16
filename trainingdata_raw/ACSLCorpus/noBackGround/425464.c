/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b + 1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    int i;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ans = a;
    i = 0;

    /*@
        loop invariant 0 <= i <= b;
        loop invariant ans >= 0;
        loop invariant ans <= ((a) + (i) + 1);
        loop assigns ans, i;
        loop variant b - i;
    */
    while (i < b)
    {
        //@ assert ans <= ((a) + (i) + 1);
        ans += 1;
        i += 1;
        //@ assert ans <= ((a) + (i) + 1);
    }

    //@ assert ans <= a + b + 1;
    return ans;
}
