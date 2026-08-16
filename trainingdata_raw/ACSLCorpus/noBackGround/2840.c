/*@
    requires 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;
    ensures \result <==> a < b && b < c;
*/
int func(int a, int b, int c)
{
    //@ assert a < b && b < c <==> a < b && b < c;
    return (a < b && b < c) ? 1 : 0;
}
