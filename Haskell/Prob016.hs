import Data.Char

main :: IO ()
main = print answer

answer :: Int
answer = sum . map digitToInt . show $ (2 :: Integer) ^ (1000 :: Integer)
