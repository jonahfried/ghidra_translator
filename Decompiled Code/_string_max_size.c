
undefined8 _string_max_size(long param_1)

{
  undefined8 local_10;
  
  if (param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_max_size.\n");
    local_10 = 0;
  }
  else {
    local_10 = 0xffffffffffffffff;
  }
  return local_10;
}

