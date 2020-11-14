<!-- SPDX-License-Identifier: X11 -->
# Fun in Z

An almost complete jab at a few fun algorithms, written as the final project for ANU's
[COMP3600](https://cs.anu.edu.au/courses/comp3600/), 2020 S2. As with most of my repos, don't expect it to work. _Do_,
however, expect it to chew your memory where you mightn't expect :)

## Usage

Compile with `make` by issuing the following in the root directory of the repository.

```shell
$ make
```

If `make` is not installed, manual compilation is possible by issuing the following commands. This assumes use of
`bash`.

```shell
$ for i in src/**/*.c; do gcc -O2 -lm -c -o ${i/.c/.o} $i; done
$ gcc -fuse-ld=gold -flto -O2 -lm -o zfun src/**/*.o
```

Compilation tested on Arch Linux with:

- [GNU Make](https://www.gnu.org/software/make/) 4.3
- [GCC](http://gcc.gnu.org/) 10.2.0
- [GNU C Library](https://www.gnu.org/software/libc/) 2.32
- [GNU gold](https://www.gnu.org/software/binutils/) 1.16

Invoking the compiled binary with no arguments, or `-i` will expose the REPL; note that doing so without specifying
input files will raise an error. Upon entering the REPL, inputs up to a maximum are loaded into a hash table.

```shell
$ ./zfun [files...]

Enter one digit 0-6.

1. Quit
2. Add point
3. Retrieve point
4. Minimum spanning tree (All)
5. Minimum spanning tree (Selected)
6. Convex hull (All)
7. Convex hull (Selected)

>

# Equivalent
$ ./zfun -i [files...]
```

Subsequent instructive prompts will be offered upon interaction with each menu option.

Invoking with `-m` activates the command line interface for the minimum spanning tree algorithm; it will operate on all
data points up to a maximum in the inputs. By default, the command line interface will write output to `output.txt`.

```shell
$ ./zfun -m [files...]
```

Invoking with `-c` activates the command line interface for the convex hull algorithm; it will operate on all data
points up to a maximum in the inputs. By default, the command line interface will write output to `output.txt`.

```shell
$ ./zfun -c [files...]
```

HTML documentation may be generated with [Doxygen](https://www.doxygen.nl/index.html) by issuing the following in the
root directory.

```shell
$ doxygen Doxyfile
```

## License

Copyright 2020 Elias Yuan <a@jthv.ai>, [MIT/X11 License](./LICENSE).

<!-- markdownlint-disable-file commands-show-output -->
