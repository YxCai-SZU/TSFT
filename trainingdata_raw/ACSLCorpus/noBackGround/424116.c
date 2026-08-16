/*@
requires x >= 0 && y >= 0 && x <= y;
ensures \result >= 0 && \result <= y;
assigns \nothing;
*/
int prove_example(int x, int y)
{
    //@ assert x >= 0 && y >= 0 && x <= y;
    int result = y - x;
    //@ assert result >= 0;
    //@ assert result <= y;
    return result;
}

int main()
{
    return 0;
}
