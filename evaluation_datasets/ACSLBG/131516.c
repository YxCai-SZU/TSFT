/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 10;
    
    logic integer inner_product(integer a) = a * (1 + a * (1 + a));
    
    lemma inner_product_bounds: \forall integer a; a_in_range(a) ==> 
        inner_product(a) <= 1110;
*/


int func(int a)
{
    int a_1;
    int a_2;
    
    //@ assert 1 <= a && a <= 10;
    
    //@ assert 1 + a * (1 + a) >= 1;
    //@ assert 1 + a * (1 + a) <= 111;
    
    a_1 = a * (1 + a);
    
    //@ assert 1 + a_1 >= 1;
    //@ assert 1 + a_1 <= 112;
    
    //@ assert a * (1 + a_1) <= 1110;
    
    a_2 = a * (1 + a_1);
    
    return a_2;
}
