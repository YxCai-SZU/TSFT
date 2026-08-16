/*@
    predicate valid_range(integer x, integer low, integer high) =
        low <= x && x <= high;

    logic integer area(integer length, integer width) =
        length * width;

    logic integer perimeter(integer length, integer width) =
        2 * (length + width);

    logic integer volume(integer side) =
        side * side * side;

    lemma area_bounds:
        \forall integer length, width;
            valid_range(length, 0, 100) && valid_range(width, 0, 100) ==>
            valid_range(area(length, width), 0, 100 * 100);

    lemma perimeter_bounds:
        \forall integer length, width;
            valid_range(length, 0, 100) && valid_range(width, 0, 100) ==>
            valid_range(perimeter(length, width), 0, 2 * (100 + 100));

    lemma volume_bounds:
        \forall integer side;
            valid_range(side, 0, 100) ==>
            valid_range(volume(side), 0, 100 * 100 * 100);
*/

/*@ requires valid_range(r, 1, 100);
    ensures \result == 3 * r * r;
*/
int func(int r)
{
    int pi = 3;
    //@ assert valid_range(r, 1, 100);
    //@ assert 3 * r * r <= 3 * 100 * 100;
    return pi * r * r;
}

/*@ requires valid_range(length, 0, 100) && valid_range(width, 0, 100);
    ensures \result == area(length, width);
*/
int rectangle_area(int length, int width)
{
    //@ assert valid_range(area(length, width), 0, 100 * 100);
    int area = length * width;
    return area;
}

/*@ requires valid_range(length, 0, 100) && valid_range(width, 0, 100);
    ensures \result == perimeter(length, width);
*/
int rectangle_perimeter(int length, int width)
{
    //@ assert valid_range(perimeter(length, width), 0, 2 * (100 + 100));
    return 2 * (length + width);
}

/*@ requires valid_range(l, 0, 100);
    ensures \result == volume(l);
*/
int volume_cube(int l)
{
    //@ assert valid_range(l * l, 0, 100 * 100);
    //@ assert valid_range(volume(l), 0, 100 * 100 * 100);
    return l * l * l;
}
