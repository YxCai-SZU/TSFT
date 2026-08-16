/*@
    requires 2 <= n <= 50;
    requires \valid(numbers + (0 .. n-1));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (numbers)[i] != (numbers)[j]);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] && (numbers)[i] <= (n));
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int *numbers)
{
    int count = 0;
    int i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 2 <= n <= 50;
        loop invariant (\forall integer i, j; 0 <= i < j < (n) ==> (numbers)[i] != (numbers)[j]);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (numbers)[i] && (numbers)[i] <= (n));
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant i <= n;
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert 0 <= i < n;
        if (i + 1 == numbers[i])
        {
            //@ assert count >= 0;
            //@ assert count <= i;
            count += 1;
            //@ assert count >= 1;
            //@ assert count <= i + 1;
        }
        i += 1;
        //@ assert i <= n;
    }
    //@ assert i == n;
    //@ assert count >= 0;
    //@ assert count <= n;
    return count;
}
