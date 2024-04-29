
undefined8 _string_length(long param_1)

{
  undefined8 local_10;
  
  if (param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_length.\n");
    local_10 = 0;
  }
  else {
    local_10 = *(undefined8 *)(param_1 + 8);
  }
  return local_10;
}

