/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((2 * 314 * (r)) / 100);
    assigns \nothing;
*/
long func(long r)
{
    long circumference = 0;
    long temp = 2 * 314 * r;
    long divisor = 100;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant divisor == 100;
        loop invariant temp >= 0;
        loop invariant circumference * 100 + temp == 2 * 314 * r;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= 100;
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert circumference == ((2 * 314 * (r)) / 100);
    return circumference;
}

int main()
{
    return 0;
}
