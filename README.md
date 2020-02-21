# ft_printf

*This project is part of the official curriculum at [School 42](https://en.wikipedia.org/wiki/42_(school)).*

## Overview


* [Official instructions](resources/ft_printf.en.pdf)
* The goal of this project is to practice the following concepts
	* variadic functions
	* dispatch tables – loose coupling and performance
	* void pointers – generic functions
	* optimization patterns – buffering
* The project is consistent with the [Norme](resources/norme.en.pdf), a code standard accepted at *School 42*. In particular, this means that
	* no comments inline or inside functions
	* `for` loops and `switch` statements are forbidden
	* each function must be maximum 25 lines
* As per instructions, the project is realised using `libft` from a previous *School 42* project.

## Checklist

**_Standard_**

- [x] `csp%` conversions
- [x] `diouxX` conversions with `hh`, `h`, `l`, `ll` flags
- [x] `f` conversion with flags `L`, `l`
- [x] `#0-+ ` flag management (when applicable)
- [x] minimum field-width
- [x] precision
- [x] `*` flag management

**_Extra_**

- [x] `b` conversion to print in binary
- [x] variants of `printf`
	* `ft_dprintf`
	* `ft_vprintf`
	* `ft_vdprintf`
- [x] colors
	* `printf("{red} Color-print.{eoc} Normal print.")`
	* red, blue, yellow, green, cyan, magenta

## Tests

* Standard printf behaviour has been tested with [42FileChecker](https://github.com/jgigault/42FileChecker)
* Non-existing flags are tested with [Unity](https://github.com/ThrowTheSwitch/Unity)
	* `make tests`  

---
If you have any questions, please contact me on Github.