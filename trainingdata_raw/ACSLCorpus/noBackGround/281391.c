/*@
    requires length <= 1000 && width <= 1000;
    ensures \result == 2 * (length + width);
    assigns \nothing;
*/
unsigned int rectangle_perimeter(unsigned int length, unsigned int width) {
    unsigned int ret;
    //@ assert length + width <= 2000;
    ret = 2 * (length + width);
    return ret;
}

/*@
    requires side <= 1000;
    ensures \result == side * side;
    assigns \nothing;
*/
unsigned int square_area(unsigned int side) {
    unsigned int ret;
    //@ assert side * side <= 1000 * 1000;
    ret = side * side;
    return ret;
}
