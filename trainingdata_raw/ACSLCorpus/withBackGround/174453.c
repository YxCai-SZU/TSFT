/*@
    logic integer div(integer x, integer y) = x / y;

    lemma div_completeness:
        \forall integer x, y;
            x > 0 && y > 0 ==> div(x, y) * y <= x;
*/

/*@
    requires \true;
    ensures \true;
*/
void example_div_usage(void)
{
    //@ assert div(10, 3) * 3 <= 10;
    //@ assert div(12, 4) * 4 <= 12;
    //@ assert div(97, 11) * 11 <= 97;
}

/*@
    requires \true;
    ensures \true;
*/
void example_div_usage2(void)
{
    //@ assert div(5, 2) * 2 <= 5;
    //@ assert div(12, 3) * 3 <= 12;
    //@ assert div(50, 10) * 10 <= 50;
}

/*@
    requires \true;
    ensures \true;
*/
void example_div_usage3(void)
{
    //@ assert div(6, 1) * 1 <= 6;
    //@ assert div(24, 4) * 4 <= 24;
    //@ assert div(48, 6) * 6 <= 48;
}

int main(void)
{
    return 0;
}
