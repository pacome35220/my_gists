#!/bin/bash
OLDIFS="$IFS" # keep a backup here

data="$(curl -s 'https://api.github.com/users/pacome35220/gists')"

IFS=$' ' # parsing the string
urls="$(echo $data | jq -r .[].files | jq -r .[].raw_url)"
descriptions="$(echo $data | jq -r .[].description)"
nb_comments="$(echo $data | jq -r .[].comments)"
IFS=$'\n' # parsing the array
urls_arr=($urls)
descrip_arr=($descriptions)
nb_com_arr=($nb_comments)

index=0


for url in "${urls_arr[@]}"
do
	echo $url
    	gist="$(curl -s $url)"

    	filename="$(echo $url | cut -f8 -d /)"

	subfolder="${filename::-2}"
	mkdir "$subfolder" 2>/dev/null
	echo "${descrip_arr[index]}" > "$subfolder/README.md"

    	echo "$gist" > "$subfolder"/"$filename"

    	echo -e "\e[033m" "$filename" : "\e[32m" DONE "\e[0m\n"
	let "index+=1"
done
IFS="$OLDIFS"
