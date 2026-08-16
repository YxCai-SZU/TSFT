/*@
    requires \exists integer x; ((x) * 7) == n;
    ensures \exists integer y; ((y) * 7) == n + n;
    assigns \nothing;
*/
void use_exists(int n)
{
    //@ assert \exists integer x; ((x) * 7) == n;
    //@ assert \exists integer x; ((x) * 7) == n;
    //@ assert \exists integer x; ((x + x) * 7) == n + n;
    //@ assert \exists integer y; ((y) * 7) == n + n;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
