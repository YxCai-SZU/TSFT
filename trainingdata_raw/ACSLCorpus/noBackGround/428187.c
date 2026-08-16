/*@
    requires ((1) <= (a) && (a) <= (500));
    requires ((1) <= (b) && (b) <= (500));
    requires ((1) <= (c) && (c) <= (1000));
    ensures \result == (a + b >= c);
*/
int func(int a, int b, int c)
{
    //@ assert ((1) <= (a) && (a) <= (500));
    //@ assert ((1) <= (b) && (b) <= (500));
    //@ assert ((1) <= (c) && (c) <= (1000));
    return a + b >= c;
}
