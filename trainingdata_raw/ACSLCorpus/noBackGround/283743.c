/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == 2 * r * 3;
    assigns \nothing;
*/
long func(long r)
{
    long pi = 3;
    long circumference = 0;
    long temp = 2 * r * pi;
    long i = 0;
    
    /*@
        loop invariant 0 <= i <= temp;
        loop invariant temp == 2 * r * pi;
        loop invariant circumference == i;
        loop invariant pi == 3;
        loop assigns circumference, i;
        loop variant temp - i;
    */
    while (i < temp)
    {
        circumference += 1;
        i += 1;
        //@ assert circumference == i;
    }
    
    //@ assert circumference == 2 * r * 3;
    return circumference;
}

int main()
{
    return 0;
}
