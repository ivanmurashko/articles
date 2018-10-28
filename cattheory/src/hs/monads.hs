f1 :: (Ord a, Floating a) => a -> Maybe a
f1 x = if x >= 0 then Just(sqrt x) else Nothing 

f2 :: Num a => a -> Maybe a
f2 x = Just (2*x)

f3 :: (Eq a, Fractional a) => a -> Maybe a
f3 x = if x /= 0 then Just(1/x) else Nothing

h :: (Ord b, Floating b) => b -> Maybe b
h x = (return x) >>= f1 >>= f2 >>= f3
