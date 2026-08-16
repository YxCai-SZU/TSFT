/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures \result >= 0;
    ensures \result == a * b || \result == a + b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int max;
    int ans;

    //@ assert (1 <= (a) <= 20);
    //@ assert (1 <= (b) <= 20);

    if (a > b) {
        max = a;
    } else {
        max = b;
    }

    //@ assert (1 <= (max) <= 20);

    if (a == max && b == max) {
        //@ assert a * b >= 0;
        //@ assert a * b <= 400;
        ans = a * b;
    } else {
        ans = a + b;
    }

    return ans;
}
