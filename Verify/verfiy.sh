#! /bin/bash

files_path=files/*
checksum_file_path=checksum.txt

checksum=$(cat $checksum_file_path)

# for each file in folder files 
for file in $files_path; do 
        #check if checksum is the same as in the checksum.txt file
        if [ "$(sha256sum $file | cut -d ' ' -f1)" == "$checksum" ];then
                # Decrypt the  file to print the flag
                echo $(openssl enc -d -aes-256-cbc -pbkdf2 -iter 100000 -salt -in "$file" -k picoCTF)
                break
        fi
done
