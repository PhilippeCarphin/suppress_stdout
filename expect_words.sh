#!/bin/bash

cmd=$1
expected=$2
words=$($1 | wc | awk '{print $2}')

if [[ "$words" != "$expected" ]] ; then
    exit 8
fi
