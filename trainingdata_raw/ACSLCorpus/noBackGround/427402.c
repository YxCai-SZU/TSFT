/*@
requires (0 <= (x) && (x) <= 10) && (0 <= (y) && (y) <= 10);
ensures 0 <= \result && \result <= 100;
assigns \nothing;
*/
int example_product(int x, int y)
{
    //@ assert (0 <= (x) && (x) <= 10);
    //@ assert (0 <= (y) && (y) <= 10);
    //@ assert 0 <= x * y;
    //@ assert x * y <= 100;
    return x * y;
}

/*@
requires (0 <= (x) && (x) <= 10) && (0 <= (y) && (y) <= 10);
ensures 0 <= \result && \result <= 20;
assigns \nothing;
*/
int example_sum(int x, int y)
{
    //@ assert (0 <= (x) && (x) <= 10);
    //@ assert (0 <= (y) && (y) <= 10);
    //@ assert 0 <= x + y;
    //@ assert x + y <= 20;
    return x + y;
}

int main()
{
    return 0;
}
