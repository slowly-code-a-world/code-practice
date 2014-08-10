#!/bin/csh

echo -n 'enter a number: '
set number = $<
if ($number < 0) then
	echo negative
else if ($number == 0) then
	echo zero
else 	echo positive
endif
