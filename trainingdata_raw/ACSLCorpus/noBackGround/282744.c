/*@
    requires \true;
    assigns \nothing;
*/
int main()
{
    int x = 1;
    int y = 2;
    int z = 3;
    
    //@ assert ((x) <= (y) && (y) <= (z));
    //@ assert (x + y) + z == x + (y + z);
    //@ assert x + (y - z) == (x + y) - z;
    //@ assert x + (z - y) == z - (y - x);
    
    return 0;
}
