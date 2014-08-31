/*
6.5
There is a building of 100 floors. If an egg drops from the Nth floor or above, it
will break. If it's dropped from any floor below, it will not break. You're given two
eggs. Find N, while minimizing the number of drops for the worst case.
*/

/*drop first at middle, if it is broken, drop the other from 1th until it is broken,
if the first is not broken, drop it at 3/4 place, if is broken, drop the 2nd from 1/2,
if the first is not broken, drop it at 7/8 place, ..*/
