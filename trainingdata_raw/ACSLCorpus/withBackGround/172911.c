/*@
    predicate mul_comparison_pre(unsigned int x, unsigned int y, unsigned int z) =
        x <= 5 && y <= 10 && z <= 2;

    predicate mul_comparison_post(unsigned int x, unsigned int y, unsigned int z) =
        x * y * z <= 100;

    lemma mul_comparison_lemma:
        \forall unsigned int x, y, z;
            mul_comparison_pre(x, y, z) ==> mul_comparison_post(x, y, z);

    predicate product_comparison_pre(unsigned int a, unsigned int b, unsigned int c, unsigned int d) =
        a <= 5 && b <= 10 && c <= 5 && d <= 10;

    predicate product_comparison_post(unsigned int a, unsigned int b, unsigned int c, unsigned int d) =
        a * b <= 50 && c * d <= 50;

    lemma product_comparison_lemma:
        \forall unsigned int a, b, c, d;
            product_comparison_pre(a, b, c, d) ==> product_comparison_post(a, b, c, d);

    predicate complex_product_comparison_pre(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) =
        a <= 5 && b <= 10 && c <= 5 && d <= 10 && e <= 2;

    predicate complex_product_comparison_post(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) =
        a * b * c * d * e <= 10000;

    lemma complex_product_comparison_lemma:
        \forall unsigned int a, b, c, d, e;
            complex_product_comparison_pre(a, b, c, d, e) ==> complex_product_comparison_post(a, b, c, d, e);

    predicate cube_volume_comparison_pre(unsigned int side) =
        side <= 10;

    predicate cube_volume_comparison_post(unsigned int side) =
        side * side * side <= 1000;

    lemma cube_volume_comparison_lemma:
        \forall unsigned int side;
            cube_volume_comparison_pre(side) ==> cube_volume_comparison_post(side);

    predicate cube_surface_area_comparison_pre(unsigned int side) =
        side <= 10;

    predicate cube_surface_area_comparison_post(unsigned int side) =
        6 * side * side <= 600;

    lemma cube_surface_area_comparison_lemma:
        \forall unsigned int side;
            cube_surface_area_comparison_pre(side) ==> cube_surface_area_comparison_post(side);

    predicate rectangle_area_comparison_pre(unsigned int length, unsigned int width) =
        length <= 10 && width <= 5;

    predicate rectangle_area_comparison_post(unsigned int length, unsigned int width) =
        length * width <= 50;

    lemma rectangle_area_comparison_lemma:
        \forall unsigned int length, width;
            rectangle_area_comparison_pre(length, width) ==> rectangle_area_comparison_post(length, width);

    predicate triangle_area_comparison_pre(unsigned int base, unsigned int height) =
        base <= 10 && height <= 5;

    predicate triangle_area_comparison_post(unsigned int base, unsigned int height) =
        base * height <= 50;

    lemma triangle_area_comparison_lemma:
        \forall unsigned int base, height;
            triangle_area_comparison_pre(base, height) ==> triangle_area_comparison_post(base, height);
*/

/*@
    requires mul_comparison_pre(x, y, z);
    ensures mul_comparison_post(x, y, z);
*/
void mul_comparison(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert x <= 5 && y <= 10 && z <= 2;
    //@ assert x * y * z <= 100;
}

/*@
    requires product_comparison_pre(a, b, c, d);
    ensures product_comparison_post(a, b, c, d);
*/
void product_comparison(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    //@ assert a <= 5 && b <= 10 && c <= 5 && d <= 10;
    //@ assert a * b <= 50;
    //@ assert c * d <= 50;
}

/*@
    requires complex_product_comparison_pre(a, b, c, d, e);
    ensures complex_product_comparison_post(a, b, c, d, e);
*/
void complex_product_comparison(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e) {
    //@ assert a <= 5 && b <= 10 && c <= 5 && d <= 10 && e <= 2;
    //@ assert a * b * c * d * e <= 10000;
}

/*@
    requires cube_volume_comparison_pre(side);
    ensures cube_volume_comparison_post(side);
*/
void cube_volume_comparison(unsigned int side) {
    //@ assert side <= 10;
    //@ assert side * side * side <= 1000;
}

/*@
    requires cube_surface_area_comparison_pre(side);
    ensures cube_surface_area_comparison_post(side);
*/
void cube_surface_area_comparison(unsigned int side) {
    //@ assert side <= 10;
    //@ assert 6 * side * side <= 600;
}

/*@
    requires rectangle_area_comparison_pre(length, width);
    ensures rectangle_area_comparison_post(length, width);
*/
void rectangle_area_comparison(unsigned int length, unsigned int width) {
    //@ assert length <= 10 && width <= 5;
    //@ assert length * width <= 50;
}

/*@
    requires triangle_area_comparison_pre(base, height);
    ensures triangle_area_comparison_post(base, height);
*/
void triangle_area_comparison(unsigned int base, unsigned int height) {
    //@ assert base <= 10 && height <= 5;
    //@ assert base * height <= 50;
}

int main() {
    return 0;
}
