/*@
    requires (1 <= (x) && (x) <= 179);
    ensures \result == 360 - (x * 2);
    ensures (2 <= (\result) && (\result) <= 358);
*/
int func(int x)
{
    int y;
    int z;

    y = x * 2;
    //@ assert (2 <= (y) && (y) <= 358);
    z = 360 - y;
    //@ assert (2 <= (z) && (z) <= 358);
    return z;
}
