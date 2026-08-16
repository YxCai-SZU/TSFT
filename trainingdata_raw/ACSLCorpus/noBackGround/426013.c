/*@
    requires (0 <= (x) && (x) < 10 && 0 <= (y) && (y) < 10);
    ensures \result == ((x) * (y));
    assigns \nothing;
*/
int func(int x, int y)
{
    //@ assert (0 <= (x) && (x) < 10 && 0 <= (y) && (y) < 10);
    
    //@ assert 0 <= x * y && x * y < 100;
    
    return x * y;
}

int main()
{
    return 0;
}
