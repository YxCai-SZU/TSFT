#include <stdbool.h>

/*@ requires ((x ? 1 : 0) != 0 && (y ? 1 : 0) != 0);
    ensures x == true && y == true;
*/
void example_10(bool x, bool y)
{
    //@ assert ((x ? 1 : 0) != 0 && (y ? 1 : 0) != 0);
}

/*@ requires ((x ? 1 : 0) != 0 && (y ? 1 : 0) != 0 && (z ? 1 : 0) != 0);
    ensures x == true && y == true && z == true;
*/
void example_11(bool x, bool y, bool z)
{
    //@ assert ((x ? 1 : 0) != 0 && (y ? 1 : 0) != 0 && (z ? 1 : 0) != 0);
}

/*@ requires ((x ? 1 : 0) != 0 && (y ? 1 : 0) != 0 && (z ? 1 : 0) != 0 && (w ? 1 : 0) != 0);
    ensures x == true && y == true && z == true && w == true;
*/
void example_12(bool x, bool y, bool z, bool w)
{
    //@ assert ((x ? 1 : 0) != 0 && (y ? 1 : 0) != 0 && (z ? 1 : 0) != 0 && (w ? 1 : 0) != 0);
}

/*@ requires ((x ? 1 : 0) != 0 && (y ? 1 : 0) != 0 && (z ? 1 : 0) != 0 && (w ? 1 : 0) != 0 && (u ? 1 : 0) != 0);
    ensures x == true && y == true && z == true && w == true && u == true;
*/
void example_13(bool x, bool y, bool z, bool w, bool u)
{
    //@ assert ((x ? 1 : 0) != 0 && (y ? 1 : 0) != 0 && (z ? 1 : 0) != 0 && (w ? 1 : 0) != 0 && (u ? 1 : 0) != 0);
}

int main() {
    return 0;
}
