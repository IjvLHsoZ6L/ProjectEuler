import Util.Prime

main :: IO ()
main = print answer

answer :: Int
answer = primeListTo 200000 !! (10001 - 1)
