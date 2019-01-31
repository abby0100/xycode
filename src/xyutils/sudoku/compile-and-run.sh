#!/usr/bin/bash

target=xy

	rm $target
	g++ sudoku.cpp -o $target
	#g++ -std=c++1y array.cpp -o $target
	./$target
