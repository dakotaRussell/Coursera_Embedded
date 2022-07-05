#include "data.h"
#include "memory.h"
#include <stdbool.h>

uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base){
  // No error checking - assume user is passing valid info.
  bool neg = false;
  if (data < 0){
    neg = true;
    data = -data;
  }

  int count = 0;
  do {
    *(ptr + count++) = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[data % base]; 
    data /= base;
  } while (data);
  if (neg)
     *(ptr + count++) = '-';
  *(ptr + count++) = '\0';
  
  ptr = my_reverse(ptr, count-1);
  return count;    
}

int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base){
  int val = 0;
  int dig;
  int digToAdd;
  bool neg = false;
  for (int i=0; i < digits-1; i++){
     if (i==0 && *(ptr+i) == '-'){
       neg = true;
     }
     else {
       dig = *(ptr + i);
       digToAdd = dig > '9'? dig-'A' : dig-'0';
       val = val*base + digToAdd;
     }
  }
  if (neg)
    val = -val;
  return val;
}
