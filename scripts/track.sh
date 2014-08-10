#!/bin/bash

pause=20
loopcount=10000
error=0

for arg in $*
do
  case $arg in
   -t*)
   pause=`expr substr $arg 3 10`
   ;;
   -n*)
   loopcount=`expr substr $arg 3 10`
   ;;
   *)
   user=$arg
   ;;
 esac	
done

if [ ! "$user" ]
then 
  error=1
fi

if [ $error -eq 1 ]
then
  cat << ENDOFERROR
usage: track [-n#] [-t#] userId
ENDOFERROR
  exit 1
fi

trap 'bash cleanup.sh $$; exit $exitcode' 0
trap 'exitcode=1; exit' 2 3
> .track.old.$$
count=0
while [ $count -lt $loopcount ]
do
 	who | grep $user | sort > .track.new.$$ 
	diff .track.new.$$ .track.old.$$ | \
	sed -f track.sed > .track.report.$$
	if [ -s .track.report.$$ ]
	then
		echo track report for $user
		cat .track.report.$$ 
	fi
	mv .track.new.$$ .track.old.$$
	sleep $pause
	count=`expr $count + 1`
done
exitcode=0
