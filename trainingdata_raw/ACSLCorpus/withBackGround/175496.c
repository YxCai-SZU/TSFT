/*@
    predicate triangle_inequality_pre(integer x, integer y, integer z) =
        x >= 0 && y >= 0 && z >= 0 &&
        x + y >= z && x + z >= y && y + z >= x;
 */

/*@
    lemma triangle_inequality_xy_ge_z:
        \forall integer x, y, z;
            triangle_inequality_pre(x, y, z) ==> x + y >= z;
 */

/*@
    lemma triangle_inequality_yz_ge_x:
        \forall integer x, y, z;
            triangle_inequality_pre(x, y, z) ==> y + z >= x;
 */

/*@
    lemma triangle_inequality_xz_ge_y:
        \forall integer x, y, z;
            triangle_inequality_pre(x, y, z) ==> x + z >= y;
 */

int main() {
    return 0;
}
