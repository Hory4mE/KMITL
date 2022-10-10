fileName="progA.c progB.c progC.c"
for i in $fileName; 
    do
    prog_name=$(echo $i | cut -d'.' -f1)
    gcc -o $prog_name $i |& grep -i 'warning' $i 2>/dev/null
    if [ $prog_name == progA ]; 
    then
        ans=10
    elif [ $prog_name == progB ]; 
    then
        ans=7
    else
        ans=5
    fi
    printf "%s\t\t%s\n" $i $ans
    ans=0

done
