/*@
    requires (0 <= (a) && (a) <= 9) && (0 <= (b) && (b) <= 9);
    ensures ((a) + (b) <= 18);
*/
void func(int a, int b)
{
    //@ assert (0 <= (a) && (a) <= 9);
    //@ assert (0 <= (b) && (b) <= 9);
    //@ assert ((a) + (b) <= 18);
}

int main()
{
    return 0;
}
