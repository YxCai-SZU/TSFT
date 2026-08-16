/*@
    requires 1 <= r && r <= 100;
    ensures \result == 2 * 314159 * r / 100000;
    assigns \nothing;
*/
long func(long r)
{
    long pi = 314159;
    long result = 0;
    long temp = 2 * pi * r;
    long count = 0;
    long divisor = 100000;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant 0 <= temp && temp <= 2 * pi * r;
        loop invariant 0 <= count;
        loop invariant count <= 2 * 314159 * r / 100000;
        loop invariant temp == 2 * 314159 * r - count * 100000;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= (100000);
        temp -= divisor;
        count += 1;
        //@ assert temp == 2 * 314159 * r - count * 100000;
    }
    
    result = count;
    //@ assert result == 2 * 314159 * r / 100000;
    return result;
}

int main(void)
{
    return 0;
}
