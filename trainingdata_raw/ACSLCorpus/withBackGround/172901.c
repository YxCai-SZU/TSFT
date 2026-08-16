/*@
    logic integer volume_cube(integer edge) = edge * edge * edge;

    lemma volume_nonneg:
        \forall integer edge; 0 <= edge <= 1000 ==> 
            volume_cube(edge) >= 0 && volume_cube(edge) <= 1000000000;
*/

#include <stdbool.h>

int main() {
    int edge;
    int volume;
    
    edge = 10;
    volume = edge * edge * edge;
    
    //@ assert volume >= 0;
    
    return 0;
}
