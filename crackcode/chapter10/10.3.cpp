/*
10.3 Given an input file with four billion non-negative integers, provide an algorithm
    to generate an integer which is not contained in the file. Assume you have 1 GB
   of memory available for this task.
FOLLOW UP
What if you have only 10 MB of memory? Assume that all the values are distinct
and we now have no more than one billion non-negative integers.
*/

// use map with size 4G+1, store exist or not, then travesal the map to find which is not true. map can use array and bit operations
