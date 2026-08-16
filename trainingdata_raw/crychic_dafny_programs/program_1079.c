// Generated C + ACSL

typedef enum {
  GodCow,
  EvilCow,
  Satan,
  DevilGirl,
  Demon,
  Hex
} Symbol;

typedef struct {
  int bank;
  int currentBet;
  int MIN_BET;
  int MAX_BET;
  Symbol result[3];
  int payout;
} SlotMachine;

/*@
  predicate Valid(SlotMachine* this) =
    \valid(this) &&
    \valid(this->result + (0..2)) &&
    this->bank >= 0 && this->MIN_BET > 0 && this->MAX_BET > this->MIN_BET &&
    this->currentBet >= this->MIN_BET && this->currentBet <= this->MAX_BET;
*/

/*@
    requires amount + *bank >= 0;
    assigns *bank;
*/
void UpdateBank(int* bank, int amount)
{
  *bank = (*bank + amount);
  /*@ assert *bank >= 0 && *bank <= 2147483647; */
}

/*@
    requires symbols != \null;
    requires symbols_len == 3;
    requires \valid_read(symbols + (0 .. symbols_len-1));
    assigns \nothing;
    ensures \result >= 0;
*/
int CalculatePayout(Symbol* symbols, int symbols_len)
{
  int payout = 0;
  /*@ assert payout >= 0 && payout <= 2147483647; */
  if (((symbols[0] == symbols[1]) && (symbols[1] == symbols[2])))
  {
    switch (symbols[0]) {
      case GodCow:
        payout = 30;
        break;
      case EvilCow:
        payout = 6;
        break;
      case Satan:
        payout = 50;
        break;
      case DevilGirl:
        payout = 20;
        break;
      case Demon:
        payout = 10;
        break;
      case Hex:
        payout = 4;
        break;
      default:
        payout = 1;
        break;
    }
  }
  else
  {
    int i = 0;
/*@
  loop invariant 0 <= i <= 2;
  loop invariant payout >= 0;
  loop invariant payout == 0 || payout == 2 || payout == 4 || payout == 20;
  loop invariant i > 0 ==> (payout >= \at(payout, LoopEntry));
  loop assigns i, payout;
  loop variant 2 - i;
*/
    while ((i < 2))
      {
        if ((((i + 1) < symbols_len) && (symbols[i] == symbols[(i + 1)])))
        {
          switch (symbols[i]) {
            case GodCow:
              payout = 20;
              break;
            case EvilCow:
              payout = 4;
              break;
            case Hex:
              payout = 2;
              break;
            default:
              payout = 0;
              break;
          }
        }
        i = (i + 1);
      }
  }
  return payout;
}

/*@
    requires Valid(this);
    requires this->bank >= this->currentBet;
    assigns this->bank, this->result[0..2], this->payout;
    ensures this->bank == \old(this->bank) - \old(this->currentBet) + this->payout;
    ensures Valid(this);
*/
void Spin(SlotMachine* this)
{
  this->bank = (this->bank - this->currentBet);
  /*@ assert this->bank >= 0 && this->bank <= 2147483647; */
  this->result[0] = Hex;
  this->result[1] = Demon;
  this->result[2] = Satan;
  /*@ assert \valid_read(this->result + (0..2)); */
  /*@ assert this->result != \null; */
  this->payout = CalculatePayout(this->result, 3);
  /*@ assert this->payout >= 0 && this->payout <= 2147483647; */
  this->bank = (this->bank + this->payout);
}