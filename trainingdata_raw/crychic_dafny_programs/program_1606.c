// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures 1 <= \result <= 10;
*/
int value(int rank)
{
  int v;
  switch(rank) {
    case 0: // Ace
      v = 1;
      break;
    case 1: // Two
      v = 2;
      break;
    case 2: // Three
      v = 3;
      break;
    case 3: // Four
      v = 4;
      break;
    case 4: // Five
      v = 5;
      break;
    case 5: // Six
      v = 6;
      break;
    case 6: // Seven
      v = 7;
      break;
    case 7: // Eight
      v = 8;
      break;
    case 8: // Nine
      v = 9;
      break;
    case 9: // Ten
      v = 10;
      break;
    case 10: // Jack
      v = 10;
      break;
    case 11: // Queen
      v = 10;
      break;
    case 12: // King
      v = 10;
      break;
    default:
      v = 1;
      break;
  }
  return v;
}

/*@
    requires *stack_size > 0;
    requires \valid(stack + (0 .. *stack_size - 1));
    requires \valid(stack_size);
    requires \forall integer k; 0 <= k < *stack_size ==> stack[k] >= 0;
    assigns *stack_size;
    ensures \result >= 0;
    ensures 0 <= \result;
    ensures *stack_size == \old(*stack_size) - 1;
*/
int pop(int *stack, int *stack_size)
{
  int c = stack[(*stack_size - 1)];
  /*@ assert 0 <= (*stack_size - 1) < \at(*stack_size, Pre); */
  /*@ assert c >= 0; */
  (*stack_size)--;
  return c;
}