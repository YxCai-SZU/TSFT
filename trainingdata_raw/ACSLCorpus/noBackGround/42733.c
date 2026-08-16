/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
*/
int func(int a)
{
    //@ assert (1 <= (a) && (a) <= 100);
    return a + a * a + a * a * a;
}

int main()
{
    return 0;
}
