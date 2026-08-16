/*@
    predicate condition_holds(integer m, integer f, integer b) =
        m + f + b >= 10 && f > m && b > m;
*/

/*@
    requires 1 <= m <= 20;
    requires 1 <= f <= 20;
    requires 1 <= b <= 20;
    ensures condition_holds(m, f, b) ==> \result == 1;
    ensures !condition_holds(m, f, b) ==> \result == 0;
*/
int func(int m, int f, int b)
{
    int sum;
    sum = m + f + b;

    if (sum >= 10 && f > m && b > m)
    {
        //@ assert condition_holds(m, f, b);
        return 1;
    }
    else
    {
        //@ assert !condition_holds(m, f, b);
        return 0;
    }
}
