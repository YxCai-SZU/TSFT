/*@
    requires \true;
    ensures \forall integer x; ((x) + 2) >= x;
*/
void establish_forall_non_decreasing()
{
    /*@
        loop invariant \forall integer j; 0 <= j < i ==> ((j) + 2) >= j;
        loop assigns i;
    */
    for (int i = 0; i >= 0; i++)
    {
        //@ assert ((i) + 2) >= i;
    }
}

int main()
{
    establish_forall_non_decreasing();
    return 0;
}
