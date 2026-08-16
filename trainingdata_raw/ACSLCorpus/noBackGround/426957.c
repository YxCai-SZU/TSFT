/*@
    requires ((13) + 2) == ((8) + 2) + 5;
    ensures \true;
*/
void use_broadcast(int x)
{
    //@ assert ((13) + 2) == ((8) + 2) + 5;
}

int main()
{
    return 0;
}
