/*@
    logic integer product(integer x, integer y) = x * y;

    lemma product_property:
        \forall integer x, y;
            x >= 0 && y >= 0 && x <= 1000 && y <= 1000 ==>
            product(x, y) <= 1000000;
*/

/*@
    requires \true;
    ensures \true;
*/
void example_product_usage(void)
{
    //@ assert product(50, 60) <= 1000000;
    //@ assert product(100, 100) <= 1000000;
}

int main(void)
{
    example_product_usage();
    return 0;
}
