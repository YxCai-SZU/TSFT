/*@
requires (1 <= (x) && (x) <= 5);
ensures \result == x + 1;
ensures \result <= 6;
*/
int calc_example(int x)
{
    //@ assert (1 <= (x) && (x) <= 5);
    int result;
    result = x + 1;
    //@ assert result <= 6;
    return result;
}

int main()
{
    return 0;
}
