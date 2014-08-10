#!/bin/csh

onintr controlC
while(1)
	echo infinite loop
	sleep 2
end
controlC:
echo control C detected
