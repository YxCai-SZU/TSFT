/*@
    requires \true;
    ensures \true;
*/
void test_injective(void)
{
    /*@ ghost int x; */
    /*@ ghost int y; */
    
    //@ assert \forall integer x, y; (-(x)) == (-(y)) ==> x == y;
}

/*@
    requires \true;
    ensures \true;
*/
void test_is_even(void)
{
    /*@ ghost int x; */
    
    //@ assert \forall integer x; (-(x)) % 2 == 0 ==> x % 2 == 0;
}

/*@
    requires \true;
    ensures \true;
*/
int main(void)
{
    test_injective();
    test_is_even();
    return 0;
}
