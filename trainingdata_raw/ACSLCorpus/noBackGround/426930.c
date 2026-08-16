/*@
    requires (1 <= (n) && (n) <= 100 &&
        0 <= (r) && (r) <= 4111);
    ensures \result == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    assigns \nothing;
*/
int func(int n, int r)
{
    int ans;
    int x;
    int y;
    int z;
    int product;

    ans = n >= 10 ? r : r + 100 * (10 - n);

    x = 2;
    y = 3;
    z = 4;

    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    //@ assert x * y <= 10000;

    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    //@ assert 1 <= z && z <= 100;
    //@ assert x * y * z >= 1;

    product = x * y * z;
    //@ assert product == 24;

    return ans;
}
