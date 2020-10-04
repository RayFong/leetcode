#! /bin/bash

problem=''
if [[ $# != 1 ]]; then
	problem=`ls  -lt *.cpp | head -n 1 | awk '{print $9}'`
else
	problem="problem_${1}.cpp"
fi
echo "build [${problem}]..."

g++ -o solution ${problem} -g -Wall -std=c++11
