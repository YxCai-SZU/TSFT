/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == 1 ==> (a + b == c || a + c == b || b + c == a);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert a >= 0 && b >= 0 && c >= 0;
    //@ assert a <= 100 && b <= 100 && c <= 100;
    return (a + b == c || a + c == b || b + c == a);
}

int main()
{
    return 0;
}
