/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result >= 0;
    ensures \result == ((n) * (a)) || \result == b;
    ensures \result == ((n) * (a)) ==> \result <= b;
    ensures \result == b ==> \result <= ((n) * (a));
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    // Variable declarations at top
    int product;
    int min_value;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;

    // Ensure no overflow in n * a
    //@ assert 1 <= n * a && n * a <= 1000;
    product = n * a;

    // Implementing min functionality manually
    if (product < b) {
        min_value = product;
        //@ assert min_value == product;
        //@ assert min_value <= b;
    } else {
        min_value = b;
        //@ assert min_value == b;
        //@ assert min_value <= product;
    }

    return min_value;
}
