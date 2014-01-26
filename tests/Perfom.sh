PerfomADD=$1
name=""
no=0
max=$2

while test $no != $max
	do
	name=circle"$no"
	commande="C "$name" 12 13 11"
	if test $no = 0
	then echo $commande > $PerfomADD
	else echo $commande >> $PerfomADD
	fi
	no=$(($no+1))
done

no=0
while test $no != $max
	do
	name=rectangle"$no"
	commande="R "$name" 134 170 80 90"
	echo $commande >> $PerfomADD
	no=$(($no+1))
done

#no=0
#while test $no != $max
#	do
#	name=polyline"$no"
#	commande="PL "$name" 134 170 80 90 123 222 345 555 "
#	echo $commande >> $PerfomADD
#	no=$(($no+1))
#done 

no=0
while test $no != $max
	do
	name=agg"$no"
	commande="OA "$name" circle$no  rectangle$no" 
	echo $commande >> $PerfomADD
	no=$(($no+1))
done

no=0
while test $no != $max
	do
	name=aggBis"$no"
	commande="OA "$name" agg$no circle$no" 
	echo $commande >> $PerfomADD
	no=$(($no+1))
done

#AU Grand jamais oublier le exit !
echo LIST >> $PerfomADD
echo exit >> $PerfomADD
