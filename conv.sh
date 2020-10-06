#  MaxRev © 2020
# converts old endcoding for github 
# cp1251 to utf8
find "${1}"  -type f \( -iname \*.cpp -o -iname \*.h \) -exec sh -c '
  for file do
    echo "$file"
    iconv -f cp1251 -t utf-8 "$file" >"$file.new" &&
    mv -f "$file.new" "$file"
  done
' exec-sh {} +