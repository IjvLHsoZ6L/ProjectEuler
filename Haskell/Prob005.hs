main :: IO ()
main = print answer

answer :: Integer
answer = foldr1 lcm [1 .. 20]
