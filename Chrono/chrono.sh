#!/bin/bash

#readVerifier(){
#	if [ $1

#~ intMaker(){
	#~ num=${1#"h"}
	#~ num=${num%"h"}
	#~ num=${1#"m"}
	#~ num=${num%"m"}
	
	#~ $integer=[int]$num
	#~ echo $integer
#~ }

secCounter(){	#hour min sec
	sec=1
	#~ if [ $1 = 0 ]; then hour="00";else hour=$1;fi
	#~ if [ $2 = 0 ]; then min="00"; else min=$2; fi

	while [ $3 -ne $sec ]
	do
		echo -ne "\tTime passed ${hour}:${min}:${sec}"\\r
		sec=`expr $sec + 1`
		#~ sleep 0.05
	done
	echo -ne "\t\t\t\t\t\t"\\r
}

minCounter(){	#hour min
	min=0
	while [ $2 -ne $min ]
	do
		secCounter $1 $min 60
		min=$((min + 1))
	done
}

hourCounter(){	#hour
	hour=0
	while [ $1 -ne $hour ]
	do
		minCounter $hour 60
		hour=$((hour + 1))
	done
}


echo "Hello! Please type the number of hours/minutes/seconds, than choose between them."
#~ echo "If you want to wait several seconds than type only the number"
echo
echo -n "How long to wait? "; read waitTime
echo -en "\033[4mS\033[0meconds, \033[4mm\033[0minutes, \033[4mh\033[0mours? "; read choice



sec=0; min=0; hour=0
secMax=60; minMax=60; hourMax=24

if [ $choice = h ] || [ $choice = H ]
then
	hourCounter $waitTime
elif [ $choice = m ] || [ $choice = M ]
then
	minCounter 0 $waitTime
else
	secCounter 0 0 $waitTime
fi

gnome-terminal -- sh -c "mpg123 finish.mp3; exit; bash"
sleep 2
echo -e '\n Done!'

#~ if [ ${waitTime: -1} = h ]
#~ then
	#~ hourCounter $time
#~ elif [ ${waitTime: -1} = m ]
#~ then
	#~ minCounter 0 $time
#~ else
	#~ secCounter 0 0 $time
#~ fi
