/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == 2 * r * 3;
    assigns \nothing;
*/
long func(long r)
{
    long pi;
    long circumference;
    long temp;
    long i;
    
    pi = 3;
    circumference = 0;
    temp = 2 * r * pi;
    i = 0;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant temp == 2 * r * pi;
        loop invariant i == 0 || i == 1;
        loop invariant 0 <= i && i <= 1;
        loop assigns i;
        loop variant 1 - i;
    */
    while (i < 1)
    {
        i = i + 1;
    }
    
    circumference = temp;
    
    //@ assert circumference == 2 * r * 3;
    
    return circumference;
}

int main(void)
{
    return 0;
}
