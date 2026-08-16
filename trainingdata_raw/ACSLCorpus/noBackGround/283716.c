#include <stdbool.h>

/*@
    requires side_length > 0;
    ensures \result == ((side_length) * (side_length));
*/
int compute_area_square(int side_length)
{
    //@ assert ((side_length) > 0);
    int result;
    result = side_length * side_length;
    //@ assert result == ((side_length) * (side_length));
    return result;
}

/*@
    requires side_length > 0;
    ensures \result == (4 * (side_length));
*/
int compute_perimeter_square(int side_length)
{
    //@ assert ((side_length) > 0);
    int result;
    result = 4 * side_length;
    //@ assert result == (4 * (side_length));
    return result;
}

/*@
    requires side_length > 0;
    ensures \result == ((side_length) * (side_length)) && \result == side_length * side_length;
    ensures \old(side_length) == side_length;
*/
int verify_area_square(int side_length)
{
    //@ assert ((side_length) > 0);
    int area;
    area = side_length * side_length;
    //@ assert area == ((side_length) * (side_length));
    return area;
}

/*@
    requires side_length > 0;
    ensures \result == (4 * (side_length)) && \result == 4 * side_length;
    ensures \old(side_length) == side_length;
*/
int verify_perimeter_square(int side_length)
{
    //@ assert ((side_length) > 0);
    int perimeter;
    perimeter = 4 * side_length;
    //@ assert perimeter == (4 * (side_length));
    return perimeter;
}

int main()
{
    int area_result;
    int perimeter_result;
    
    area_result = compute_area_square(4);
    //@ assert area_result == 16;
    
    perimeter_result = compute_perimeter_square(4);
    //@ assert perimeter_result == 16;
    
    return 0;
}
