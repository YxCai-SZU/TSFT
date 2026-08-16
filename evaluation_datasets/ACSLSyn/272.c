#include <stdbool.h>

/* predicate and lemma from first snippet */
/*@
predicate neg(integer x, integer result) = result == -x;
*/

int test_AdditiveInverses() {
    //@ assert neg(10, -10);
    return -10;
}

void test_M2() {
    //@ assert neg(10, -10);
    //@ assert neg(100, -100);
    //@ assert 10 + (-10) == 0;
    //@ assert 100 + (-100) == 0;
}

/* functions from second snippet */
/*@
    predicate is_valid_triangle(integer x, integer y, integer z) =
        x > 0 && y > 0 && z > 0;
*/

bool func_triangle(int x, int y, int z)
{
    bool is_valid = false;

    if (x > 0) {
        if (y > 0) {
            if (z > 0) {
                is_valid = true;
            }
        }
    }

    return is_valid;
}

bool func_triangle_spec(int x, int y, int z)
{
    return x > 0 && y > 0 && z > 0;
}

/* functions from third snippet */
/*@ predicate is_valid_params(integer a, integer b, integer c) =
      1 <= a <= 5000 &&
      1 <= b <= 5000 &&
      1 <= c <= 5000;
*/

/*@ logic integer compute_x(integer a, integer b, integer c) =
      c - a - b;
*/

bool func_triangle_check(int a, int b, int c)
{
    int x;
    bool result;

    x = c - a - b;
    result = (x > 0) && (a + b > c);
    return result;
}

/* synthesized function: validate triangle angles and sides for a real-world scenario */
bool validate_triangle(int angle1, int angle2, int angle3, int side1, int side2, int side3)
{
    bool angles_ok = false;
    bool sides_ok = false;
    bool result = false;

    angles_ok = func_triangle(angle1, angle2, angle3);

    sides_ok = func_triangle_check(side1, side2, side3);

    if (angles_ok && sides_ok) {
        result = true;
    }

    return result;
}
