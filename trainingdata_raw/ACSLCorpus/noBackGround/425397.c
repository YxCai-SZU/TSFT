/*@
    requires (1 <= (x) <= 5);
    requires (1 <= (y) <= 5);
    ensures (1 <= (x + y) <= 10);
*/
void func(int x, int y)
{
    //@ assert (1 <= (x) <= 5);
    //@ assert (1 <= (y) <= 5);
    //@ assert (1 <= (x + y) <= 10);
}
