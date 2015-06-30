main :: IO ()
main = print answer

answer :: Int
answer
    = (100 + 90) * length "onetwothreefourfivesixseveneightnine"
    + 10 * length "ten"
    + 10 * length "eleventwelvethirteenfourteenfifteensixteenseventeeneighteennineteen"
    + 100 * length "twentythirtyfortyfiftysixtyseventyeightyninety"
    + 900 * length "hundred"
    + 9 * 99 * length "and"
    + length "onethousand"
