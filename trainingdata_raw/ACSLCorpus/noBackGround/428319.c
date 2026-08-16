/*@
    requires (0 <= (x) && (x) <= 1);
    ensures \result == ((x) == 0 ? 1 : 0);
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
*/
int func(int x)
{
    int result;
    int i;

    //@ assert (0 <= (x) && (x) <= 1);
    result = (x == 0) ? 1 : 0;
    //@ assert result == ((x) == 0 ? 1 : 0);

    i = 0;
    /*@
        loop invariant 0 <= i <= 1;
        loop invariant (0 <= (x) && (x) <= 1);
        loop invariant result == ((x) == 0 ? 1 : 0);
        loop assigns i;
    */
    while (i < 1)
    {
        //@ assert i < 1;
        i = i + 1;
        //@ assert i <= 1;
    }
    //@ assert i == 1;
    //@ assert result == ((x) == 0 ? 1 : 0);

    return result;
}

int main()
{
    return 0;
}
