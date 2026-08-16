/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result >= 0;
    ensures \result == n - 2 * m || \result == 0;
*/
int func(int n, int m)
{
    int result;
    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);
    result = n - 2 * m;
    /*@ assert
        (result >= 0 ==> result == n - 2 * m) &&
        (result < 0 ==> 0 == n - 2 * m || 0 == 0);
    */
    if (result < 0)
    {
        return 0;
    }
    else
    {
        return result;
    }
}
