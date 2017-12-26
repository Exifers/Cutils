#! /bin/sh

if [ "$#" -le 0 ]; then
  echo "Usage : ./hgen.sh <outputname> <search_dir>"
  exit
fi

if [ -z "$2" ]; then
  $2='.'
fi

files=$(find $2 -name "*.c" -type f)

if [ -z "$files" ]; then
  exit
fi


for file in $files; do

  output=$(echo $file | sed 's/\.c$/\.h/g')
  echo $output
  basename=$(echo $output | grep -e '\/[^\/]\+$' -o | grep -e '[^\/]*' -o)
  format=$(echo $basename | sed 's/./\U&/g' | sed 's/\./_/g')
  
  echo "#ifndef $format" > $output
  echo "# define $format" >> $output
  echo "" >> $output
  sed -n '/^[^ ]*[ ]*[^ (]\+ [^ (]\+([^;]\+) *{* *$/p' $file | \
  sed 's/ *{* *$/;/' >> $output
  echo "" >> $output
  echo "#endif /* !$format */" >> $output

done
