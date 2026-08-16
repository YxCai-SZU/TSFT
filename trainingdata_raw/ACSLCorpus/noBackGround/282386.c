/*@
    requires (2 <= (x) <= 100 && 2 <= (y) <= 100);
    ensures \result == (((x) - 1) * ((y) - 1));
    assigns \nothing;
*/
int func(int x, int y)
{
    int x_new;
    int y_new;
    int product;

    x_new = x - 1;
    y_new = y - 1;

    //@ assert 1 <= x_new <= 99;
    //@ assert 1 <= y_new <= 99;
    //@ assert 1 <= x_new * y_new <= 9801;

    product = x_new * y_new;
    return product;
}
