#!/bin/bash

# Variables
resources="./resources/"
testOutput="TestOutput_sh_"
validOutput="ValidOutput_sh_"
parcial="template"
inputs=($'500\n10' $'900\n100' $'50\n2')

clang -o "${parcial}.out" "${parcial}.c"

for i in ${!inputs[@]}; do
    output=$("./${parcial}.out" <<< "${inputs[$i]}")
    echo "$output" > "${resources}${testOutput}$((i+1)).txt"
done

for i in {1..3}
do
    file1="${resources}${validOutput}$i.txt"
    file2="${resources}${testOutput}$i.txt"

    if diff -q "$file1" "$file2" >/dev/null; then
        echo "Los archivos $file1 y $file2 son identicos."
    else
        echo "Los archivos $file1 y $file2 son diferentes."
    fi
done