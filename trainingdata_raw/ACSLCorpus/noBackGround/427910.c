/*@
    requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
 */
int is_sorted(const int *arr, unsigned int len)
{
    unsigned int i;

    if (len < 2)
        return 1;

    i = 0;
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= arr[j + 1];
        loop assigns i;
        loop variant len - i;
     */
    while (i < len - 1)
    {
        //@ assert 0 <= i < len - 1;
        if (arr[i] > arr[i + 1])
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    return 0;
}
