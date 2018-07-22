-- Example Hask Category

isEven :: Int -> Bool
isEven x = x `mod` 2 == 0

stringLength :: String -> Int
stringLength x = length x
                 
isStringLengthEven :: String -> Bool
isStringLengthEven = isEven . stringLength