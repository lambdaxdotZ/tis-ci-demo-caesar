# Demo-caesar

A version of the *demo-caesar* repository for the purposes of testing the
*TiS-CI* prototypes.


## Command line

### Command to simply run test `$N` with `tis-interpreter`

```bash
tis-interpreter -tis-config-load tis.config -tis-config-select $N
```

### Full TiS-CI command for test `$N`

```bash
tis-interpreter\
  --no-color\
  -tis-config-restrict\
  -tis-config-load tis.config\
  -tis-config-select $N\
  --keep-results\
  -info-json-results test-results-$N.json
```

### Variables

Test numbers: `$N` = [1..9]


## Test suite

* Files `src/caesar.c` and `src/gen_test.c` must be always used.
* The `src` directory must be included with `-I src` in order to get headers
  `src/caesar.h` and `src/gen_test.h`.
* There are 3 test cases, each available in two forms:
  * Separate files `tests/test_01.c`, `tests/test_02.c`, and `tests/test_03.c`,
    each with a singl entry point `main`.
  * Single file `tests/three_tests.c` with three entry points `test_01`,
    `test_02`, and `test_03`.

### Tests cases

1. No undefined behavior.

   Exit value: **0**

   Result: **success**

2. Undefined behavior (out of bounds write).

   Exit value: **2**

   Result: **failure**

   > src/caesar.c:30:[kernel] warning: out of bounds write. assert \valid(buf+i);

3. Undefined behavior (signed overflow).

   Exit value: **2**

   Result: **failure**

   > src/caesar.c:16:[kernel] warning: signed overflow. assert -x ≤ 2147483647;

4. Same as `1.`

   *(Using file `tests/three_tests.c` with option `main` = `test_01`.)*

5. Same as `2.`

   *(Using file `tests/three_tests.c` with option `main` = `test_02`.)*

6. Same as `3.`

   *(Using file `tests/three_tests.c` with option `main` = `test_03`.)*

7. No entry point.

   Exit value: **2**

   Result: **error**

   > [kernel] user error: cannot find entry point 'main'.

8. Two entry points.

   Exit value: **0**

   Result: **success**

   Should be: **?**

   *The warning does not stop the analysis, so we in spite of having two entry
    points the analysis is concluded with success.*

   > tests/test_02.c:6:[kernel] warning: def'n of func main at tests/test_02.c:6
     conflicts with the one at tests/test_01.c:6; keeping the one at
     tests/test_01.c:6.

9. The `compilation_cmd` option missing.

   Exit value: **0**

   Result: **error**

   > src/gen_test.c:3:20: fatal error: caesar.h: No such file or directory

<3
