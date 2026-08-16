/*@
    logic integer f(integer x) = x * 10 + 5;

    lemma f_increasing:
        \forall integer x; f(x) > x * 10;
*/

/*@
    requires \true;
    ensures \forall integer i; f(i) > i * 10;
*/
void test_increasing(void)
{
    //@ assert \forall integer i; f(i) > i * 10;
}

/*@
    requires \true;
    ensures \forall integer i; f(i) > i * 10;
*/
void test_increasing_fixed(void)
{
    //@ assert \forall integer i; f(i) > i * 10;
}

int main(void)
{
    return 0;
}
