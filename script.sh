#! /bin/sh

if [ "$#" -le "0" ]
then
  echo "Usage : ./hgen <outputname>"
  exit
fi

output="$1".h
format=$(echo $output | sed 's/./\U&/g' | sed 's/\./_/g')
files=$(find . -name "*.c")

echo "#ifndef $format" > $output
echo "# define $format" >> $output
echo "" >> $output
sed -n '/^[^ ]*[ ]*[^ (]\+ [^ (]\+([^;]\+) *{* *$/p' $files | \
sed 's/ *{* *$/;/' >> $output
echo "" >> $output
echo "#endif /* !$format */" >> $output
