/*@
requires \valid(a) && \valid(b);
requires *a > 0 && *a <= 10;
requires *b > 0 && *b <= 10;
ensures *a + *b >= 2;
ensures *a + *b <= 20;
assigns \nothing;
*/
void func(int* a, int* b)
{
    int x = *a;
    int y = *b;

    //@ assert ((x) > 0) && ((x) <= 10);
    //@ assert ((y) > 0) && ((y) <= 10);
    //@ assert x + y >= 2;
    //@ assert x + y <= 20;
}

int main()
{
    return 0;
}
