file=$1.h

echo "#ifndef FOO" > $file
echo "# define FOO" >> $file
echo "" >> $file
sed -n '/^[^ ]*[ ]*[^ (]\+ [^ (]\+([^;]\+) *{* *$/p' * | sed 's/ *{* *$/;/' \
>> $file
echo "" >> $file
echo "#endif /* !FOO */" >> $file
