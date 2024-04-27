
long _string_back(long *param_1)

{
  long local_10;
  
  if ((param_1 == (long *)0x0) || (param_1[1] == 0)) {
    local_10 = 0;
  }
  else {
    local_10 = *param_1 + param_1[1] + -1;
  }
  return local_10;
}

