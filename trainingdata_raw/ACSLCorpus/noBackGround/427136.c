/*@
    requires n >= 1 && n <= 100;
    requires x >= 1 && x <= 10000;
    requires \valid(lengths + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> (lengths)[i] >= 1 && (lengths)[i] <= 100);
    ensures \result >= 1 && \result <= n + 1;
    ensures \result == 1 || x >= lengths[\result - 2];
    assigns \nothing;
*/
int func(int n, int x, int *lengths)
{
    int di = 0;
    int i = 1;

    /*@
        loop invariant (1 <= (i) && (i) <= (n) + 1 &&
        0 <= (di) && (di) <= (x) &&
        ((i) > 1 ==> (x) >= (lengths)[(i) - 2]) &&
        (((n)) >= 1 && ((n)) <= 100 &&
        \forall integer i; 0 <= i < ((n)) ==> ((lengths))[i] >= 1 && ((lengths))[i] <= 100) &&
        (x) >= 1 && (x) <= 10000);
        loop assigns i, di;
        loop variant n - i;
    */
    while (i <= n)
    {
        int l = lengths[i - 1];
        di += l;

        if (x < di)
        {
            //@ assert i >= 1 && i <= n + 1;
            return i;
        }
        else if (i == n)
        {
            //@ assert i + 1 >= 1 && i + 1 <= n + 1;
            return i + 1;
        }

        //@ assert i >= 1 && i < n;
        i += 1;
    }

    //@ assert n >= 1 && n <= 100;
    return n + 1;
}
