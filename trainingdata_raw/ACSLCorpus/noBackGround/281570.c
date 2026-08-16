/*@
    requires (1 <= (a) && (a) <= 100);
    requires (1 <= (b) && (b) <= 20);
    requires (1 <= (c) && (c) <= 2000);
    ensures \result >= 0;
    ensures \result == ((a) * (b)) || \result == c;
    ensures \result == ((a) * (b)) ==> \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int x;
    int res;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 20);
    //@ assert (1 <= (c) && (c) <= 2000);
    
    x = a * b;
    
    //@ assert ((a) * (b)) == x;
    //@ assert x >= 0;
    
    if (x < c) {
        res = x;
    } else {
        res = c;
    }
    
    //@ assert res >= 0;
    //@ assert res == ((a) * (b)) || res == c;
    //@ assert res == ((a) * (b)) ==> res <= c;
    
    return res;
}

int main()
{
    return 0;
}
