for out in *.out
do
  echo $out
  (time -p ./$out)
  echo
done 2>&1 | tee result.txt
