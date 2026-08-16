/*@
requires \true;
assigns \nothing;
ensures (2 * 3 == 6);
*/
void custom_relation()
{
    //@ assert 2 * 3 == 6;
}

/*@
requires \true;
assigns \nothing;
ensures (2 < 5);
*/
void custom_less_than()
{
    //@ assert 2 < 5;
}

/*@
requires \true;
assigns \nothing;
ensures (5 > 2);
*/
void custom_greater_than()
{
    //@ assert 5 > 2;
}

/*@
requires \true;
assigns \nothing;
ensures (5 == 5);
*/
void custom_equal_to()
{
    //@ assert 5 == 5;
}

/*@
requires \true;
assigns \nothing;
ensures (5 != 2);
*/
void custom_not_equal_to()
{
    //@ assert 5 != 2;
}

/*@
requires \true;
assigns \nothing;
ensures (5 <= 5);
*/
void custom_less_than_or_equal_to()
{
    //@ assert 5 <= 5;
}

/*@
requires \true;
assigns \nothing;
ensures (5 >= 2);
*/
void custom_greater_than_or_equal_to()
{
    //@ assert 5 >= 2;
}

int main()
{
    custom_relation();
    custom_less_than();
    custom_greater_than();
    custom_equal_to();
    custom_not_equal_to();
    custom_less_than_or_equal_to();
    custom_greater_than_or_equal_to();
    return 0;
}
