name=$1

bison -d -v -b y parserpp.y 
flex lexer.l
g++ y.tab.c lex.yy.c -o ganzaki
rm lex.yy.c
rm y.tab.h
rm y.tab.c
rm y.output

if [[ -n "$name" ]]; then
    ./ganzaki "Test/$name" > out.txt
    python3 lol.py
    # eog "OutputTree/tree.png" &
    rm out.txt
    rm ganzaki
    spim -file ass.s
    rm ass.s
    rm ast.txt
    rm imc.ta
    # sleep 10 
    # rm "OutputTree/tree.png"
else
    echo "argument error"
fi