#include <stdbool.h>

/*@ requires (\valid((v)) && \valid((v)+1) && \valid((v)+2) &&
      (1 <= ((v)[0]) && ((v)[0]) <= 9) && (1 <= ((v)[1]) && ((v)[1]) <= 9) && (1 <= ((v)[2]) && ((v)[2]) <= 9)); 
    ensures \result == 1 <==> (((v)[0] < (v)[1] && (v)[1] < (v)[2]) || 
      ((v)[0] <= (v)[1] && (v)[1] < (v)[2]) || 
      ((v)[0] < (v)[1] && (v)[1] <= (v)[2])); */
bool is_increasing_func(int *v)
{
    bool result;
    
    //@ assert \valid(v) && \valid(v+1) && \valid(v+2);
    //@ assert (1 <= (v[0]) && (v[0]) <= 9) && (1 <= (v[1]) && (v[1]) <= 9) && (1 <= (v[2]) && (v[2]) <= 9);
    
    result = (v[0] < v[1] && v[1] < v[2]) || 
             (v[0] <= v[1] && v[1] < v[2]) || 
             (v[0] < v[1] && v[1] <= v[2]);
    
    //@ assert result == 1 <==> (((v)[0] < (v)[1] && (v)[1] < (v)[2]) ||        ((v)[0] <= (v)[1] && (v)[1] < (v)[2]) ||        ((v)[0] < (v)[1] && (v)[1] <= (v)[2]));
    return result;
}

int main() {
    return 0;
}
