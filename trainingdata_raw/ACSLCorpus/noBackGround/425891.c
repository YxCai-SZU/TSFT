/*@
    requires 0 <= a <= 100;
    requires 0 <= p <= 100;
    ensures \result >= 0;
    ensures \result <= a * 3 + p;
*/
int func(int a, int p)
{
    int total;
    int pies;
    int temp;

    total = a * 3 + p;
    pies = 0;
    temp = total;

    /*@
        loop invariant 0 <= temp <= total;
        loop invariant 0 <= pies <= total / 2;
        loop invariant temp + 2 * pies == total;
        loop invariant 0 <= a <= 100;
        loop invariant 0 <= p <= 100;
        loop assigns temp, pies;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
        pies += 1;
    }

    //@ assert pies <= a * 3 + p;

    return pies;
}
