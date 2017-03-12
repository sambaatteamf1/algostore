# Misc coding exercises

## Dependencies

 - gcc and g++, gdb, gmake, valgrind
 - git
 - cmake (`apt-get install cmake`)
 - autoconf
 - cpputest (>= 3.8). Required to build collection submodule. May need to compile from source [ https://cpputest.github.io/ ]

## Build steps

1. Update submodules: 
   
   ```
   $ git submodule update --init --recursive
   ```
2. Build

   ```
   $ cmake .
   $ make 	
   ```

3. Test

   ```
   $ ./bin/compare-sort-list 100
   ```
