#include <stdbool.h>

/*@
    logic integer sum_of_even(integer n) =
        (n == 0) ? 0 :
        ((n % 2 == 0) ? n + sum_of_even(n - 1) : sum_of_even(n - 1));

    lemma sum_of_even_10:
        sum_of_even(10) == 30;

    logic integer square(integer n) = n * n;

    logic integer area_square(integer s) = square(s);

    lemma lemma_square_facts:
        \forall integer s; area_square(s) == square(s) && area_square(s) == s * s;

    logic integer volume_cube(integer l) = l * l * l;

    logic integer volume_cube_spec(integer l) = volume_cube(l);

    lemma lemma_cube_facts:
        \forall integer l; volume_cube(l) == volume_cube_spec(l) && volume_cube(l) == l * l * l;
*/

int main() {
    //@ assert sum_of_even(10) == 30;
    return 0;
}
