# Leetcode Problem Solutions
a collection of leetcode problem solutions and a custom testing framework to test them.

works for Windows, but probably does not work for Mac or Linux.
  
To get it to work on Linux, you may only need to change the 'clean' rule in the Makefile to use '/' instead of '\\'.

## Build
use make in root folder to build

```bash
make
```

a debug version for use with gdb can also be made. (be sure to use make clean before)
```bash
make debug
```

## Usage
```bash
# run all tests on all problems
out/test -a

# run all tests on problem "NeedleInHaystack"
out/test -p NeedleInHaystack -a

# run test called "Leetcode Example 1" on problem "NeedleInHaystack"
out/test -p NeedleInHaystack "Leetcode Example 1"

# run all tests silently unless failure
out/test -a -v 0

# display test names on problem "NeedleInHaystack"
out/test -l NeedleInHaystack
```