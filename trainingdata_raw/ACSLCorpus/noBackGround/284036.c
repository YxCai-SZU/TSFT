/*@
    requires (1 <= (a) && (a) <= 20 && 1 <= (b) && (b) <= 20);
    ensures \result == ((a) * (b) + 1);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product;
    int result;

    //@ assert (1 <= (a) && (a) <= 20 && 1 <= (b) && (b) <= 20);
    //@ assert 1 <= a * b <= 400;

    product = a * b;
    result = (int)(product + 1);

    //@ assert result == ((a) * (b) + 1);
    return result;
}

void test_vec_map_with_closure(void) {}

int main(void)
{
    return 0;
}
