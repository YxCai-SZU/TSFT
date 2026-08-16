/*@
requires 0 <= x;
requires 0 <= y;
ensures \result >= 0;
assigns \nothing;
*/
int proof_example_11(int x, int y)
{
    //@ assert 0 <= x;
    //@ assert 0 <= y;
    //@ assert 0 <= x * y;
    return x * y;
}

/*@
requires 0 <= x;
requires 0 <= y;
requires x + y >= 0;
ensures \result >= 0;
assigns \nothing;
*/
int proof_example_12(int x, int y)
{
    //@ assert 0 <= x;
    //@ assert 0 <= y;
    //@ assert 0 <= x * y;
    return x * y;
}

int main()
{
    return 0;
}
