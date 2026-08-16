/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) * (b) + 1) / 2);
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int product;
    int result;
    int count;
    int temp;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert a * b <= 10000;

    product = a * b + 1;
    result = 0;
    count = 0;
    temp = product;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant temp >= 0;
        loop invariant temp == product - 2 * count;
        loop invariant count >= 0;
        loop invariant count <= product / 2;
        loop invariant count <= (((a) * (b) + 1) / 2);
        loop assigns temp, count;
    */
    while (temp >= 2)
    {
        temp -= 2;
        count += 1;
    }
    result = count;

    //@ assert result == (((a) * (b) + 1) / 2);
    return result;
}

int main(void)
{
    return 0;
}
