/*@
    requires ((a) + (b) == (c));
    ensures ((a) + (b) <= (c) + 1);
*/
void example_7(int a, int b, int c)
{
    //@ assert a + b == c;
    //@ assert a + b <= c;
    //@ assert a + b <= c + 1;
    //@ assert c <= c + 1;
}
