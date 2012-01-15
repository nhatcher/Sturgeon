STEP01
======

There are two programs in this directory:

step01.R

step01.py

step01.cpp

The second is a python translation of the former.
To run the first program:

``Rscript step01.R``

to run the python program

``python step01.py``

Should work in all systems. Ask me if you need to compile and run the cpp program.

BENCHMARKS
==========

In my computer (linux 64 with 2Gb RAM )

``time Rscript step01.R``

``real    0m2.773s``

``time python step01.py``

``real    0m0.047s``

``time ./step01``

``real    0m0.005s``


Which mean that python is 60 times faster than R and C++ 10 times faster that python (~600 faster that R). Of course this means very little, if anything.

DESCRIPTION
===========

This is a very basic 100 year loop of population growth. 
It loads three csv files at the beginning (they are in the attachment). 

* "Initabundance" is the number of fish in each age class at the beginning of a simulation, 
* "Fecund" is the fecundity of each age class (how much eggs each fish of certain age produces), and 
* "Surv" is the annual survival of each age class (which percent of each age class survives in each year).

This code represents only females (there are no males in the model).
The code loads these three csv files, and then in a loop of 100 years

1) fish first reproduce, class abundance is multiplied with the fecundity
     ``spawn <- abundb * fecund - age``
2) then a certain number of eggs do not survive to the end of the year:
     ``spawn <- spawn * 0.0001``, 
3) then we get the total number of survived eggs produced by all fish:
     ``spawntot <- as.vector(sum(spawn))``
4) then certain number of fish die in that year:
      ``abunda <- abundb * surv``, 
5) and in the end of the loop fish age for one year (abundance of each age class is moved up for one year - e.g. abundance of age class 2 becomes the abundance of age class 3).