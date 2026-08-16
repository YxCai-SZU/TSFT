/*@
    requires ((n) >= -46340 && (n) <= 46340);
    ensures \result == ((n) * (n));
    assigns \nothing;
*/
int square(int n)
{
    //@ assert ((n) >= -46340 && (n) <= 46340);
    
    //@ assert ((n) * (n)) >= -46340 * 46340 && ((n) * (n)) <= 46340 * 46340;
    
    return n * n;
}

int main()
{
    return 0;
}
