------------------------ Merge Sort -----------------------------
merge :: Ord a => [a] -> [a] -> [a] -- merge two list into one list and assign to variable a
merge xs [] = xs -- merge a non-empty list with an empty list
merge [] ys = ys -- merge an empty list with a non-empty list
merge (x:xs) (y:ys) | x <= y = x:merge xs (y:ys) -- compare the first elements of the two list, then take the smaller one
                    | otherwise = y:merge (x:xs) ys -- continue to compare the value, then merge the rest of the list 


msort :: Ord a => [a] -> [a] -- Take a list as an input, and then split them into two sub-lists
msort [] = [] --if the list is empty, then return a empty list
msort [a] = [a] --if the list has only one element, the return the list
msort xs = merge (msort (firstHalf xs)) (msort(secondHalf xs)) -- merge two sub-lists (the left list and rigth list) by calling function merge recursively

firstHalf xs = let { n = length xs } in take (div n 2) xs -- Take the first half of the list
secondHalf xs = let { n = length xs } in drop (div n 2) xs -- Take the second half of the list

------------------------- Quick Sort ---------------------------- 
-- get a list as an input then sort it, and return to a
qsort :: Ord a => [a] -> [a]
-- Initialize an empty list
qsort []   = []
-- Make p as a pivot element and put all smaller elements than p on the left side and all greater elements on the right side
qsort (p:xs) = (qsort smaller) ++ [p] ++ (qsort bigger) 
    where
        -- Getting all the elements of xs that are smaller than p
        smaller = filter (< p) xs
        -- Getting all the elements of xs that are greater than p
        bigger = filter ( >= p) xs


main = do       -- main function
    putStrLn "original array: [4,65,2,-31,0,99,2,83,782,1]"     -- print original array
    putStr "merge sort: "       -- label merge sort
    print (msort [4,65,2,-31,0,99,2,83,782,1])     -- print merge sort result
    putStr "quick sort: "       -- label quick sort
    print (qsort [4,65,2,-31,0,99,2,83,782,1])