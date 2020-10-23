#! /bin/bash

timeout --preserve-status 1 ./solution $@
code=$?
if [[ $code -ne 0 ]]; then 
	echo "run ./solution $@ failed, error code is $code"
fi
