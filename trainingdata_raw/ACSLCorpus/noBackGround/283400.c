/*@
    requires (-4 <= (x) && (x) <= 4);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
int cube(int x)
{
    // Variable declarations at top
    int result;
    
    //@ assert -4 <= x && x <= 4;
    
    //@ assert -64 <= x * x && x * x <= 64;
    
    //@ assert -64 <= x * x * x && x * x * x <= 64;
    
    result = x * x * x;
    
    //@ assert result == ((x) * (x) * (x));
    
    return result;
}

int main()
{
    // Variable declarations at top
    int x;
    int c;
    
    x = 2;
    
    //@ assert (-4 <= (x) && (x) <= 4);
    
    c = cube(x);
    
    //@ assert c == 8;
    
    return 0;
}
