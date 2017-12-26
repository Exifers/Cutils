#! /bin/sh

files=$(find $1 -name "*.c" -type f)

if [ -z "$files" ]; then
  echo "no *.c has been found"
  exit
fi


for file in $files; do

  output=$(echo $file | sed 's/\.c$/\.h/g')
  echo "generating $output"
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
