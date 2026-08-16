/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * 3142 * ((r))) / 1000);
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int precision_factor;
    int pi;
    int product;
    int temp;
    int count;

    precision_factor = 1000;
    pi = 3142;

    product = 0;
    temp = 2 * pi * r;
    count = 0;

    /*@
        loop invariant 0 <= count <= (2 * 3142 * (r)) / 1000;
        loop invariant temp == (2 * 3142 * (r)) - count * precision_factor;
        loop invariant count * precision_factor + temp == (2 * 3142 * (r));
        loop invariant 0 <= (2 * 3142 * (r)) <= 200 * 3142;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= precision_factor)
    {
        //@ assert temp >= precision_factor;
        temp -= precision_factor;
        count += 1;
    }

    product = count;
    //@ assert product == ((2 * 3142 * ((r))) / 1000);
    return product;
}
