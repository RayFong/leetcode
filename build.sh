#! /bin/bash

problem=''
if [[ $# != 1 ]]; then
	problem=`ls  -lS --time-style=+%D *.cpp | head -n 1 | awk '{print $7}'`
else
	problem="problem_${1}.cpp"
fi
echo "build [${problem}]..."

g++ -o solution ${problem} -std=c++11
