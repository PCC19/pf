#!/bin/bash
for f in *.c; do
    a="$(echo $f | sed 's/[.]c/_bonus.c/')"
    cp "$f" "$a"
done
