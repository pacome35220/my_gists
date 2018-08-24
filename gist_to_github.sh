data="$(curl -s 'https://api.github.com/users/pacome35220/gists')"

urls=$(echo $data | jq -r .[].files | jq -r .[].raw_url)
descriptions=$(echo $data | jq -r .[].description)
nb_comments=$(echo $data | jq -r .[].comments)

for url in $urls
do
    tmp=$IFS
    IFS=''

    gist="$(curl -s $url)"

    filename=$(echo $url | cut -f8 -d /)

    subfolder=${filename::-2}
    mkdir $subfolder 2>/dev/null

    echo $gist > $subfolder/$filename

    IFS=$tmp
    echo -e "\e[033m" $filename : "\e[32m" DONE "\n"
done
