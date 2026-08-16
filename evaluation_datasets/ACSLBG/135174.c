/*@
predicate positive(integer x) = x > 0;

lemma arithmetic_lemma:
    \forall integer a, b, c, d;
    positive(a) && positive(b) && positive(c) && positive(d) ==>
    a * (b + c) * d <= a * b * d + a * c * d;
*/


void non_linear_arith_example(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    // Variable declarations at top
    unsigned int tmp1;
    unsigned int tmp2;
    unsigned int tmp3;
    unsigned int tmp4;
    unsigned int tmp5;
    unsigned int tmp6;
    unsigned int tmp7;
    unsigned int tmp8;
    unsigned int tmp9;
    unsigned int tmp10;
    unsigned int tmp11;
    unsigned int tmp12;
    unsigned int tmp13;
    unsigned int tmp14;
    unsigned int tmp15;
    unsigned int tmp16;
    unsigned int tmp17;
    unsigned int tmp18;
    unsigned int tmp19;
    unsigned int tmp20;
    unsigned int tmp21;
    unsigned int tmp22;
    unsigned int tmp23;
    unsigned int tmp24;
    unsigned int tmp25;
    unsigned int tmp26;
    unsigned int tmp27;
    unsigned int tmp28;
    unsigned int tmp29;
    unsigned int tmp30;
    unsigned int tmp31;
    unsigned int tmp32;
    unsigned int tmp33;
    unsigned int tmp34;
    unsigned int tmp35;
    unsigned int tmp36;
    unsigned int tmp37;
    unsigned int tmp38;
    unsigned int tmp39;
    unsigned int tmp40;
    unsigned int tmp41;
    unsigned int tmp42;
    unsigned int tmp43;
    unsigned int tmp44;
    unsigned int tmp45;
    unsigned int tmp46;
    unsigned int tmp47;
    unsigned int tmp48;
    unsigned int tmp49;
    unsigned int tmp50;
    unsigned int tmp51;
    unsigned int tmp52;
    unsigned int tmp53;
    unsigned int tmp54;
    unsigned int tmp55;
    unsigned int tmp56;
    unsigned int tmp57;
    unsigned int tmp58;
    unsigned int tmp59;
    unsigned int tmp60;
    unsigned int tmp61;
    unsigned int tmp62;
    unsigned int tmp63;
    unsigned int tmp64;
    unsigned int tmp65;
    unsigned int tmp66;
    unsigned int tmp67;
    unsigned int tmp68;
    unsigned int tmp69;
    unsigned int tmp70;
    unsigned int tmp71;
    unsigned int tmp72;
    unsigned int tmp73;
    unsigned int tmp74;
    unsigned int tmp75;
    unsigned int tmp76;
    unsigned int tmp77;
    unsigned int tmp78;
    unsigned int tmp79;
    unsigned int tmp80;
    unsigned int tmp81;
    unsigned int tmp82;
    unsigned int tmp83;
    unsigned int tmp84;
    unsigned int tmp85;
    unsigned int tmp86;
    unsigned int tmp87;
    unsigned int tmp88;
    unsigned int tmp89;
    unsigned int tmp90;
    unsigned int tmp91;
    unsigned int tmp92;
    unsigned int tmp93;
    unsigned int tmp94;
    unsigned int tmp95;
    unsigned int tmp96;
    unsigned int tmp97;
    unsigned int tmp98;
    unsigned int tmp99;
    unsigned int tmp100;

    //@ assert positive(a);
    //@ assert positive(b);
    //@ assert positive(c);
    //@ assert positive(d);
    
    //@ assert a * (b + c) <= a * b + a * c;
    //@ assert a * b * d <= a * b * d;
    //@ assert a * c * d <= a * c * d;
    
    //@ assert a * (b + c) * d <= a * b * d + a * c * d;
}

int main() {
    return 0;
}
