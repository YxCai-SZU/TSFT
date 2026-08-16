/* Scenario: Warehouse storage optimization - calculating maximum number of 
   equally-sized cubic boxes that can fit on a rectangular pallet, considering 
   the pallet has a 1-unit border clearance requirement */

#include <limits.h>

/*@
    logic integer volume_cube(integer l, integer w) = w * w * l;

    lemma test_volume_cube:
        volume_cube(5, 2) == 2 * 2 * 5 &&
        volume_cube(5, 3) == 3 * 3 * 5;

    logic integer perimeter_rectangle(integer l, integer w) = 2 * (w + l);

    lemma test_perimeter_rectangle:
        perimeter_rectangle(5, 2) == 2 * (2 + 5) &&
        perimeter_rectangle(5, 3) == 2 * (3 + 5);

    logic integer surface_area_cube(integer l, integer w) = 6 * (w * w);

    lemma test_surface_area_cube:
        surface_area_cube(5, 2) == 6 * (2 * 2) &&
        surface_area_cube(5, 3) == 6 * (3 * 3);

    logic integer area_square(integer s, integer t) = t * t;

    lemma test_area_square:
        area_square(4, 5) == 5 * 5 &&
        area_square(4, 3) == 3 * 3;

    logic integer volume_rectangular_prism(integer l, integer w, integer h) = l * w * h;

    lemma test_volume_rectangular_prism:
        volume_rectangular_prism(2, 3, 4) == 2 * 3 * 4 &&
        volume_rectangular_prism(2, 3, 5) == 2 * 3 * 5;

    lemma check_cube_volume:
        \forall integer l, w;
            l > 0 && w > 0 && l <= 100 && w <= 100 ==>
            volume_cube(l, w) == w * w * l;

    predicate bounds(integer n, integer m) =
        2 <= n <= 100 && 2 <= m <= 100;

    logic integer result_val(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma no_overflow:
        \forall integer n, m;
            bounds(n, m) ==> 0 <= result_val(n, m) <= 9801;
*/

int func(int n, int m)
{
    int max_val;
    int min_val;
    int result;

    //@ assert bounds(n, m);

    if (n > m) {
        max_val = n;
    } else {
        max_val = m;
    }

    if (n < m) {
        min_val = n;
    } else {
        min_val = m;
    }

    //@ assert 1 <= min_val && min_val <= 100;
    //@ assert 1 <= max_val && max_val <= 100;
    //@ assert max_val - 1 >= 0 && min_val - 1 >= 0;
    //@ assert max_val - 1 <= 99 && min_val - 1 <= 99;
    //@ assert (max_val - 1) * (min_val - 1) <= 9801;

    result = (n - 1) * (m - 1);
    
    //@ assert result == result_val(n, m);
    return result;
}

int total_box_volume(int pallet_length, int pallet_width, int box_side)
{
    int num_boxes;
    int box_volume;
    int total_volume;
    
    //@ assert bounds(pallet_length, pallet_width);
    num_boxes = func(pallet_length, pallet_width);
    
    //@ assert box_side > 0 && box_side <= 100;
    //@ assert volume_cube(box_side, box_side) == box_side * box_side * box_side;
    box_volume = box_side * box_side * box_side;
    
    total_volume = num_boxes * box_volume;
    
    //@ assert total_volume == volume_cube(box_side, box_side) * result_val(pallet_length, pallet_width);
    return total_volume;
}
