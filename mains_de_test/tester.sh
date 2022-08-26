#!/bin/bash

echo -e "\n\t\t#MAP#";
for filename in ./map/*.cpp; do
	c++ -Wall -Wextra -Werror -std=c++98 $filename && ./a.out | grep -v "max_size" > std_vector.out
	c++ -Wall -Wextra -Werror -std=c++98 -D NAME_SPACE="ft" $filename && ./a.out | grep -v "max_size" > ft_vector.out
	echo $filename | rev | cut -d '/' -f 1 | rev | sed "s/.cpp//g" | sed "s/_/ /g" | tr '\n' ' ';
	echo -ne "\t\t\t:\t";
	diff std_vector.out ft_vector.out > /dev/null
	if (($? == 0))
	then
		echo "✅";
	else
		echo "❌";
	fi
	rm *.out
done

echo -e "\n\t\t#VECTOR#";
for filename in ./vector/*.cpp; do
	c++ -Wall -Wextra -Werror -std=c++98 $filename && ./a.out > std_vector.out
	c++ -Wall -Wextra -Werror -std=c++98 -D NAME_SPACE="ft" $filename && ./a.out > ft_vector.out
	echo $filename | rev | cut -d '/' -f 1 | rev | sed "s/.cpp//g" | sed "s/_/ /g" | tr '\n' ' ';
	echo -ne "\t\t\t:\t";
	diff std_vector.out ft_vector.out > /dev/null
	if (($? == 0))
	then
		echo "✅";
	else
		echo "❌";
	fi
	rm *.out
done

echo -e "\n\t\t#STACK#";
for filename in ./stack/*.cpp; do
	c++ -Wall -Wextra -Werror -std=c++98 $filename && ./a.out > std_vector.out
	c++ -Wall -Wextra -Werror -std=c++98 -D NAME_SPACE="ft" $filename && ./a.out > ft_vector.out
	echo $filename | rev | cut -d '/' -f 1 | rev | sed "s/.cpp//g" | sed "s/_/ /g" | tr '\n' ' ';
	echo -ne "\t\t\t:\t";
	diff std_vector.out ft_vector.out > /dev/null
	if (($? == 0))
	then
		echo "✅";
	else
		echo "❌";
	fi
	rm *.out
done
