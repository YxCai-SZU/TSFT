#include <stdint.h>

/*@ predicate is_safe_square(integer side) = 
      -46340 <= side <= 46340; */

/*@ logic integer square_area(integer side) = 
      side * side; */

/*@ lemma square_bounds: 
      \forall integer side; 
      is_safe_square(side) ==> 
      -46340*46340 <= square_area(side) <= 46340*46340; */

/*@ requires is_safe_square(side_length);
    ensures \result == square_area(side_length);
    assigns \nothing; */
int32_t calculate_square_area(int32_t side_length) {
    int32_t area;
    //@ assert is_safe_square(side_length);
    //@ assert -46340*46340 <= square_area(side_length) <= 46340*46340;
    area = side_length * side_length;
    //@ assert area == square_area(side_length);
    return area;
}

/*@ requires is_safe_square(side_length);
    assigns \nothing; */
void print_square_area(int32_t side_length) {
    //@ assert is_safe_square(side_length);
    //@ assert square_area(side_length) == side_length * side_length;
    //@ assert square_area(side_length) >= 0;
    //@ assert square_area(side_length) <= 46340*46340;
}

/*@ assigns \nothing; */
int main() {
    int32_t side;
    int32_t area;
    
    side = 20;
    //@ assert is_safe_square(side);
    //@ assert square_area(side) == 400;
    
    area = calculate_square_area(side);
    //@ assert area == 400;
    
    print_square_area(side);
    return 0;
}
