/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && 
             (1 <= (c) <= 10) && (1 <= (d) <= 10);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int res;
    
    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    //@ assert (1 <= (d) <= 10);
    
    //@ assert ((a) * (b)) >= 1 && ((a) * (b)) <= 100;
    //@ assert ((c) * (d)) >= 1 && ((c) * (d)) <= 100;
    
    if (a * b > c * d) {
        res = a * b;
    } else {
        res = c * d;
    }
    
    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    //@ assert res >= 1;
    
    return res;
}

int main()
{
    return 0;
}
