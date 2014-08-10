#!/bin/csh

echo menu test program
set stop = 0
while ($stop == 0)
cat << ENDOFMENU
1: print the date
2,3 : print the current working directory
4: exit
ENDOFMENU

echo 
echo -n 'your choice?'
set reply = $<
echo ""
switch ($reply)
	case "1":
 	date
	breaksw
	case "2":
	case "3":
	pwd
	breaksw
	case "4":
	set stop = 1
	breaksw
	default:
	echo illegal choice
	breaksw
endsw
end
