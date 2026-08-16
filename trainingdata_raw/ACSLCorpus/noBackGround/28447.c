/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == n - m;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    //@ assert n >= m;
    //@ assert n - m <= 100;
    return n - m;
}

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    ensures (\exists integer i; 0 <= i < (len) && (arr)[i] == (\result) &&
        \forall integer j; 0 <= j < (len) ==> (arr)[j] <= (\result));
    assigns \nothing;
*/
unsigned int find_max(unsigned int *arr, unsigned int len)
{
    unsigned int max;
    unsigned int idx;
    
    max = arr[0];
    
    /*@
        loop invariant 1 <= idx <= len;
        loop invariant (\exists integer i; 0 <= i < (idx) && (arr)[i] == (max) &&
        \forall integer j; 0 <= j < (idx) ==> (arr)[j] <= (max));
        loop assigns max, idx;
        loop variant len - idx;
    */
    for (idx = 1; idx < len; idx++)
    {
        if (arr[idx] > max)
        {
            max = arr[idx];
        }
    }
    return max;
}
