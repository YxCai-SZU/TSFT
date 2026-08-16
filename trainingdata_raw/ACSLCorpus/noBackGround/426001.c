/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == 1 <==> ((a) < (b) && (b) < (c));
 */
int func(int a, int b, int c)
{
    //@ assert ((a) < (b) && (b) < (c)) ==> ((a) < (b) && (b) < (c));
    return (a < b && b < c) ? 1 : 0;
}
