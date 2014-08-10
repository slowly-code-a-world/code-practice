#!/bin/csh

echo -n "do you like the C shell? "
set reply = $<
if ($reply == "yes") then
	echo you entered yes
else if ($reply =~ y*) then
	echo I assume you mean yes
endif
