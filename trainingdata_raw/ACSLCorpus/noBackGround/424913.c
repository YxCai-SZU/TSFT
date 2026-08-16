/*@
    requires \valid(arr + (0 .. len-1));
    requires (\forall integer k; 0 <= k < (len) ==> (arr)[k] <= (bound));
    requires 0 <= i < len;
    ensures \result <= bound;
*/
int calc_example_i(int *arr, int len, int i, int bound)
{
    //@ assert 0 <= i < len;
    //@ assert (\forall integer k; 0 <= k < (len) ==> (arr)[k] <= (bound));
    return arr[i];
}

int main()
{
    return 0;
}
