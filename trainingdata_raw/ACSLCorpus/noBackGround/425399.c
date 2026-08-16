/*@
    requires low <= x && x <= high;
    ensures \result == 1;
*/
int test_in_range(int x, int low, int high)
{
    //@ assert low <= x && x <= high;
    //@ assert ((low) <= (x) && (x) <= (high));
    return 1;
}

int main()
{
    return 0;
}
