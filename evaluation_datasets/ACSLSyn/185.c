#include <stdbool.h>

/*@
    predicate sorted_seq(int *arr) =
        arr[0] <= arr[1] && arr[1] <= arr[2];
*/

/*@
    predicate is_valid_params(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= 100;
*/

bool verify_sorted_chains(const int *a, const int *b, const int *c)
{
    //@ assert a[2] <= b[0];
    //@ assert b[0] <= b[2];
    //@ assert b[2] <= c[0];
    return true;
}

bool func(unsigned int n, unsigned int k)
{
    bool result;

    if (n % 3 == 0) {
        result = true;
    } else {
        result = (k >= 2);
    }

    return result;
}

bool validate_pipeline(const int *a, const int *b, const int *c, unsigned int n, unsigned int k)
{
    bool chain_ok = verify_sorted_chains(a, b, c);
    bool params_ok = func(n, k);
    bool result = chain_ok && params_ok;

    //@ assert result ==> (chain_ok && params_ok);
    return result;
}

int main()
{
    return 0;
}
