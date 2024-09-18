#include <stdio.h>
#include <time.h>

#define TICTAC_PREC 6
#define TICTAC_FILEP stderr

#define TIC(label)                                                             \
  ; /* for labels */                                                           \
  clock_t _start_##label = clock(), _elap_##label;                             \
  static clock_t _total_##label = 0
#define TAC(label)                                                             \
  _elap_##label = clock() - _start_##label, _start_##label += _elap_##label,   \
  fprintf(TICTAC_FILEP, "%.*f\t%.*f\t%s\n", TICTAC_PREC,                       \
          _elap_##label * 1.0 / CLOCKS_PER_SEC, TICTAC_PREC,                   \
          (_total_##label += _elap_##label) * 1.0 / CLOCKS_PER_SEC, #label)
#define TICTAC(label)                                                          \
  TIC(label);                                                                  \
  for (int _tictac = 1; _tictac; TAC(label), _tictac = 0)
