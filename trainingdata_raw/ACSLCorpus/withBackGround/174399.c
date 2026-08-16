/*@
    predicate sorted(int *arr, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> arr[i] <= arr[j];

    predicate contains(int *arr, integer len, integer v) =
        \exists integer i; 0 <= i < len && arr[i] == v;

    logic integer double_triple(integer n) = n * 2 * 3;
*/

/*@
    requires 1 <= n <= 100;
    ensures \result == double_triple(n);
    assigns \nothing;
*/
int func(int n)
{
    int pi = 3;
    int result = n * 2 * pi;
    //@ assert result == n * 2 * 3;
    return result;
}

int main(void)
{
    int v[4] = {1, 2, 3, 4};
    
    //@ assert contains(&v[0], 4, 2);
    //@ assert !contains(&v[0], 4, 5);
    //@ assert sorted(&v[0], 4);
    
    int res = func(50);
    //@ assert res == 300;
    
    return 0;
}
