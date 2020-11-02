<!-- SPDX-License-Identifier: X11 -->
# Fun in Z

- [Fun in Z](#fun-in-z)
  - [Usage](#usage)
  - [License](#license)

## Usage

Compile with `make` by issuing the following in the root directory of the repository.

```shell
$ make
```

If `make` is not installed, manual compilation is possible by issuing the following commands. This assumes use of
`bash`.

```shell
$ for i in src/**/*.c; do gcc -c -o ${i/.c/.o} $i; done
$ gcc -o zfun src/**/*.o
```

Compilation tested on Arch Linux with:

- [GNU Make](https://www.gnu.org/software/make/) 4.3
- [GCC](http://gcc.gnu.org/) 10.2.0
- [GNU C Library](https://www.gnu.org/software/libc/) 2.32

Invoking the compiled binary with no arguments, or `-i` will expose the REPL (incomplete).

```shell
$ ./zfun

Enter one digit 0-6.

0. Quit
1. Add point
2. Retrieve point
3. Minimum spanning tree (All)
4. Minimum spanning tree (Selected)
5. Convex hull (All)
6. Convex hull (Selected)

>

# Equivalent
$ ./zfun -i
```

Invoking with input files will parse those inputs (incomplete).

```shell
$ ./zfun [files...]
```

Invoking with `-m` activates the command line interface for the minimum spanning tree algorithm (incomplete).

```shell
$ ./zfun -m [files...]
```

Invoking with `-c` activates the command line interface for the convex hull algorithm (incomplete).

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
