sudo update
sudo apt-get install eog -y
sudo apt-get install bison++ bison-doc bison bisonc++-doc bisonc++ flex flexc++ -y


bison -d -v -b y parserpp.y 
flex lexer.l
g++ y.tab.c lex.yy.c -o ganzaki
rm lex.yy.c
rm y.tab.h
rm y.tab.c
rm y.output
