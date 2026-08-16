/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((2 * ((r)) * 314159) / 100000);
    assigns \nothing;
*/
long func(long r)
{
    long pi = 314159;
    long scale = 100000;
    long circumference = 0;
    long temp = 2 * r * pi;
    
    /*@
        loop invariant 0 <= temp <= 2 * r * pi;
        loop invariant circumference >= 0;
        loop invariant temp + scale * circumference == 2 * r * pi;
        loop invariant circumference * scale <= 2 * r * pi;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        circumference += 1;
        temp -= scale;
    }
    
    //@ assert circumference == ((2 * ((r)) * 314159) / 100000);
    
    return circumference;
}

/*@
    assigns \nothing;
*/
int main(void)
{
    return 0;
}
