/*@
    requires 1 <= x && x <= 100;
    requires 1 <= y && y <= 100;
    requires 1 <= z && z <= 100;
    ensures \result >= 1;
    ensures \result <= x || \result <= y || \result <= z;
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    int ret = 2147483647;

    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert (1 <= (y) && (y) <= 100);
    //@ assert (1 <= (z) && (z) <= 100);

    if (x < ret)
    {
        ret = x;
    }

    if (y < ret)
    {
        ret = y;
    }

    if (z < ret)
    {
        ret = z;
    }

    //@ assert ret >= 1;
    //@ assert ret <= x || ret <= y || ret <= z;

    return ret;
}
