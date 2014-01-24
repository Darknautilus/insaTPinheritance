echo -----------------------------------------------------------
echo Tests pour le binome : $1
echo -----------------------------------------------------------

nTestCount=0
nSuccesfulTests=0
nStrResult="$1 "

echo ADD.1
let "nTestCount=$nTestCount+1"
./$1 < ADD.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB ADD.out temp1.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo MOVE.1
let "nTestCount=$nTestCount+1"
./$1 < MOVE.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB MOVE.out temp1.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo DELETE.1
let "nTestCount=$nTestCount+1"
./$1 < REMOVE.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB REMOVE.out temp1.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo UNDO.1
let "nTestCount=$nTestCount+1"
./$1 < UNDO-REDO.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB UNDO-REDO.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo -----------------------------------------------------------
echo RESULTS
echo -----------------------------------------------------------
echo Results: $nSuccesfulTests/$nTestCount
echo CSVLine: $nStrResult
echo $nStrResult >> results.txt
