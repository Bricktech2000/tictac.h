# tictac.h

_Tiny portable single-header timing library_

`tictac.h` is a tiny single-header library that provides convenience macros for timing program fragments.

Annotate a statement with `TICTAC(label)` or surround a declaration or sequence of statements with `TIC(label);` and `TAC(label);` to output current and total elapsed CPU time.

```c
#include "tictac.h"

void work(void);

int main(void) {
  // start a timer labeled `main`
  TIC(main);

  // time a block then output
  TICTAC(loop)
  for (int i = 0; i < 8; i++)
    work();

  // output time since `TIC(main);`
  TAC(main);
  work();

  // time a block then output
  TICTAC(sub) {
    int i = 3;
    do
      // time an iteration then output
      TICTAC(iter) work();
    while (i--);
  }

  // output time since `TAC(main);`
  TAC(main);
}
```
