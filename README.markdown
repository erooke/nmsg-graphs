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
and how many branches it contains. (In its current iteration
it is not rendering the dot files that should be readded 
shortly)

The algorithm used was discovered [in this paper](https://arxiv.org/abs/1105.2147)
by V. Blanco and J.C. Rosales.
