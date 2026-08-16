/*@
    requires ((i) <= (j) && (arr)[(i)] <= (arr)[(j)]);
    ensures arr[j] >= arr[i];
*/
void calc_example_i(int *arr, int i, int j)
{
    //@ assert ((i) <= (j) && (arr)[(i)] <= (arr)[(j)]);
    //@ assert arr[i] <= arr[j];
    //@ assert arr[j] >= arr[i];
}

/*@
    requires ((i) <= (j) && (arr)[(i)] <= (arr)[(j)]);
    ensures arr[j] >= arr[i];
*/
void calc_example_d(int *arr, int i, int j)
{
    //@ assert ((i) <= (j) && (arr)[(i)] <= (arr)[(j)]);
    //@ assert arr[i] <= arr[j];
    //@ assert arr[j] >= arr[i];
}

int main()
{
    return 0;
}
