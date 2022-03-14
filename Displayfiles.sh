#! /bin/bash

echo $1 

cd $1



Filesindir()
{
	cd $dir
	for dir in *
	do
		if [ -d $dir ]
		then
			Filesindir $dir
		elif [ -f $dir ]
		then
			echo $dir
		fi
	done
	cd ..
}

			
	
for dir in *
do
	if [ -d $dir ]
	then
		Filesindir $dir
	

	elif [ -f $dir ]
	then
		echo $dir
	fi

done

