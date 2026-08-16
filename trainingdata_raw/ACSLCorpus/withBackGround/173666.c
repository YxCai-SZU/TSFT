#include <stdbool.h>

/*@ predicate is_valid_vector(int *v, integer len) =
      len == 2 &&
      \valid(v + (0..1)) &&
      v[0] >= 1 && v[0] <= 100 &&
      v[1] >= 1 && v[1] <= 100;
*/

/*@ lemma product_range:
      \forall integer a, b;
        a >= 1 && a <= 100 && b >= 1 && b <= 100 ==> a * b >= 1 && a * b <= 10000;
*/

/*@ requires is_valid_vector(v, 2);
    ensures \result == v[0] * v[1];
    assigns \nothing;
*/
int func(int *v)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int result = 0;

    /*@ loop invariant 0 <= i <= v[0];
        loop invariant is_valid_vector(v, 2);
        loop assigns i;
        loop variant v[0] - i;
    */
    while (i < v[0])
    {
        i += 1;
    }

    /*@ loop invariant 0 <= j <= v[1];
        loop invariant is_valid_vector(v, 2);
        loop assigns j;
        loop variant v[1] - j;
    */
    while (j < v[1])
    {
        j += 1;
    }

    //@ assert i == v[0] && j == v[1];

    //@ assert v[0] * v[1] >= 1 && v[0] * v[1] <= 10000;
    result = v[0] * v[1];

    /*@ loop invariant 0 <= k <= v[0];
        loop invariant is_valid_vector(v, 2);
        loop assigns k, l;
        loop variant v[0] - k;
    */
    while (k < v[0])
    {
        l = 0;
        /*@ loop invariant 0 <= l <= v[1];
            loop invariant is_valid_vector(v, 2);
            loop assigns l;
            loop variant v[1] - l;
        */
        while (l < v[1])
        {
            l += 1;
        }
        k += 1;
    }

    return result;
}

int main()
{
    return 0;
}
