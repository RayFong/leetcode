#! /bin/bash

problem=''
if [[ $# != 1 ]]; then
	problem=`ls  -lt *.cpp | head -n 1 | awk '{print $9}'`
else
	problem="problem_${1}.cpp"
fi

cat ${problem}
