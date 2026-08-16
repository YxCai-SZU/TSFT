// Generated C + ACSL

typedef enum {
    Buy = 0,
    Sell = 1,
    Ignore = 2
} Trend;

typedef struct {
    int *close;
    int close_len;
    int ema;
    double macd;
    double macdSignal;
} MarketData;

/*@
    assigns \nothing;
    ensures \result == 0 || \result == 1 || \result == 2;
    ensures \result == 0 ==> currentPrice > ema;
    ensures \result == 1 ==> currentPrice < ema;
    ensures \result == 2 ==> currentPrice == ema;
*/
int GetPriceTrend(int currentPrice, int ema)
{
  int trend;
  if ((currentPrice > ema))
  {
    trend = Buy;
    /*@ assert trend == 0; */
  }
  else
  if ((currentPrice < ema))
  {
    trend = Sell;
    /*@ assert trend == 1; */
  }
  else
  {
    trend = Ignore;
    /*@ assert trend == 2; */
  }
  /*@ assert trend == 0 || trend == 1 || trend == 2; */
  return trend;  // Dafny implicit return
}

/*@
    requires macd < macdSignal || macd > macdSignal || macd == macdSignal;
    assigns \nothing;
    ensures \result == 0 || \result == 1 || \result == 2;
    ensures \result == 0 ==> macd > macdSignal;
    ensures \result == 1 ==> macd < macdSignal;
    ensures \result == 2 ==> macd == macdSignal;
*/
int GetMACDTrend(int macd, int macdSignal)
{
  int trend;
  if ((macd > macdSignal))
  {
    trend = Buy;
    /*@ assert trend == 0; */
  }
  else
  if ((macd < macdSignal))
  {
    trend = Sell;
    /*@ assert trend == 1; */
  }
  else
  {
    trend = Ignore;
    /*@ assert trend == 2; */
  }
  /*@ assert trend == 0 || trend == 1 || trend == 2; */
  return trend;  // Dafny implicit return
}

/*@
    requires data.close_len >= 1;
    requires \valid(data.close + (data.close_len - 1));
    assigns \nothing;
*/
void GetSignal(MarketData data)
{
  int currentPrice = data.close[(data.close_len - 1)];
  int priceTrend = GetPriceTrend(currentPrice, data.ema);
  /*@ assert priceTrend == 0 || priceTrend == 1 || priceTrend == 2; */
  int macdTrend;
  if (((data.macd < 0.0) && (data.macdSignal < 0.0)))
  {
    /*@ assert (int)data.macd < (int)data.macdSignal || (int)data.macd > (int)data.macdSignal || (int)data.macd == (int)data.macdSignal; */
    macdTrend = GetMACDTrend((int)data.macd, (int)data.macdSignal);
    /*@ assert macdTrend == 0 || macdTrend == 1 || macdTrend == 2; */
  }
  else
  {
    macdTrend = Ignore;
    /*@ assert macdTrend == 2; */
  }
  /*@ assert macdTrend == 0 || macdTrend == 1 || macdTrend == 2; */
  int prevMacdTrend;
  if (((data.macd < 0.0) && (data.macdSignal < 0.0)))
  {
    /*@ assert (int)data.macd < (int)data.macdSignal || (int)data.macd > (int)data.macdSignal || (int)data.macd == (int)data.macdSignal; */
    prevMacdTrend = GetMACDTrend((int)data.macd, (int)data.macdSignal);
    /*@ assert prevMacdTrend == 0 || prevMacdTrend == 1 || prevMacdTrend == 2; */
  }
  else
  {
    prevMacdTrend = Ignore;
    /*@ assert prevMacdTrend == 2; */
  }
  /*@ assert prevMacdTrend == 0 || prevMacdTrend == 1 || prevMacdTrend == 2; */
}