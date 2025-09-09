#include <stdio.h>
#include <time.h>

#define TICTAC_PREC 6
#define TICTAC_STREAM stderr

#define TIC(LABEL)                                                             \
  ; /* for labels */                                                           \
  clock_t _start_##LABEL = clock();                                            \
  static clock_t _total_##LABEL = 0
#define TAC(LABEL)                                                             \
  _start_##LABEL = clock() - _start_##LABEL,                                   \
  fprintf(TICTAC_STREAM, "%.*f\t%.*f\t%s\n", TICTAC_PREC,                      \
          _start_##LABEL * 1.0 / CLOCKS_PER_SEC, TICTAC_PREC,                  \
          (_total_##LABEL += _start_##LABEL) * 1.0 / CLOCKS_PER_SEC, #LABEL),  \
  _start_##LABEL = clock() /* exclude call to `fprintf` */
#define TICTAC(LABEL)                                                          \
  /* ISO/IEC 9899:TC3, $7.23.1 requires `clock_t` to be an arithmetic type */  \
  for (clock_t _start_##LABEL = clock(), _tictac = 1; _tictac; _tictac = 0)    \
    for (int _tictac = 0; _tictac < 2; _tictac++)                              \
      if (_tictac) {                                                           \
        static clock_t _total_##LABEL = 0;                                     \
        TAC(LABEL);                                                            \
      } else
