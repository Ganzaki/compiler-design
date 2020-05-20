name=$1



if [[ -n "$name" ]]; then
    ./ganzaki "Test/$name" > out.txt
    python3 lol.py
    # eog "OutputTree/tree.png" &
    rm out.txt
    rm ast.txt
    spim -file Output/ass.s
    # sleep 10 
    # rm "OutputTree/tree.png"
else
    echo "argument error, make sure mentioned file is in Test folder"
fi
