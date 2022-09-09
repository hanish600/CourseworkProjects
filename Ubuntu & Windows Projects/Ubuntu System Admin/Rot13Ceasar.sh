#!/bin/bash

# Display options for users
function menu()
{
	clear
	echo "========================="
	echo "      MAIN     MENU      "
	echo "========================="
	echo "1. Rot13 Algorithm"
	echo "2. Ceasar's Cipher"
	echo "3. Exit"
}

# Show options
# Extra checking for file and decrypt/encrypt not done
function read_options()
{
	local choice
	# collects file text or user phrase
	local phrase=""
	# Sets decryption or encryption algorithm
	local decrypt_or_encryp=""
	# get output name
	local output=""
	# Reads and sets user choices and phrases
	read -p "Enter choice [1-3]: " choice
	if [[ $choice == 3 ]]
	then
		exit 0
	fi
	
	# Get prompt
	read -p "Enter phrase or f for file: "  phrase
	# Opens user entered file
	if [[ $phrase == "f" ]] 
	then
		read -p "Enter filename: " phrase
		phrase= cat<$phrase
	fi
	# Ask user to enter output file
	read -p "Enter a output filename: " output
	read -p "1 for encrypt 2 for decrypt: " decrypt_or_encrypt
	clear
	case $choice in
		1) 
		if [[ $decrypt_or_encrpyt == 1 ]]
		then
			result=$(Rot13_encrypt $phrase)
			echo $result >> $output
		else
			result=$(Rot13_decrypt $phrase)
			echo $result >> $output
		fi ;;
		2) 
		local shifts
		read -p "Enter the shifts: " shifts
		if [[ $decrypt_or_encrypt == 1 ]] 
		then
			result=$(Ceasar $shifts $phrase)
			echo $result >> $output
		fi ;;
		3) exit 0 ;;
		*) continue ;;
	esac	
}

#
function Rot13_encrypt()
{
	echo $1 | tr '[a-z][A-Z]' '[n-za-m][N-ZA-M]'
}

function Rot13_decrypt()
{
	echo $1 | tr '[n-za-m][N-ZA-M]' '[a-z][A-Z]'
}

#
function Ceasar()
{
	# shift is starting from 0
	shift=$(( $shift - 1))
	# shift n places, 25=z, but 26=a
	shift=$(( $1 % 26))
	alphabet="abcdefghijklmnopqrstuvwxyz"
	alphabet2="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	# break tr into two parts
	# 1) Take the lower case letters and shift them by 
	# the alphabet's n character with 1 value in the alphabet
	# 2) pipe this into the same upper case letters
	echo $2 | tr '[a-z]' [${alphabet:shift:1}-za-${alphabet:shift-1:1}] | tr '[A-Z]' [${alphabet2:shift:1}-ZA-${alphabet2:shift-1:1}]
}


# Display menu and options
while true
do
	menu
	read_options
done
