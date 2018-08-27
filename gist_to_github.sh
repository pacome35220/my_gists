#!/bin/bash
OLDIFS="$IFS" # keep a backup here

data="$(curl -s 'https://api.github.com/users/pacome35220/gists')"

IFS=$' ' # parsing the string
urls="$(echo $data | jq -r .[].files | jq -r .[].raw_url)"
descriptions="$(echo $data | jq -r .[].description)"
nb_comments="$(echo $data | jq -r .[].comments)"
comments_urls="$(echo $data | jq -r .[].comments_url)"

IFS=$'\n' # parsing the array
urls=($urls)
descriptions=($descriptions)
nb_comments=($nb_comments)
comments_urls=($comments_urls)

index=0

for url in "${urls[@]}"
do
	gist="$(curl -s $url)"

	filename="$(echo $url | cut -f8 -d /)" # parse url to get filename

	subfolder="${filename::-2}" # remove ".c"
	mkdir "$subfolder" 2>/dev/null # create directory for each gist

	echo "${descriptions[index]}" > "$subfolder/README.md" # write gist description
	echo "$gist" > "$subfolder"/"$filename" # write code
	if [ "${nb_comments[index]}" -ne 0 ]
	then
	    comment="$(curl -s ${comments_urls[index]})"
	    comment_body="$(echo $comment | jq -r .[].body)"
	    echo -e "---------------\n\n" >> "$subfolder/README.md"
	    echo "$comment_body" >> "$subfolder/README.md"
	fi

	echo -e "\e[033m" "$filename" : "\e[32m" DONE "\e[0m\n"
	let "index+=1"
done
IFS="$OLDIFS"
