/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int func(int r)
{
    int ans;
    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r * r <= 3 * 100 * 100;
    ans = 3 * r * r;
    return ans;
}

int main()
{
    return 0;
}
