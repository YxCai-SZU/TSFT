#include <limits.h>

/*@
    requires (0 <= (l) <= 1290);
    ensures \result == ((l) * (l) * (l));
    assigns \nothing;
*/
int volume_cube(int l) {
    //@ assert 0 <= l && l <= 1290;
    //@ assert l * l <= 1290 * 1290;
    //@ assert l * l * l <= 1290 * 1290 * 1290;
    return l * l * l;
}

/*@
    requires (0 <= (l) <= 1290) && (0 <= (w) <= 1290) && (0 <= (h) <= 1290);
    ensures \result == ((l) * (w) * (h));
    assigns \nothing;
*/
int volume_rectangular_prism(int l, int w, int h) {
    //@ assert 0 <= l && l <= 1290;
    //@ assert 0 <= w && w <= 1290;
    //@ assert 0 <= h && h <= 1290;
    //@ assert l * w <= 1290 * 1290;
    //@ assert l * w * h <= 1290 * 1290 * 1290;
    return l * w * h;
}

/*@
    requires (0 <= (l) <= 1290);
    ensures \result == (6 * (l) * (l));
    assigns \nothing;
*/
int surface_area_cube(int l) {
    //@ assert 0 <= l && l <= 1290;
    //@ assert 6 * l * l <= 6 * 1290 * 1290;
    return 6 * l * l;
}

/*@
    requires (0 <= (l) <= 1290) && (0 <= (w) <= 1290) && (0 <= (h) <= 1290);
    ensures \result == (2 * ((l) * (w) + (l) * (h) + (w) * (h)));
    assigns \nothing;
*/
int surface_area_rectangular_prism(int l, int w, int h) {
    //@ assert 0 <= l && l <= 1290;
    //@ assert 0 <= w && w <= 1290;
    //@ assert 0 <= h && h <= 1290;
    //@ assert 2 * (l * w + l * h + w * h) <= 6 * 1290 * 1290;
    return 2 * (l * w + l * h + w * h);
}

/*@
    assigns \nothing;
*/
void test_volume_cube(void) {
    int v1 = volume_cube(5);
    int v2 = volume_cube(1290);
}

/*@
    assigns \nothing;
*/
void test_volume_rectangular_prism(void) {
    int v1 = volume_rectangular_prism(5, 10, 15);
    int v2 = volume_rectangular_prism(1290, 1290, 1290);
}

/*@
    assigns \nothing;
*/
void test_surface_area_cube(void) {
    int s1 = surface_area_cube(5);
    int s2 = surface_area_cube(1290);
}

/*@
    assigns \nothing;
*/
void test_surface_area_rectangular_prism(void) {
    int s1 = surface_area_rectangular_prism(5, 10, 15);
    int s2 = surface_area_rectangular_prism(1290, 1290, 1290);
}
