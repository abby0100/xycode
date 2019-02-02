#!/usr/bin/bash

target=xy

	rm $target
	#g++ tree.cpp -o $target
	g++ -std=c++1y tree.cpp -o $target
	./$target
