/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a + b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int result = 0;

    result += a;
    //@ assert result == a;

    result += b;
    //@ assert result == a + b;

    result += c;
    //@ assert result == a + b + c;

    result += d;
    //@ assert result == a + b + c + d;

    return result;
}
