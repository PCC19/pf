#!/bin/bash
echo "=========================="
echo "Project Statistics:"
echo "=========================="

x=$(cat *.c | grep -Ev '^#|^//*' | wc -l)
echo "Numero de linhas (sem comentarios e includes): $x"

y=$(cat *.c | grep -E "^char|^int|^void|^static|^unsigned" | wc -l)
echo "Numero de funcoes: $y"

echo "Media de linhas / funcao:"
printf %.2f "$(( 100 * x / y))e-2"
echo

echo "Numero de funcoes por quantidade de parametros:"
cat *.c | grep -E "^char|^int|^void|^static|^unsigned" | awk -F ',' '{print NF}' | sort | uniq -c

