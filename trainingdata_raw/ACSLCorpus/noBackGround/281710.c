/*@
    requires (-100 <= (x) && (x) <= 100);
    ensures \result == ((x) * 3);
    assigns \nothing;
*/
long func(long x)
{
    long ans;
    //@ assert (-100 <= (x) && (x) <= 100);
    ans = x * 3;
    //@ assert ans == ((x) * 3);
    return ans;
}

int main()
{
    long result;
    result = func(5);
    //@ assert result == 15;
    return 0;
}
