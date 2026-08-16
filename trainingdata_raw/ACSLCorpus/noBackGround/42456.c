/*@
    requires (-10 <= (a) && (a) <= 10) && (-10 <= (b) && (b) <= 10);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int result;
    
    //@ assert (-10 <= (a) && (a) <= 10) && (-10 <= (b) && (b) <= 10);
    
    //@ assert ((a) * (b)) <= 100;
    //@ assert ((a) * (b)) >= -100;
    
    result = a * b;
    
    //@ assert result == ((a) * (b));
    return result;
}

int main()
{
    return 0;
}
