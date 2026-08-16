/*@
  requires \valid(out);
  requires (1 <= (x) && (x) <= 10) && (1 <= (y) && (y) <= 10);
  ensures *out == x + y;
  ensures 2 <= *out && *out <= 20;
*/
void calculate_sum(int x, int y, int *out) {
    int result;
    result = x + y;
    
    //@ assert (1 <= (x) && (x) <= 10);
    //@ assert (1 <= (y) && (y) <= 10);
    //@ assert result >= 2;
    //@ assert result <= 20;
    
    *out = result;
}

int main() {
    return 0;
}
