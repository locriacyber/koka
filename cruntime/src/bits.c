/*---------------------------------------------------------------------------
  Copyright 2020 Daan Leijen, Microsoft Corporation.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the file "license.txt" at the root of this distribution.
---------------------------------------------------------------------------*/
#include "runtime.h"

static const uintx_t powers_of_10[] = { 
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
#if (INTPTR_SIZE > 4)
  , 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000
  , 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000
  , 10000000000000000000, 10000000000000000000
#endif
};

uint8_t bits_digits32(uint32_t u) {
  static const uint8_t guess[33] = {
    1, 0, 0, 0, 1, 1, 1, 2, 2, 2,
    3, 3, 3, 3, 4, 4, 4, 5, 5, 5,
    6, 6, 6, 6, 7, 7, 7, 8, 8, 8,
    9, 9, 9
  };
  uint8_t count = guess[32 - bits_clz32(u)];
  return (count + (u >= powers_of_10[count] ? 1 : 0));
}

uint8_t bits_digits64(uint64_t u) {
  static const uint8_t guess[65] = {
    1, 0, 0, 0, 1, 1, 1, 2, 2, 2,
    3, 3, 3, 3, 4, 4, 4, 5, 5, 5,
    6, 6, 6, 6, 7, 7, 7, 8, 8, 8,
    9, 9, 9, 9,10,10,10,11,11,11,
   12,12,12,12,13,13,13,14,14,14,
   15,15,15,15,16,16,16,17,17,17,
   18,18,18,18,19
  };
  uint8_t count = guess[64 - bits_clz64(u)];
  return (count + (u >= powers_of_10[count] ? 1 : 0));
}
