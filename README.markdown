Numerical Semigroup Graphs
==========================

When looking at all the irreducible numerical semigroups
with a shared frobenius number it is possible to generate
all of the semigroups from a seed value. In this way it is 
possible to create a tree of them. In an attempt to study 
these trees it became necessary to generate the actual
graphs, and this software does just that. It generates dot
files to be read by the graphviz software. Additionally it
calculates the total number of nodes, how tall the tree is,
and how many branches it contains. 

The algorithm used was discovered [in this paper](https://arxiv.org/abs/1105.2147)
by V. Blanco and J.C. Rosales.

The current software is incomplete (I managed to delete our
old code base through a careless rm -rf) features it will 
have re-added shortly:
* dot file rendering
* output of data in csv and latex table formats
* multithreaded graph generation
* comments which explain what is going on
