/*@
    requires 0 <= a <= 10;
    requires 0 <= b <= 10;
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;
    //@ assert ((a) >= 0) && ((b) >= 0);
    //@ ghost mul_comm_unnat: a * b == b * a;
    ans = a * b;
    //@ assert ans == a * b;
    return ans;
}
