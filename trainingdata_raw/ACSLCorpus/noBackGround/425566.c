/*@
    requires (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
    ensures \result == (((A) * 3 + (P)) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int A, unsigned int P)
{
    unsigned int sum;
    unsigned int ret;
    unsigned int temp_sum;
    unsigned int count;

    //@ assert A * 3 <= 300;
    //@ assert A * 3 + P <= 400;

    sum = A * 3 + P;
    ret = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant temp_sum + 2 * count == sum;
        loop invariant temp_sum <= sum;
        loop invariant 0 <= count && count <= sum / 2;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }
    ret = count;

    return ret;
}

int main(void)
{
    return 0;
}
