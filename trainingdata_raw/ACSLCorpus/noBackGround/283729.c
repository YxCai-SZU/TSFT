/*@
    requires 1 <= x && x <= 100;
    requires 1 <= y && y <= 100;
    requires 1 <= z && z <= 100;
    requires x * y <= 10000;
    requires x * z <= 10000;
    requires x * (y + z) <= 20000;
    ensures \result == x * (y + z);
*/
int compute_distributive(int x, int y, int z)
{
    int left_sum;
    int right_product;
    int result;

    left_sum = x * y + x * z;
    right_product = x * (y + z);

    //@ assert (1 <= (x) && (x) <= 100 &&     1 <= (y) && (y) <= 100 &&     1 <= (z) && (z) <= 100 &&     (x) * (y) <= 10000 &&     (x) * (z) <= 10000 &&     (x) * ((y) + (z)) <= 20000);
    //@ assert left_sum == right_product;

    result = right_product;
    return result;
}
