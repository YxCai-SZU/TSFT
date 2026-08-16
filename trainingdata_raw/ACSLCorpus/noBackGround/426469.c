/*@
    requires (1 <= (a) && (a) <= 10) && (1 <= (b) && (b) <= 10) && (1 <= (c) && (c) <= 10);
    ensures \result == 1 <==> ((a) < (b) && (b) < (c));
*/
int func(int a, int b, int c)
{
    int res;

    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert (1 <= (b) && (b) <= 10);
    //@ assert (1 <= (c) && (c) <= 10);

    res = (a < b && b < c) ? 1 : 0;
    
    //@ assert res == 1 <==> ((a) < (b) && (b) < (c));
    return res;
}
