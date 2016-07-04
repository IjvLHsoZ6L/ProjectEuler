import Util.Prime

main :: IO ()
main = print answer

answer :: Int
answer = sum $ takeWhile (< 2000000) primes
