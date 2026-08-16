/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) * (b)) % 2);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product;
    int mod_result;

    product = a * b;
    mod_result = product;

    //@ assert product <= 10000;

    /*@
        loop invariant 1 <= a <= 100 && 1 <= b <= 100;
        loop invariant 0 <= mod_result <= product;
        loop invariant mod_result % 2 == product % 2;
        loop assigns mod_result;
        loop variant mod_result;
    */
    while (mod_result >= 2)
    {
        mod_result -= 2;
    }

    /*@
        loop invariant 1 <= a <= 100 && 1 <= b <= 100;
        loop invariant mod_result < 2;
        loop invariant mod_result % 2 == product % 2;
        loop assigns mod_result;
        loop variant -mod_result;
    */
    while (mod_result < 0)
    {
        mod_result += 2;
    }

    //@ assert mod_result == 0 || mod_result == 1;

    if (mod_result == 0)
    {
        //@ assert mod_result == 0;
        return 0;
    }
    else
    {
        //@ assert mod_result == 1;
        return 1;
    }
}
