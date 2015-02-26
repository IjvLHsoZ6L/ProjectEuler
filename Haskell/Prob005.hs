answer :: Integer
answer = foldl1 lcm [1 .. 20]

main :: IO ()
main = print answer
