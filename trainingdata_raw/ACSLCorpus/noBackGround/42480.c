/*@
requires \exists integer j; j > 0 && ((j) > 0);
ensures ((5) > 0);
*/
void establish_exists_is_positive()
{
    //@ assert ((5) > 0);
}

int main()
{
    return 0;
}
