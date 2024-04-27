
void _string_deallocate(void *param_1)

{
  if (param_1 == (void *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Warning: Attempt to deallocate a NULL String object in string_deallocate.\n");
  }
  else {
    if (*(long *)((long)param_1 + 0x18) != 0) {
      _memory_pool_destroy(*(undefined8 *)((long)param_1 + 0x18));
      *(undefined8 *)((long)param_1 + 0x18) = 0;
    }
    _free(param_1);
    if ((_memoryPoolCreated & 1) != 0) {
      _destroy_global_memory_pool();
    }
  }
  return;
}

