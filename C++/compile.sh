for cpp in *.cpp
do
  echo $cpp
  out=${cpp%.cpp}.out
  g++ -O2 -g -Wall -std=c++11 -o $out $cpp
done
