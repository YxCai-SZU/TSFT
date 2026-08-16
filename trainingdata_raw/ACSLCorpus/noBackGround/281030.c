/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b)) / 2;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product;
    unsigned int result;
    unsigned int temp;
    unsigned int count;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    product = a * b;
    //@ assert 1 <= product <= 10000;
    
    result = 0;
    temp = product;
    count = 0;

    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp + 2 * count == product;
        loop invariant count <= product / 2;
        loop assigns temp, count;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
        //@ assert temp + 2 * count == product;
    }

    result = count;
    //@ assert result == product / 2;
    return result;
}
