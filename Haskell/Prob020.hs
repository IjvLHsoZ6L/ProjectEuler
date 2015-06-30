import Data.Char

main :: IO ()
main = print answer

answer :: Int
answer = sum . map digitToInt . show $ factorial 100

factorial :: Integer -> Integer
factorial n = product [1 .. n]
