# socho-sat

This is a really minor convenience tool I wrote in about 10 minutes to help out with my assignments in [15-816 Advanced Topics in Logic: Automated Reasoning and Satisfiability](http://www.cs.cmu.edu/~mheule/15816-f22/). I'm posting it here since someone told me they'd find this snippet useful.

I might add more functionality to this as I go, but this is really intended to be lightweight. I'm just trying to automate the process of output/some simple and common techniques so that I can focus on the harder part: finding efficient encodings.

Here is the current list of functionality:

  - There is a struct called `CNF` which all the functionality is built around. It contains:
    - A variable counter `var_count` which allows us to quickly generate unused variables with an associated `get_var` function.
    - A manual override to the number of variables in the formula, called `set_var_count`, in case you prefer to generate your own variables instead of using `get_var`.
    - A function to add a new clause to the CNF formula, called `add_clause`. Clauses are represented as vectors of literals (which are stored as `int` in C++). The literal `x` represents the variable `x` being set to `true` satisfies the clause, while the literal `-x` represents the variable `x` being set to `false` satsifes the clause.
    - A function `validate` to validate the formula by checking that all clauses contain only valid literals. This is automatically run on the output step, unless it is forced to not run.
    - A function `output_cnf` to output the CNF formula built to standard output. For now I intend to pipe it into files as necessary, but if it seems inconvenient, I will directly add a file-output function.
  - Apart from this, there is a function called `unsat` which simply generates an instance of `CNF` which is not satisfiable.

And here are some functions I am considering adding in the future:

  - A function `merge` to take two CNF formulae, and merge them into one larger formula, while either (a) allowing the option to use the same variables in both formula, or (b) allowing the option to renumber the variables of the second formula so the two formula are disjoint, or (c) allowing the option to specify a mapping of the variables in the first formula and second formula, which would preserve the overlapping variables and leave any unspecified variables disjoint. Perhaps this will instead become three separate functions, for convenience.

The easiest way to get started is to simply download the `template.cpp` file and start coding in the `main` function.
