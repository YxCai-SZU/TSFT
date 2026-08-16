/*@
    requires -1290 <= x && x <= 1290;
    ensures \result == x * x * x;
    assigns \nothing;
*/
int cubict(int x)
{
    //@ assert -1290 <= x && x <= 1290;
    //@ assert -1664100 <= x * x && x * x <= 1664100;
    //@ assert -2146689000 <= x * x * x && x * x * x <= 2146689000;
    return x * x * x;
}

int main()
{
    return 0;
}
