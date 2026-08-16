/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int sum1;
    int sum2;
    int sum3;
    int ans;

    //@ assert a + b <= 200;
    sum1 = a + b;

    //@ assert b + c <= 200;
    sum2 = b + c;

    //@ assert c + a <= 200;
    sum3 = c + a;

    ans = 0;
    if (sum1 == c || sum2 == a || sum3 == b)
    {
        ans = 1;
    }

    //@ assert ans == (a + b == c || b + c == a || c + a == b);
    return ans;
}
