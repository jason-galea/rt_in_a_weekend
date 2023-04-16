#!/bin/bash

echo -e "\n==> Linecount for all *.cpp and *.h files:"
find . -type f \( -name "*.cpp" -o -name "*.h" \) | xargs -n1 cat | wc -l


echo -e "\n==> Linecount for all *.cpp and *.h files (Excluding blank lines & comments):"
find . -type f \( -name "*.cpp" -o -name "*.h" \) | xargs -n1 cat | grep -vE "^$|^\ *\/\/" | wc -l

echo
