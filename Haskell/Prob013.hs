main :: IO ()
main = putStrLn . answer =<< readFile "src/013.txt"

answer :: String -> String
answer = take 10 . show . sum . map (read :: String -> Integer) . lines
