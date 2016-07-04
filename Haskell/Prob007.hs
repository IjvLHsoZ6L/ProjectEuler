import Util.Prime

main :: IO ()
main = print answer

answer :: Int
answer = primes !! (10001 - 1)
