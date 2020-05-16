# ft_printf

*This project is part of the official curriculum at [School 42](https://en.wikipedia.org/wiki/42_(school)).*

## Overview


* [Official instructions](resources/ft_printf.en.pdf)
* The goal of this project is to practice the following concepts
	* variadic functions
	* dispatch tables – loose coupling and performance
	* void pointers – generic programming
	* optimization patterns – buffering
* The project (with the exception of tests) is consistent with the [Norme](resources/norme.en.pdf), the code standard accepted at *School 42*. In particular, this means that
	* no comments inline or inside functions
	* `for` loops and `switch` statements are forbidden
	* each function must be maximum 25 lines
* As per instructions, the project is realised using `libft` compiled during a previous [project](http://github.com/almayor/libft).

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
	* `ft_printf("{red} Color-print.{eoc} Normal print.")`
	* red, blue, yellow, green, cyan, magenta

## Tests

Run tests with `make test`

* Behaviour is tested with [Unity](https://github.com/ThrowTheSwitch/Unity)
* Performance is benchmarked against `printf(3)` 

## Acknowledgements

Many of the included tests are borrowed from [pft](https://github.com/gavinfielder/pft) by [gavinfielder](https://github.com/gavinfielder) and other contributors and [Moulitest](https://github.com/yyang42/moulitest) by [yyang42](https://github.com/yyang42) and other contributors. My thanks go to them.

---
If you have any questions, please contact me on Github.
