

rm ast
rm qicg
rm tcg
rm opt

ln -s ast.cpp ast
ln -s qicg.cpp qicg
ln -s tcg.cpp tcg
ln -s opt.cpp opt

sudo update
sudo apt install spim
pip3 install anytree
chmod +x ex.sh





