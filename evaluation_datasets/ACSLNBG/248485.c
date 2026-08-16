
int non_linear_arith(int x, int y, int z) {
    int sum;
    int product;
    int result;
    
    //@ assert (1 <= (x) <= 100) && (1 <= (y) <= 100) && (1 <= (z) <= 100);
    
    sum = x + y;
    //@ assert 1 <= sum <= 200;
    
    product = sum * z;
    //@ assert product == (((x) + (y)) * (z));
    
    result = product;
    return result;
}
