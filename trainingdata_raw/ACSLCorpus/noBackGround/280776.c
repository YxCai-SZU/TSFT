/*@
    requires 1 <= a <= 1000000000;
    requires 1 <= b <= 1000000000;
    requires 1 <= c <= 1000000000;
    ensures \result == 1 <==> ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
*/
int func(int a, int b, int c)
{
    int max;
    int mid;
    int min;
    int temp;

    max = a;
    mid = b;
    min = c;

    //@ assert max == a && mid == b && min == c;

    if (max < mid)
    {
        temp = max;
        max = mid;
        mid = temp;
    }
    //@ assert max >= mid;

    if (mid < min)
    {
        temp = mid;
        mid = min;
        min = temp;
    }
    //@ assert mid >= min;

    if (max < mid)
    {
        temp = max;
        max = mid;
        mid = temp;
    }
    //@ assert max >= mid && mid >= min;

    if (max == mid + min)
    {
        //@ assert ((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
        return 1;
    }
    else
    {
        //@ assert !((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a));
        return 0;
    }
}
