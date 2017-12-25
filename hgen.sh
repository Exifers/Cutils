#! /bin/sh

if [ "$#" -le 0 ]; then
  echo "Usage : ./hgen.sh <outputname> <search_dir>"
  exit
fi

if [ -z "$2" ]; then
  $2='.'
fi

output=$1.h
format=$(echo $output | sed 's/./\U&/g' | sed 's/\./_/g')
files=$(find $2 -name "*.c")

if [ -z "$files" ]; then
  exit
fi

echo "#ifndef $format" > $output
echo "# define $format" >> $output
echo "" >> $output
sed -n '/^[^ ]*[ ]*[^ (]\+ [^ (]\+([^;]\+) *{* *$/p' $files | \
sed 's/ *{* *$/;/' >> $output
echo "" >> $output
echo "#endif /* !$format */" >> $output
