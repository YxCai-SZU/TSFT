/*@
    logic integer max_value(integer x, integer y) = (x > y) ? x : y;

    lemma max_property:
        \forall integer x, y; x > y ==> max_value(x, y) == x;
*/

/*@
    requires \true;
    ensures \true;
*/
void example_max_usage(void)
{
    /*@ assert max_value(5, 3) == 5; */
    /*@ assert max_value(2, 4) == 4; */
}

int main(void)
{
    return 0;
}
