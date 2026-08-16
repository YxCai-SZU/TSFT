/*@
requires (1 <= (x) <= 3);
ensures \result == x + 1;
assigns \nothing;
*/
int example_1(int x)
{
    //@ assert 2 <= x + 1 <= 4;
    return x + 1;
}

/*@
requires (1 <= (x) <= 3);
ensures \result == x + 2;
assigns \nothing;
*/
int example_2(int x)
{
    //@ assert 3 <= x + 2 <= 5;
    return x + 2;
}

/*@
requires (1 <= (x) <= 3);
ensures \result == x + 3;
assigns \nothing;
*/
int example_3(int x)
{
    //@ assert 4 <= x + 3 <= 6;
    return x + 3;
}

/*@
requires (1 <= (x) <= 3);
ensures \result == x + 4;
assigns \nothing;
*/
int example_4(int x)
{
    //@ assert 5 <= x + 4 <= 7;
    return x + 4;
}

/*@
requires (1 <= (x) <= 3);
ensures \result == x + 5;
assigns \nothing;
*/
int example_5(int x)
{
    //@ assert 6 <= x + 5 <= 8;
    return x + 5;
}

int main()
{
    return 0;
}
