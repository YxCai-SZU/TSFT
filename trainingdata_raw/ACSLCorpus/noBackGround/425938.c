/*@
    requires (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123 &&
        0 <= (k) && (k) <= 123);
    ensures \result == (e - a <= k);
*/
int func(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int count = 0;
    unsigned int i = a;

    /*@
        loop invariant (0 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) < (e) && (e) <= 123 &&
        0 <= (k) && (k) <= 123);
        loop invariant a <= i && i <= e;
        loop invariant count == i - a;
        loop invariant count <= e - a;
        loop assigns i, count;
    */
    while (i < e)
    {
        //@ assert count == i - a;
        count += 1;
        i += 1;
    }

    //@ assert count == e - a;
    return count <= k;
}
