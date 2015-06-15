import Util.Prime

main :: IO ()
main = print answer

answer :: Int
answer = sum $ primeListTo (2000000 - 1)
