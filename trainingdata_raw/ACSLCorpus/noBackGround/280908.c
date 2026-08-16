/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert 1 <= a - 1 && a - 1 <= 99;
    //@ assert 1 <= b - 1 && b - 1 <= 99;
    //@ assert 1 <= (a - 1) * (b - 1) && (a - 1) * (b - 1) <= 9801;
    
    int ans = (a - 1) * (b - 1);
    return ans;
}

int main(void)
{
    return 0;
}
