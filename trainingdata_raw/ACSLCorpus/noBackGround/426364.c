/*@
    requires \valid(s1 + (0..len1-1));
    requires \valid(s2 + (0..len2-1));
    requires \valid(s3 + (0..len3-1));
    ensures (len1 + len2) + len3 == len1 + len2 + len3;
*/
void complex_calc_example_5(int *s1, int len1, int *s2, int len2, int *s3, int len3)
{
    int a;
    int b;

    a = 2;
    b = 5;

    //@ assert a <= a + 3;
    //@ assert a + 3 <= b;
    //@ assert b - 3 <= a + 3;
    //@ assert len1 + len2 + len3 == len1 + len2 + len3;
    //@ assert (len1 + len2) + len3 == len1 + len2 + len3;
}

int main()
{
    return 0;
}
