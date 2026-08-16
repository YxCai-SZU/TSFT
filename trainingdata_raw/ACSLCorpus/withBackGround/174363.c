/*@
    predicate seq_eq{L1,L2}(int *a, int *b, integer len) =
        \forall integer i; 0 <= i < len ==> \at(a[i], L1) == \at(b[i], L2);

    lemma power_facts:
        2 * 2 == 4 &&
        4 * 4 == 16 &&
        8 * 8 == 64 &&
        16 * 16 == 256;
*/

/*@
    requires
        len_a >= 0 && len_b >= 0 && len_c >= 0 && len_d >= 0 &&
        \valid(a + (0 .. len_a - 1)) &&
        \valid(b + (0 .. len_b - 1)) &&
        \valid(c + (0 .. len_c - 1)) &&
        \valid(d + (0 .. len_d - 1));
    ensures
        seq_eq{Pre,Post}(a, a, len_a) &&
        seq_eq{Pre,Post}(b, b, len_b) &&
        seq_eq{Pre,Post}(c, c, len_c) &&
        seq_eq{Pre,Post}(d, d, len_d);
*/
void example_power(int *a, int *b, int *c, int *d, int len_a, int len_b, int len_c, int len_d)
{
    int tmp1;
    int tmp2;
    int tmp3;
    int tmp4;

    tmp1 = 2 * 2;
    //@ assert tmp1 == 4;

    tmp2 = 4 * 4;
    //@ assert tmp2 == 16;

    tmp3 = 8 * 8;
    //@ assert tmp3 == 64;

    tmp4 = 16 * 16;
    //@ assert tmp4 == 256;
}

int main()
{
    return 0;
}
