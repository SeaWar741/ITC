# Simple implementation of Selection Sort and Quicksort in R.
# Quick sort algorithm:
# 1. Select a random value from the array.
# 2. Put all values less than the random in arrayLeft.
# 3. Put all values greater than the random in arrayRight.
# 4. If arrayLeft or arrayRight has more than 1 value, repeat the above steps on it.
# 5. The sorted result is arrayLeft, random, arrayRight.
#
# Selection sort algorithm:
# 1. Find the smallest value in the array and move it to a result array.
# 2. If there is more than 1 value remaining, repeat the above step on the rest.
# 3. The sorted result is smallest, rest.
#
# Kory Becker 9/4/2015
# http://primaryobjects.com/kory-becker

selectionSort <- function(arr) {
  # Find the smallest value in the list (ok sort of cheating, because we're using the highliy optimized min() function).
  smallest <- min(arr)
  rest <- arr[arr != smallest]
  
  if (length(rest) > 1) {
    rest <- selectionSort(arr[arr != smallest])
  }
  
  c(smallest, rest)
}

quickSort <- function(arr) {
  # Pick a number at random.
  mid <- sample(arr, 1)

  # Place-holders for left and right values.
  left <- c()
  right <- c()
  
  # Move all the smaller values to the left, bigger values to the right.
  lapply(arr[arr != mid], function(d) {
    if (d < mid) {
      left <<- c(left, d)
    }
    else {
      right <<- c(right, d)
    }
  })
  
  if (length(left) > 1) {
    left <- quickSort(left)
  }
  
  if (length(right) > 1) {
    right <- quickSort(right)
  }
  
  # Finally, return the sorted values.
  c(left, mid, right)
}
  