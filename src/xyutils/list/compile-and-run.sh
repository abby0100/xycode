#!/usr/bin/bash

target=xy

	rm $target
	#g++ list.cpp -o $target
	g++ -std=c++1y list.cpp -o $target
	./$target
