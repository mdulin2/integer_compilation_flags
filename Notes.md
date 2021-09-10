## Overview
- Integer bugs are interesting and the root of A LOT of problems in this world...
- Can we cause them to crash or detect them at compile time? Below is a list of interesting things to look for.
- The overflow check (ftrapv) checking only works on signed integers (so, not floats and unsigned ints).:
	- DAMN!? I wish this worked on unsigned values as well :( 
- tldr; 
	- I would use ``Wsign-conversion, Wconversion, ftrapv`` for GCC. Everything else looks like a bunch of fluff that causes an insane amount of warnings and nothing else. 
	- In clang, I would use the same flags as GCC plus the added '-fsanitize=integer' to add MUCH MUCH more dynamic bug finding at run time. 

## Flags

All of these flags apply to BOTH gcc and clang. 

### Wsign-conversion
- WARNING for implicit conversions that may change the sign of an integer value. 
- int a = (unsigned int) b; 

### Wconversion
- WARNING for implicit conversions that MAY alter a value. 
- This mostly deals with literals and type issues, instead of signed-ness issues. 
- char d = (char c) + 1; // Causes issues because of weird type conversion things. 
- unsigned ui = -1;

### -Warith-conversion 
- WARNING about implicit conversions from arithmetic operations even when conversion of the operands to the same type cannot change their values. 
- Not the most useful flag and produces a TON of false positives. 

### -Wfloat-conversion
- WARNING for implicit conversions that reduce the precision of a real value. 
- This will likely never cause any real issues... but, interesting to know about!
- float a = (double b); 

### ftrapv/ fsanitize=signed-integer-overflow
- CRASH on signed integer overflows/underflows on addition, multiplication and subtraction. 
- Does NOT catch unsigned bugs though. Could add support? Lolz
- Super useful for fuzzing and detecting signed overflows :) 

### fsanitize=float-cast-overflow
- Ensure conversions between integer and floats produce expected values. 

### Wstrict-overflow=5
- WARNING for when the compiler optimizes out the potential for overflows in the code. 
- Could be useful for detecting overflows? But, at the same time, I do not feel like it's worth the time to go through. Probably not worth the time.


### Shifts
- There are some other flags for shifts as well...
	- -Wshift-overflow=2: static checking at compile time
	- -fsanitize=shift: Checks that the exponent and base are in the proper range on a shift operation. 

## Clang specialties!
- All of the abvoe flags work in clang AND GCC. However, there are a collection of dynamic runtime flags that change how the program in ran. This is PERFECT for fuzzing. 

### -fsanitize=integer
- Integer related issues such as overflows and underflows and truncation bugs during conversion. 
-fsanitize=integer: Adds instrumention for unsigned integer overflows. This will check for signed integer overflows, unsigned integer overflows, shift issues, divide by zeros, integer truncation and sign change issues. 
- The main difference is that the integer flags (listed below) are found at RUNTIME, which is great for a fuzzer for detecting bugs. 
	- signed-integer-overflow
	- unsigned-integer-overflow
	- implicit-unsigned-integer-truncation
	- implicit-signed-integer-truncation
	- implicit-integer-sign-change



## Resources
- GCC compilation links: 
	- https://gcc.gnu.org/onlinedocs/gcc/Instrumentation-Options.html
	- https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
	- https://gcc.gnu.org/onlinedocs/gcc/Integer-Overflow-Builtins.html
- GCC Compilation Flags cheatsheet: 
	- https://airbus-seclab.github.io/c-compiler-security/gcc_compilation.html
- Clang Compilation Flags cheatsheet: 
	- https://airbus-seclab.github.io/c-compiler-security/clang_compilation.html
- UBSAN in Clang: 
	- https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html
- Example of truncation: 
	- Could have been caught by simply adding flags and looking around :) 
	- https://www.qualys.com/2021/07/20/cve-2021-33909/sequoia-local-privilege-escalation-linux.txt
- Overflow example: 
	- https://research.checkpoint.com/2021/i-can-take-over-your-kindle/
