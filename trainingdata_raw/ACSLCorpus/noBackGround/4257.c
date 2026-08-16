/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result == a * n || \result == b;
    ensures \result <= b && \result <= a * n;
*/
int func(int n, int a, int b)
{
    int min_value;
    int product;

    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= n && n <= 20;
    //@ assert a * n <= 1000;

    product = a * n;

    if (b < product) {
        min_value = b;
    } else {
        min_value = product;
    }

    //@ assert min_value == a * n || min_value == b;
    //@ assert min_value <= b && min_value <= a * n;
    return min_value;
}
