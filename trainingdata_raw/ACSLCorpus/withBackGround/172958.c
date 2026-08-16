/*@
    predicate valid_range(integer x) = 1 <= x && x <= 10;
    predicate valid_product(integer a, integer b, integer res) = 
        valid_range(a) && valid_range(b) && res == a * b;
*/

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= b && b <= 10;
    //@ assert 1 <= a * b && a * b <= 100;
    return a * b;
}

/*@
    requires 1 <= a <= 10;
    requires 1 <= b <= 10;
    requires valid_range(a) && valid_range(b);
    ensures valid_product(a, b, \result);
    assigns \nothing;
*/
int high_order_calc(int a, int b)
{
    //@ assert valid_range(a) && valid_range(b);
    int res = func(a, b);
    //@ assert valid_product(a, b, res);
    return res;
}

int main()
{
    int a = 5;
    int b = 7;
    int result = high_order_calc(a, b);
    //@ assert result == 35;
    return 0;
}
