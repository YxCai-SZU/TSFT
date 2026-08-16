/*@
    requires 1 <= a && a <= 8;
    requires 1 <= b && b <= 8;
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) && (a) <= 8 &&         1 <= (b) && (b) <= 8);
    //@ assert 1 <= a * b && a * b <= 64;
    int ans = a * b;
    return ans;
}

int main()
{
    return 0;
}
