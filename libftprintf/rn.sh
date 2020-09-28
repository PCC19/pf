#!/bin/bash
for f in *.c; do
    a="$(echo $f | sed s/trata/ft_conv/)"
    mv "$f" "$a"
done
