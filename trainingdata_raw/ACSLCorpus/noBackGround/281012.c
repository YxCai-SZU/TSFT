#include <limits.h>

/*@
    requires (-1290 <= (side_length) <= 1290);
    ensures \result == ((side_length) * (side_length) * (side_length));
    assigns \nothing;
*/
int volume_cube(int side_length) {
    // Variable declarations at top of scope
    int volume;
    
    //@ assert -1290 <= side_length && side_length <= 1290;
    
    //@ assert side_length * side_length >= -1290 * 1290 && side_length * side_length <= 1290 * 1290;
    
    //@ assert side_length * side_length * side_length >= -1290 * 1290 * 1290 && side_length * side_length * side_length <= 1290 * 1290 * 1290;
    
    volume = side_length * side_length * side_length;
    return volume;
}

int main() {
    // Variable declarations at top of scope
    int side;
    int volume;
    
    side = 10;
    volume = volume_cube(side);
    
    //@ assert volume == 1000;
    
    return 0;
}
