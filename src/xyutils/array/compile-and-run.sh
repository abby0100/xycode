#!/usr/bin/bash

target=xy

	rm $target
	#g++ array.cpp -o $target
	g++ -std=c++1y array.cpp -o $target
	./$target
