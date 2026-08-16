/*@
    lemma mul_is_distributive_add:
        \forall integer x, y, z;
            x >= 0 && x <= 10000 &&
            y >= 0 && y <= 10000 &&
            z >= 0 && z <= 10000 &&
            x * y <= 10000 &&
            x * z <= 10000 &&
            y * z <= 10000 &&
            x * (y + z) <= 10000
        ==> x * (y + z) == x * y + x * z;

    lemma mul_is_distributive_sub:
        \forall integer x, y, z;
            x >= 0 && x <= 10000 &&
            y >= 0 && y <= 10000 &&
            z >= 0 && z <= 10000 &&
            x * y <= 10000 &&
            x * z <= 10000 &&
            y * z <= 10000 &&
            x * (y - z) <= 10000
        ==> x * (y - z) == x * y - x * z;
*/

int main() {
    return 0;
}
