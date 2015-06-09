for cpp in *.cpp
do
  echo $cpp
  out=${cpp%.cpp}.out
  g++ -O2 -g -Wall -std=c++11 -o $out $cpp
  (time -p ./$out)
  echo
done 2>&1 | tee result.txt
