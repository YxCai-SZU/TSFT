#include <stdint.h>

/*@
    requires (-1000 <= (side) && (side) <= 1000 && (side) >= 0);
    ensures \result == ((side) * (side));
    assigns \nothing;
*/
int32_t find_square_area(int32_t side)
{
    int32_t area;
    
    //@ assert (-1000 <= (side) && (side) <= 1000 && (side) >= 0);
    //@ assert ((side) * (side)) >= 0;
    //@ assert ((side) * (side)) <= 1000000;
    
    area = side * side;
    
    //@ assert area == ((side) * (side));
    return area;
}

/*@
    requires (-1000 <= (side) && (side) <= 1000 && (side) >= 0);
    assigns \nothing;
*/
void print_square_area(int32_t side)
{
    int32_t area;
    
    //@ assert (-1000 <= (side) && (side) <= 1000 && (side) >= 0);
    area = side * side;
    //@ assert area == ((side) * (side));
}

/*@
    assigns \nothing;
*/
int main()
{
    int32_t side;
    int32_t area;
    
    side = 25;
    
    //@ assert (-1000 <= (side) && (side) <= 1000 && (side) >= 0);
    area = find_square_area(side);
    
    //@ assert area == 625;
    //@ assert area == ((side) * (side));
    
    print_square_area(side);
    return 0;
}
