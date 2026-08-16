/*@
    requires (-1290 <= (n) <= 1290);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
long long mainfn(long long n)
{
    long long result;
    //@ assert (-1290 <= (n) <= 1290);
    //@ assert -1664100 <= n * n <= 1664100;
    //@ assert -2146689000 <= n * n * n <= 2146689000;
    result = n * n * n;
    //@ assert result == ((n) * (n) * (n));
    return result;
}
