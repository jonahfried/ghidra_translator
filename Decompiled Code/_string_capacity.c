
undefined8 _string_capacity(long param_1)

{
  undefined8 local_10;
  
  if (param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_capacity.\n");
    local_10 = 0;
  }
  else {
    local_10 = *(undefined8 *)(param_1 + 0x10);
  }
  return local_10;
}

