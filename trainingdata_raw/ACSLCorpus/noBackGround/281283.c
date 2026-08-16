/*@
    requires ((0) <= (a) <= (100));
    requires ((0) <= (p) <= (100));
    ensures ((\result) >= 0);
    ensures \result == (((3 * (a) + (p))) / 2);
*/
int func(int a, int p)
{
    int sum;
    int pies;
    int temp_sum;

    sum = 3 * a + p;
    pies = 0;
    temp_sum = sum;

    /*@
        loop invariant ((0) <= (temp_sum) <= (sum));
        loop invariant sum == (3 * (a) + (p));
        loop invariant ((pies) >= 0);
        loop invariant pies == ((sum - temp_sum) / 2);
        loop invariant temp_sum % 2 == sum % 2;
        loop assigns pies, temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert pies >= 0;
        pies = pies + 1;
        //@ assert temp_sum >= 2;
        temp_sum = temp_sum - 2;
    }
    //@ assert pies == (((3 * (a) + (p))) / 2);
    return pies;
}
