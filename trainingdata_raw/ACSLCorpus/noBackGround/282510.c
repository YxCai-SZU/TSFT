/*@
    requires (1 <= (x) && (x) <= 100) && (1 <= (y) && (y) <= 100);
    ensures \result == ((x) * (y));
    assigns \nothing;
*/
int func(int x, int y)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert (1 <= (y) && (y) <= 100);
    //@ assert ((x) * (y)) <= 10000;
    
    result = x * y;
    return result;
}

int main()
{
    return 0;
}
