/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
int func(int n, int a)
{
    // Variable declarations at top
    int result;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;
    //@ assert n * n <= 10000;
    
    result = n * n - a;
    return result;
}

// Test functions (empty implementations as in original)
void test_func(void) {}
void test_max_n(void) {}
void test_min_n(void) {}
void test_mid_n(void) {}
void test_max_a(void) {}
void test_min_a(void) {}
void test_bounds(void) {}
void test_negative(void) {}

int main(void)
{
    return 0;
}
