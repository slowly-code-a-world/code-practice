#!/bin/csh

echo -n "enter the name of the file you wish to erase: "
set filename = $<
if (! (-w "$filename")) then
	echo you do not have permission to erase that file
else
	rm $filename
	echo file erased
endif
