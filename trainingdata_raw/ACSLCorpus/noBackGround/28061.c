/*@
    requires ((n) >= 2 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 10);
    ensures \result >= 0;
    ensures \exists integer i, j; 0 <= i < n && 0 <= j < n && \result == a[j] - a[i];
*/
int func(int n, int *a)
{
    int min;
    int max;
    int i;

    min = a[0];
    max = a[0];
    i = 1;

    /*@
        loop invariant 1 <= i <= n;
        loop invariant ((n) >= 2 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 10);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (min) <= (a)[k]);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (max) >= (a)[k]);
        loop invariant (\exists integer x, y; 0 <= x < (i) && 0 <= y < (i) && (max) == (a)[y] && (min) == (a)[x]);
        loop invariant max - min >= 0;
        loop assigns i, min, max;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert a[i] >= 1 && a[i] <= 10;
        
        if (a[i] < min)
        {
            min = a[i];
        }
        
        if (a[i] > max)
        {
            max = a[i];
        }
        
        i++;
    }

    //@ assert \exists integer x, y; 0 <= x < n && 0 <= y < n && max == a[y] && min == a[x];
    return max - min;
}
