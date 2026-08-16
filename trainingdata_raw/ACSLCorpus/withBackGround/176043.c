/*@
    predicate heights_valid(integer n, int *heights) =
        \forall integer i; 0 <= i < n ==> 1 <= *(heights + i) <= 500;

    predicate loop_invariant(integer index, integer n, integer num) =
        index <= n && num <= index;
*/

/*@
    requires 1 <= n <= 100000;
    requires 1 <= k <= 500;
    requires \valid(heights + (0 .. n-1));
    requires heights_valid(n, heights);
    ensures \result <= n;
    assigns \nothing;
*/
unsigned int func(unsigned int n, int k, int *heights)
{
    unsigned int num = 0;
    unsigned int index = 0;

    /*@
        loop invariant loop_invariant(index, n, num);
        loop assigns index, num;
        loop variant n - index;
    */
    while (index < n)
    {
        int h = heights[index];
        //@ assert 0 <= index < n;
        if (h >= k)
        {
            num += 1;
        }
        index += 1;
    }
    return num;
}
