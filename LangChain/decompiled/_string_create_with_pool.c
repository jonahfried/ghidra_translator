
undefined8 * _string_create_with_pool(undefined8 param_1)

{
  undefined8 *puVar1;
  
  if (_string_create_with_pool_counter == 0) {
    _init_global_memory_pool(param_1);
    _string_create_with_pool_counter = _string_create_with_pool_counter + 1;
  }
  if (_global_pool == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Failed to initialize global memory pool in string_create_with_pool.\n");
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  puVar1 = (undefined8 *)_malloc(0x20);
  if (puVar1 == (undefined8 *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Memory allocation failed for String object in string_create_with_pool.\n");
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  puVar1[1] = 0;
  puVar1[2] = 1;
  *puVar1 = 0;
  puVar1[3] = _global_pool;
  return puVar1;
}

