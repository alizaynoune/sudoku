# sudoku
solving sudoku puzzle with backtracking

0 ==>> run make


1 ==>> 	./sudoku [file sudoku] or ./sudoku [flag1] or/and [flag2] [file sudoku]

	==> flags: -s[time milliseconds] ==> slow solving
		 : -S[time seconds] ==> time between each result "work whit many files"
	
example:
		./sudoku maps/easy
	or
		./sudoku -s100000 maps/easy
	or
		./sudoku -S2 maps/easy maps/su

2 ==>> example file sudoku
	|2 1 0 3 9 0 4 0 5|
	|0 9 0 0 0 7 0 0 2|
	|0 0 3 2 8 0 0 1 0|
	|0 0 1 0 0 2 0 0 4|
        |0 4 0 8 3 0 0 2 7|
	|8 2 0 0 4 0 1 0 3|
	|0 0 0 0 1 0 7 3 8|
	|0 8 0 0 6 3 2 0 0|
	|3 0 4 9 0 0 0 5 1|
	
	or you can find it in folder 'maps'
