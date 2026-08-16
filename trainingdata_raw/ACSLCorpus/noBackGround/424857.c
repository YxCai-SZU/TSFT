/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (k) && (k) <= (n));
    ensures \result >= 0;
    ensures \result == n - k + 1 || \result == 0;
*/
int func(int n, int k)
{
    int result;
    int max_val;
    int temp;

    //@ assert k - 1 >= 0;
    //@ assert n - (k - 1) <= 100;

    temp = n - (k - 1);
    if (0 > temp) {
        max_val = 0;
    } else {
        max_val = temp;
    }

    result = max_val;
    return result;
}
