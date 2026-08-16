/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
unsigned long func(unsigned long n)
{
    // Variable declarations at top of scope
    unsigned long sum;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    //@ assert ((n) * ((n) + 1) / 2) <= ((100) * ((100) + 1) / 2);
    
    sum = n * (n + 1) / 2;
    
    //@ assert sum == ((n) * ((n) + 1) / 2);
    
    return sum;
}

int main()
{
    return 0;
}
