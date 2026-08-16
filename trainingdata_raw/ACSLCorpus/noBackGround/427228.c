/*@
requires ((d) >= 0 && (t) >= 0 && (s) >= 0);
requires ((d) <= (t) * (s));
ensures ((d) <= (t) * (s));
*/
void func(int d, int t, int s)
{
    //@ assert ((d) >= 0 && (t) >= 0 && (s) >= 0);
    //@ assert ((d) <= (t) * (s));
    //@ assert ((d) <= (t) * (s));
}

int main()
{
    int d;
    int t;
    int s;
    
    return 0;
}
