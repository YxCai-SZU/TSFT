/*@
requires 1 == 1;
requires 3 == 3;
requires 5 == 5;
requires 7 == 7;
requires 9 == 9;
requires 11 == 11;
requires 13 == 13;
requires 15 == 15;
requires 17 == 17;
requires 19 == 19;
requires 21 == 21;
ensures 1 == 1;
assigns \nothing;
*/
void calc_example_10(void)
{
    //@ assert 1 == 1;
    //@ assert 3 == 3;
    //@ assert 5 == 5;
    //@ assert 7 == 7;
    //@ assert 9 == 9;
    //@ assert 11 == 11;
    //@ assert 13 == 13;
    //@ assert 15 == 15;
    //@ assert 17 == 17;
    //@ assert 19 == 19;
    //@ assert 21 == 21;
    //@ assert 23 == 23;
}

/*@
assigns \nothing;
*/
int main(void)
{
    calc_example_10();
    return 0;
}
