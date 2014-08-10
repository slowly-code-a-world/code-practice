#!/bin/csh

set x = 1
while ($x <= $1)
	set y = 1
	while ($y <= $1)
	@ v = $x * $y
	echo -n $v " "
	@ y ++
	end
	echo ""
	@ x ++
end
