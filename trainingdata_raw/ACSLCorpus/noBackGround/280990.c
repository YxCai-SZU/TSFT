/*@
    requires 1 <= a <= 500 && 1 <= b <= 500 && 1 <= c <= 1000;
    ensures \result == (c <= a + b);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int temp;
    int local_a = a;
    int local_b = b;
    int local_c = c;

    //@ assert (1 <= (local_a) <= 500 && 1 <= (local_b) <= 500 && 1 <= (local_c) <= 1000);
    
    if (local_a > local_b) {
        temp = local_a;
        local_a = local_b;
        local_b = temp;
    }

    //@ assert ((local_a) <= (local_b));
    //@ assert (1 <= (local_a) <= 500 && 1 <= (local_b) <= 500 && 1 <= (local_c) <= 1000);
    //@ assert ((local_a) + (local_b)) <= 1000;

    return local_c <= local_a + local_b;
}
