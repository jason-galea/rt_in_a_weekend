#!/bin/bash

echo -e "\n==> Searching for '*.cpp' and '*.h' files in '$PWD'"
CPP_FILES=$(find . -type f \( -name "*.cpp" -o -name "*.h" \) | sort)

echo -e "\n==> Linecount for individual files:"
echo $CPP_FILES | xargs -n1 wc -l

echo -e "\n==> Linecount for individual files (Excluding blank lines & comments):"
for FILE in $CPP_FILES; do
    echo "$(grep -vE '^$|^\ *\/\/' $FILE | wc -l) $FILE"
done

echo -e "\n==> Total linecount:"
echo $CPP_FILES | xargs -n1 cat | wc -l

echo -e "\n==> Total linecount (Excluding blank lines & comments):"
echo $CPP_FILES | xargs -n1 cat | grep -vE '^$|^\ *\/\/' | wc -l

echo
